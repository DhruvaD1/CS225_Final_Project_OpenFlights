#include "parseInput.h"
#include "utils.h"
#include <sstream>
#include <fenv.h>
#include <signal.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Finds all the airports each airport flies to 
map<string, vector<string>> parseRoutes(string routeFile) {
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

// Parses the data for each airport based on its properties
map<string, vector<string>> parseData(string data) {
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