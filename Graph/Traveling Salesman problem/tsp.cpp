#include <utility>
using namespace std;

constexpr int INF = 10000000;
constexpr int N   = 16;

int W[N][N], dp[N][1 << N];

int tsp(int i, int visited) {
    if (dp[i][visited]) {
        return dp[i][visited];
    }

    if (visited == (1 << N) - 1) {
        int ret = W[i][0];
        dp[i][visited] = ret ? ret : INF;
        return dp[i][visited];
    }

    int ret = INF;
    for (int j = 0; j < N; ++j) {
        if (visited & (1 << j) || !W[i][j]) { continue; }

        ret = min(ret, W[i][j] + tsp(j, visited | (1 << j)));
    }
    
    dp[i][visited] = ret;
    return dp[i][visited];
}