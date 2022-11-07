#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

using NODE  = pair<int, int>;        // weight, adjacent vertex
using GRAPH = vector<vector<NODE>>;  // adjacency list
using PQ    = priority_queue<NODE, vector<NODE>, greater<NODE>>;

vector<int> Dijkstra(const GRAPH& graph, int source) {  
    vector<int> distance(graph.size(), -1);
    distance[source] = 0;

    PQ pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [weight, vertex] = pq.top();
        pq.pop();

        if (distance[vertex] == -1 || weight <= distance[vertex]) {
            for (auto [w, v] : graph[vertex]) {
                int currDist = w + weight;

                if (distance[v] == -1 || currDist < distance[v]) {
                    distance[v] = currDist;
                    pq.emplace(currDist, v);
                }
            }
        }

    }

    return distance;
}
