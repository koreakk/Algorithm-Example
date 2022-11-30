#include <vector>
using namespace std;
using ll = long long;

/*
    nCr % m = ((n-1)C(r-1) % m + (n-1)Cr % m) % m
    Bottom-Up Dynamic Programming

    Time Complexity  : O(n^2)
    Space Complexity : O(n^2)
*/
ll BinomialCoefficient(ll n, ll r, ll mod) {
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));

    for (ll i = 0; i <= n; ++i) {
        dp[i][0] = 1;

        for (ll j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }

    return dp[n][r];
}

vector<vector<ll>> BinomialCoefficientCompute(ll n, ll mod) {
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));

    for (ll i = 0; i <= n; ++i) {
        dp[i][0] = 1;

        for (ll j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }

    return dp;
}

ll BinomialCoefficientComputed(ll n, ll r, const vector<vector<ll>>& dp) {
    return dp[n][r];
}