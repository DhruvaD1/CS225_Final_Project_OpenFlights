#include "bfs.h"

vector<string> BFS(map<string, vector<string>> route_maps, string starting_airport)
{
    vector<string> airports_traversed;
    set<string> visited;
    
    queue<string> q;
    q.push(starting_airport);

    while (!q.empty()) {
        string curr_airport = q.front();
        visited.insert(curr_airport);
        airports_traversed.push_back(curr_airport);
        q.pop();

        for (string neighbor : route_maps[curr_airport]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    } 
    
    return airports_traversed;
}