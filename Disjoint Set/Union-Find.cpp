#include <vector>
using namespace std;

void Init(vector<int>& parents) {
    int N = (int)parents.size();
    for (int i = 0; i < N; ++i)
        parents[i] = i;
}

int Find(vector<int>& parents, int v) {
    if (parents[v] == v) return v;
    return parents[v] = Find(parents, parents[v]);
}

void Union(vector<int>& parents, int v, int u) {
    v = Find(parents, v);
    u = Find(parents, u);
    if (v < u) parents[u] = v;
    else parents[v] = u;
}