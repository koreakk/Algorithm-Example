#include <vector>
using namespace std;

/*
    nCr % m = ((n-1)C(r-1) % m + (n-1)Cr % m) % m
    Bottom-Up Dynamic Programming

    Time Complexity  : O(n^2)
    Space Complexity : O(n^2)
*/
template<class T>
T BinomialCoefficient(T n, T r, T mod) {
    vector<vector<T>> dp(n + 1, vector<T>(n + 1));

    for (T i = 0; i <= n; ++i) {
        dp[i][0] = 1;

        for (T j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }

    return dp[n][r];
}

template<class T>
vector<vector<T>> BinomialCoefficientCompute(T n, T mod) {
    vector<vector<T>> dp(n + 1, vector<T>(n + 1));

    for (T i = 0; i <= n; ++i) {
        dp[i][0] = 1;

        for (T j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }

    return dp;
}

template<class T>
T BinomialCoefficientComputed(T n, T r, const vector<vector<T>>& dp) {
    return dp[n][r];
}