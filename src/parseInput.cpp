    
#include "parseInput.h"
#include "utils.h"
#include <sstream>
#include <fenv.h>
#include <signal.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

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
    // for (auto const& it : route_maps) {
    //     cout << it.first;
    //     vector<string> tmp = it.second;
    //     for (unsigned i = 0; i < tmp.size(); i++) {
    //         cout << tmp.at(i) << " ";
    //     }
    //     cout << endl;
    // }
map<string, vector<string>> parseData(string data) {
    map<string, vector<string>> data_maps;
    vector<string> lines;

    SplitString(data, '\n', lines);

    for (string l : lines) {
        vector<string> properties;
        SplitString(l, ',', properties);

        string airport = properties[4];
        if (airport == "\\N") {
            continue;
        }

        // airports are surrounded by quotes, for example: "SFO"
        // we want to remove the quotes so we can use just SFO as the map key
        airport = airport.substr(1, 3);

        data_maps[airport] = properties;
    }

    // for (int i = 0; i < dataSize; i++) {
    //     vector<string> vec;
    //     SplitString(lines.at(i), ',', vec);

    //     vec.erase(vec.begin());
    //     std::string airport = vec.at(0);
    //     vec.erase(vec.begin());
    //     data_maps[airport] = vec;
    // }

    return data_maps;
}

// string file_to_string(const string& filename){
//   std::ifstream text(filename);

//   std::stringstream strStream;
//   if (text.is_open()) {
//     strStream << text.rdbuf();
//   }
//   return strStream.str();
// }

// int SplitString(const string & str1, char sep, vector<string> &fields) {
//     std::string str = str1;
//     std::string::size_type pos;
//     while((pos=str.find(sep)) != std::string::npos) {
//         fields.push_back(str.substr(0,pos));
//         str.erase(0,pos+1);  
//     }
//     fields.push_back(str);
//     return fields.size();
// }