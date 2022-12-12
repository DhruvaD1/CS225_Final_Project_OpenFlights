#include <iostream>
#include <vector>
#include "utils.h"
#include <cmath>
#include <map>
#include <algorithm>
#include "bfs.h"
#include "parseInput.h"
#include <string>
#include <map>
#include <utility>
#include <set>
#include <cassert>
#include <fstream>
#include <signal.h>
#include <sstream>

#define pi 3.14159265358979323846

using namespace std;

std::string BFS::file_to_string(const std::string& filename){
  std::ifstream text(filename);

  std::stringstream strStream;
  if (text.is_open()) {
    strStream << text.rdbuf();
  }
  return strStream.str();
}

int BFS::SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
    std::string str = str1;
    std::string::size_type pos;
    while((pos=str.find(sep)) != std::string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);  
    }
    fields.push_back(str);
    return fields.size();
}

map<string, vector<string>> BFS::parseData(string data) {
    map<string, vector<string>> data_maps;
    vector<string> lines;

    int dataSize = SplitString(data, '\n', lines);
    for (int i = 0; i < dataSize; i++) {
        vector<string> vec;
        SplitString(lines.at(i), ',', vec);

        vec.erase(vec.begin());
        
        if(vec.at(3).length()==5){

                std::string airport = vec.at(3).substr(1,3);
                vec.erase(vec.begin());
        data_maps[airport] = {vec.at(4),vec.at(5)};
        }
    }
 
    return data_maps;
}


vector<string> BFS::runBFS(map<string, vector<string>> route_maps, string starting_airport)
{
    map<string, int> in;
        //the number of airports you can directly fly to from each airport
    map<string, int> out;
    vector<string> path;
    vector<string> airports_traversed;
    set<string> visited;
    vector<pair<double,double>> pos;
    string data = file_to_string("data.txt");
    map<string,vector<string>> maper= parseData(data);
    //parsing the data and removing values that are not in both hashmaps
for(auto i = route_maps.begin(); i!=route_maps.end();++i){
    if(maper.find(i->first)==maper.end()){
        i=route_maps.erase(i);
    }
}

    queue<string> q;
    q.push(starting_airport);

    while (!q.empty()) {

        string curr_airport = q.front();
        //finds the number of airports that you can fly to from curr_airports
        out[curr_airport] = route_maps[curr_airport].size();
        visited.insert(curr_airport);
        airports_traversed.push_back(curr_airport);
        q.pop();

        for (string neighbor : route_maps[curr_airport]) {
            //find the number of airports that can fly to 
            in[neighbor]+=1;
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    } 
        //calcualting the distance between the starting airport and last airport
        string two =airports_traversed[airports_traversed.size()-2];
        string one =airports_traversed[0];
        vector<string> oner = maper[one];
        vector<string> twoer = maper[two];


        double sub = stod(oner.at(1))-stod(twoer.at(1));
        double dist;
        dist = sin(stod(oner.at(0))/180*pi)*sin(stod(twoer.at(0))/180*pi)+cos(stod(oner.at(0))/180*pi)*cos(stod(twoer.at(0))/180*pi)*cos(sub/180*pi);
        dist=acos(dist);
        dist=dist*6371;
        cout<<"The total distance in km between the two airports is : "<< dist<<endl;
        return airports_traversed;
}


map<string, vector<string>> BFS::parseRoutes(string routeFile) {
    string routes = file_to_string(routeFile);
    vector<string> line;
    int size = SplitString(routes, '\n', line);
    map<string, vector<string>> route_maps;
    for (int i = 0; i < size; i++) {
        vector<string> vec;
        SplitString(line.at(i), ',', vec);
        vector<string> tmp = route_maps[vec.at(2)];
        if (std::find(tmp.begin(), tmp.end(), vec.at(4)) == tmp.end()) {
            route_maps[vec.at(2)].push_back(vec.at(4));
        }
    }

    return route_maps;
}

/**
    @param routes - is a vector containing all the aiports in the dataset
           start_airport - is the starting at which we determine whether or not a euler's path exists at that location
    @return
    path - a vector of strings containing the euler's path if there is one. If there isn't, return an empty vector
*/
vector<string> BFS::findEulerPath(map<string, vector<string>> routes, string start_airport) {
    //runs a bfs to find the number of vertices going in and going out of each node
    vector<string> bfs = runBFS(routes, start_airport);
    if (hasEulerPath(bfs, start_airport) == 0) {
        return vector<string>();
    }
    dfs(routes, start_airport);
    return path;
} 

/** 
    @param routes - map with all airports and their respective adjacency list
           current_airport - the current airport we are at
*/
void BFS::dfs(map<string, vector<string>> routes, string current_airport) {
    //adds the current_airport to the euler's path

    while (out[current_airport] != 0) {
        //finds the next airport to visit in the adjacency list and decrements out by 1
        string next_airport = routes[current_airport].at(out[current_airport]-1);
        out[current_airport]--;
        //recursive call on the next airport
        dfs(routes, next_airport);
    }
    
    path.insert(path.begin(), current_airport);
}
/**
    @param starting_airport - determine if a bfs exists at the starting airport
           airports - vector of all airports
    @return int - 0 if there is not an euler's path in the graph or if there is no euler's path starting
    at starting_airport. 1 otherwise
*/
int BFS::hasEulerPath(vector<string> airports, string start_airport) {
    //start node is any node with an extra out going edge, i.e. out = in+1
    int start_nodes = 0;
    //end node is any node with an extra incoming edge, i.e in = out+1
    int end_nodes = 0;

    for (unsigned i = 0; i < airports.size(); i++) {
        string airport = airports.at(i);
        /* if any node has more than one edge going in than it has edges going out or vice versa
            than a euler's path does not exist */
        if (std::abs(out[airport]-in[airport]) > 1) {
            return false;
        }
        //iterates the number of start and end nodes in the graph
        if (out[airport] == in[airport] + 1)
            start_nodes++;
        else if (out[airport] + 1 == in[airport])
            end_nodes++;
    }
    /* An euler's circuit will exist if there are no start or end nodes detected. Therefore, the starting
        airport will always have an euler's path. However, if there are start and end nodes, then 
        the starting_airport will have one more edge going out than it will going in */
    if ((start_nodes == 0 && end_nodes == 0)) {
        return true;
    } else if (out[start_airport] != in[start_airport] + 1) {
        return false;
    } 
    //The last case of an euler's path existing is if there are exactly 1 start node and 1 end node
    return (start_nodes == 1 && end_nodes == 1);
}
