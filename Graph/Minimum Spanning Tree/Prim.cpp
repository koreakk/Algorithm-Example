#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
    Time Complexity  : O(ElogV)
*/

using NODE  = pair<int, int>;        // weight, adjacent vertex
using GRAPH = vector<vector<NODE>>;  // adjacency list
using PQ    = priority_queue<NODE, vector<NODE>, greater<NODE>>;

int Prim(const GRAPH& graph) {
    vector<bool> visited(graph.size());

    PQ pq;
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
