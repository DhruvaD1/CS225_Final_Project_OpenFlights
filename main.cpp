#include <iostream>
#include <vector>
#include "utils.h"
#include <map>
#include <algorithm>
#include "bfs.h"

using namespace std;


int main() {
    string data = file_to_string("data.txt");
    string routes = file_to_string("routes.txt");
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

    // for (auto const& it : route_maps) {
    //     cout << it.first;
    //     vector<string> tmp = it.second;
    //     for (unsigned i = 0; i < tmp.size(); i++) {
    //         cout << tmp.at(i) << " ";
    //     }
    //     cout << endl;
    // }

    map<string, vector<string>> data_maps;
    vector<string> lines;

    int dataSize = SplitString(data, '\n', lines);
    for (int i = 0; i < dataSize; i++) {
        vector<string> vec;
        SplitString(lines.at(i), ',', vec);

        vec.erase(vec.begin());
        std::string airport = vec.at(0);
        vec.erase(vec.begin());
        data_maps[airport] = vec;
        // std::cout << "-----------------" << std::endl;
        // for (auto s : vec) {
        //     std::cout << s << std::endl;
        // }

        // std::cout << "-----------------" << std::endl;
    }

    // ONCE AN ADJACENCY LIST IS MADE, REPLACE "route_maps" parameter with its name
    // vector<string> bfs_traversal = BFS(route_maps, "SFO");
    // for (string e : bfs_traversal) {
    //     cout << e << endl;
    // }
}   