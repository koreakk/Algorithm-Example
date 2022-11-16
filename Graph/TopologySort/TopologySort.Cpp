#include <queue>
#include <vector>
using namespace std;

/*
    Time Complexity  : O(V+E)
*/

vector<int> TopologySort(int N, const vector<pair<int, int>>& edges) { 
    vector<int>         indegree(N + 1);
    vector<vector<int>> graph(N + 1);

    for (const auto& [v, u] : edges) {
        graph[v].push_back(u);
        ++indegree[u];
    }
    
    vector<int> result;
    result.reserve(N);

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        result.push_back(v);
        q.pop();

        for (int i : graph[v]) {
            if (--indegree[i] == 0) {
                q.push(i);
            }
        }
    }

    return result;
}