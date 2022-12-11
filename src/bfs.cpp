#include "bfs.h"
#include <iostream>
#include <cmath>

vector<string> BFS::runBFS(map<string, vector<string>> route_maps, string starting_airport)
{
    out.clear();
    in.clear();
    path.clear();
    vector<string> airports_traversed;
    set<string> visited;
    
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
    
    return airports_traversed;
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
    path.push_back(current_airport);

    while (out[current_airport] != 0) {
        //finds the next airport to visit in the adjacency list and decrements out by 1
        string next_airport = routes[current_airport].at(out[current_airport]-1);
        out[current_airport]--;
        //recursive call on the next airport
        dfs(routes, next_airport);
    }
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