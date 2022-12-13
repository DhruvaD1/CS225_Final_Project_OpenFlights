#include "WeightedGraph.h" 

WeightedGraph::WeightedGraph(map<string, vector<string>> route_map, map<string, vector<string>> data_map) {
    for (auto entry : route_map) {
        string start_airport = entry.first;
        if (data_map.find(start_airport) == data_map.end()) {
            continue;
        }
        map<string, double> neighbors;

        for (string n : entry.second) {
            if (data_map.find(n) == data_map.end()) {
                continue;
            }
            neighbors[n] = CalculateDist(data_map, start_airport, n);
        }

        graph_[start_airport] = neighbors;
    }
}

vector<string> WeightedGraph::ShortestPath(string airport1, string airport2) {
    // Dijkstra's Algorithm using a priority queue
    // Node is a pair<double, string> which holds (weight, airport_name)

    if (airport1 == airport2) {
        vector<string> path {airport1};
        return path;
    }

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    map<string, double> dist;
    map<string, string> parent;

    pq.push(make_pair(0.0, airport1));
    dist[airport1] = 0.0;
    parent[airport1] = "none";

    while (!pq.empty()) {
        string current_airport = pq.top().second;
        pq.pop();

        for (auto n : graph_[current_airport]) {
            string neighbor = n.first;
            double weight = n.second;

            if (dist.find(neighbor) == dist.end()) {
                dist[neighbor] = 9999999.99;
            }

            if (dist[neighbor] > dist[current_airport] + weight) {
                dist[neighbor] = dist[current_airport] + weight;
                parent[neighbor] = current_airport;
                pq.push(make_pair(dist[neighbor], neighbor));
            }
        }
    }

    vector<string> path;
    BuildPath(airport2, parent, path);
    return path;
}

void WeightedGraph::BuildPath(string airport, map<string, string> parent, vector<string>& path) {
    if (airport == "none") {
        return;
    }
    BuildPath(parent[airport], parent, path);
    path.push_back(airport);
}

double CalculateDist(map<string, vector<string>> data_map, string airport1, string airport2) {
    double airport1_lat = stod(data_map[airport1][0]) * (3.15149/180);
    double airport1_lon = stod(data_map[airport1][1]) * (3.15149/180);

    double airport2_lat = stod(data_map[airport2][0]) * (3.15149/180);
    double airport2_lon = stod(data_map[airport2][1]) * (3.15149/180);

    double dlat = airport2_lat - airport1_lat;
    double dlon = airport2_lon - airport1_lon;

    double ans = pow(sin(dlat/2), 2) + cos(airport1_lat) * cos(airport2_lat) * pow(sin(dlon/2), 2);
    ans = 2 * asin(sqrt(ans));
    ans = ans * 6371;

    return ans;
}
