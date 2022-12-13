#include <iostream>
#include <vector>
#include "utils.h"
#include "utils.cpp"
#include <map>
#include <algorithm>
#include "bfs.h"
#include "bfs.cpp"
#include "parseInput.h"
#include "parseInput.cpp"
#include <fstream>
#include <map>
#include "WeightedGraph.cpp"
#include "WeightedGraph.h"
#include <cstring>
using namespace std;


int main() {
    //opens up input.txt to get user input
    ifstream input("../input.txt");
    //output file to write results to
    ofstream output;
    output.open("../output.txt");
    output << "Here are the results based off of your input data" << endl;
    //just a little bit of formating
    output << "----------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n" << endl;
    string word;
    //stores the airports for each algorithm
    string bfs_airport;
    string euler_airport;
    string djikstra_start_airport;
    string djikstra_end_airport;

    int count = 0;
    while (getline(input, word)) {
        if (count == 14) {
            bfs_airport = (Trim(word));
        } else if (count == 18) {
            euler_airport = (Trim(word));
        } else if (count == 22) {
            djikstra_start_airport = (Trim(word));
        } else if (count == 25) {
            djikstra_end_airport = (Trim(word));
        }
        count++;
    }
    //creates an adjancency list for all the airports
    map<string, vector<string>> routes = parseRoutes("../src/routes.txt");
    //data for each airport store here
    string data = file_to_string("../src/data.txt");
    map<string, vector<string>> airport_data = parseData(data);

    BFS b;
    //run a bfs starting at the inputed airport (bfs_airport)
    if (routes[bfs_airport].size() != 0) { //checks that bfs_airport is a valid airport
        vector<string> traversed_bfs = b.runBFS(routes, bfs_airport);
        //prints out some information for the user to understand what is bring printed
        output << "After running a BFS, we have found that, starting at " << bfs_airport 
               << " you can travel to all of the following airports either directly or through connections. \n" << endl;

        for (unsigned i = 0; i < traversed_bfs.size(); i++) { //prints the traversed bfs
            if (i == traversed_bfs.size() -1) {
                output << traversed_bfs.at(i) << endl;
            } else if (i%30 == 0) {
                output << traversed_bfs.at(i) << ", " << endl;
            } else {
                output << traversed_bfs.at(i) << ", ";
            }
        }
    } else { //not a valid airport inputted
        output << bfs_airport << " is not a valid airpot."  << endl;
    } 
    output << "\n\n\n" << endl;
    //Runs an Euler's path  on the inputted airport (euler_airport) if there is one
    if (routes[euler_airport].size() != 0) { //checks that euler_airport is a valid airport
        vector<string> euler_path = b.findEulerPath(routes, euler_airport);
        //some info for user
        output << "After running " << euler_airport << " through our algorithm we, we have determined that.... \n" << endl;

        if (euler_path.size() == 0) {
            output << "an euler path does not exist for this airport" << endl;
        } else {
            output << "an euler path does exist for this airport, and is printed below\n" << endl;
            for (unsigned i = 0; i < euler_path.size(); i++) { //prints out the euler's path
                if (i == euler_path.size() -1) {
                    output << euler_path.at(i) << endl;
                } else if (i%30 == 0) {
                    output << euler_path.at(i) << " -> " << endl;
                } else {
                    output << euler_path.at(i) << " -> ";
                }
            }
        }
    } else {
        output << euler_airport << " is not a valid airpot."  << endl;
    }
    output << "\n\n\n" << endl;
    //Runs a Djikstra's shortest path, to find the shortest distance between two airports
    if (routes[djikstra_start_airport].size() != 0 && routes[djikstra_end_airport].size() != 0) {
        WeightedGraph wg(routes,airport_data);
        vector<string> shortest_path = wg.ShortestPath(djikstra_start_airport, djikstra_end_airport);

        output << "After running Djikstra's shortest path on " << djikstra_start_airport << " and " 
            << djikstra_end_airport << " we have determined that the shortest path from " << djikstra_start_airport 
            << " to " << djikstra_end_airport << " is... \n" << endl;
        
        for (unsigned i = 0; i < shortest_path.size(); i++) { //prints out the shortest path
            if (i == shortest_path.size() -1) {
                output << shortest_path.at(i) << endl;
            } else {
                output << shortest_path.at(i) << "-> ";
            }
        }
        
    } else { //not a valid airport
        if (routes[djikstra_end_airport].size() != 0) {
            output << djikstra_end_airport << " is not a valid airpot."  << endl;
        }
        if (routes[djikstra_start_airport].size() != 0) {
            output << djikstra_start_airport << " is not a valid airpot."  << endl;
        }
    }
}   
