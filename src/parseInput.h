#pragma once
#include <utility>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <fstream>

using namespace std;

class parseInput {
    public: 
        map<string, vector<string>> parseRoutes(string routeFile);
        map<string, vector<string>> parseData(string data);
        // string file_to_string(const string & filename);

        // int SplitString(const string & str1, char sep, vector<string> &fields);
};