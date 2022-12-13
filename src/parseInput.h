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

class ParseInput {
    public: 
        map<string, vector<string>> parseRoutes(string routeFile);
        map<string, vector<string>> parseData(string data);
        int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
        std::string file_to_string(const std::string& filename);
};