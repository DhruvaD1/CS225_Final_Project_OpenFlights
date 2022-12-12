#pragma once
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<double, string> Node;

class WeightedGraph {
    public:
        // Builds graph_ using the existing adjacency list and airport data
        WeightedGraph(map<string, vector<string>> route_map, map<string, vector<string>> data_map);

        // Returns a vector of the airports in order in the shortest path between airport1 and airport2
        vector<string> ShortestPath(string airport1, string airport2);

        // Helper function for ShortestPath
        void BuildPath(string airport, map<string, string> parent, vector<string>& path);

        // Adjacency list with distance between two airports
        // graph_[airport1][airport2] gives the distance in km between them
        map<string, map<string, double>> graph_;
};

double CalculateDist(map<string, vector<string>> data_map, string airport1, string airport2);