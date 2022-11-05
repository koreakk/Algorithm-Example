#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
    Time Complexity  : O(ElogV)
*/

using node_type  = pair<int, int>;  // weight, vertex
using graph_type = vector<vector<node_type>>;
using pq_type    = priority_queue<node_type, vector<node_type>, greater<node_type>>;

int Prim(const graph_type& graph) {
    vector<bool> visited(graph.size());

    pq_type pq;
    pq.emplace(0, 1);

    int answer = 0;
    while (!pq.empty()) {
        auto [weight, vertex] = pq.top();
        pq.pop();

        if (visited[vertex]) {
            continue;
        }

        visited[vertex] = true;
        answer         += weight;

        for (auto [w, v] : graph[vertex]) {
            if (!visited[v]) {
                pq.emplace(w, v);
            }
        }
    }

    return answer;
}
