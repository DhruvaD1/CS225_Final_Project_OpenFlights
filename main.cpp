#include <iostream>
#include <vector>
#include "utils.h"
#include <map>
#include <algorithm>
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
    for (auto const& it : route_maps) {
        cout << it.first << endl;
        vector<string> tmp = it.second;
        for (unsigned i = 0; i < tmp.size(); i++) {
            cout << tmp.at(i) << " ";
        }
    }
}