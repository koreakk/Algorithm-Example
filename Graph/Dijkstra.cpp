#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

using node_type  = pair<int, int>;  // weight, vertex
using graph_type = vector<vector<node_type>>;
using pq_type    = priority_queue<node_type, vector<node_type>, greater<node_type>>;

vector<int> Dijkstra(const graph_type& graph, int source) {  
    vector<int> distance(graph.size(), -1);
    distance[source] = 0;

    pq_type pq;
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
