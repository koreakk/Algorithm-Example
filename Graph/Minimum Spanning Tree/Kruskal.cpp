#include <algorithm>
#include <vector>
using namespace std;

/*
    Time Complexity  : O(ElogV)
*/

struct Node {
    int v, u, w;
};

int FindParent(vector<int>& parents, int v) {
    if (parents[v] == v) return v;
    return parents[v] = FindParent(parents, parents[v]);
}

void UnionParent(vector<int>& parents, int v, int u) {
    v = FindParent(parents, v);
    u = FindParent(parents, u);
    if (v < u) parents[u] = v;
    else parents[v] = u;
}

int Kruskal(int n, vector<Node>& edges) {
    vector<int> parents(n + 1);
    for (int i = 0; i <= n; i++)
        parents[i] = i;

    sort(
        edges.begin(),
        edges.end(),
        [](const Node& l, const Node& r) {
            return l.w < r.w;
        }
    );

    int answer = 0;
    for (const auto& [v, u, w] : edges) {
        if (FindParent(parents, v) != FindParent(parents, u)) {
            UnionParent(parents, v, u);
            answer += w;
        }
    }

    return answer;
}