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
        vector<string> findEulerPath(map<string, vector<string>> routes, string start_airport);
        int hasEulerPath(vector<string> airports, string start_airport);
        void dfs(map<string, vector<string>> routes, string current_airport);
        map<string, vector<string>> parseData(string data);
        int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
        std::string file_to_string(const std::string& filename);
        map<string, vector<string>> parseRoutes(string routeFile);
    private:
        //the number of airports that directly fly to a specific airport
        map<string, int> in;
        //the number of airports you can directly fly to from each airport
        map<string, int> out;
        vector<string> path;
};
