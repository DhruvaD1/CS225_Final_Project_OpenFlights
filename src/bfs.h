#pragma once

#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

class BFS {
    public: 
        vector<string> runBFS(map<string, vector<string>> route_maps, string starting_airport);
};