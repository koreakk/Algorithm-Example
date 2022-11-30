#include <utility>
#include <vector>
using namespace std;
using ll = long long;

ll pow(ll base, ll exp, ll mod) {
    ll ret = 1;
    for (base %= mod; exp; exp >>= 1) {
        if (exp & 1) {
            ret *= base;
            ret %= mod;
        }
        base *= base;
        base %= mod;
    }
    return ret;
}

ll factorial(ll n, ll mod) {
    ll ret = 1;
    for (int i = 1; i <= n; ++i) {
        ret *= i % mod;
        ret %= mod;
    }
    return ret;
}

/*
    nCr = n! / r!(n - r)! = n! * (n!(n - r)!) ^ (m - 2) MOD m
    (m == prime)

    Time Complexity  : O(n + logm)
*/
ll BinomialCoefficient(ll n, ll r, ll mod) {
    ll nF  = factorial(n, mod);
    ll rF  = factorial(r, mod);
    ll nrF = factorial(n - r, mod);

    return (nF * pow(rF * nrF, mod - 2ll, mod)) % mod;
}

pair<vector<ll>, vector<ll>> BinomialCoefficientCompute(ll n, ll mod) {
    vector<ll> fac(n + 1ll), inv(n + 1ll);

    fac[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        fac[i] = i * fac[i - 1];
        fac[i] %= mod;
    }

    inv[n] = pow(fac[n], mod - 2ll, mod);
    for (ll i = n - 1; i >= 0; --i) {
        inv[i] = (i + 1) * inv[i + 1];
        inv[i] %= mod;
    }

    return { fac, inv };
}

ll BinomialCoefficientComputed(const vector<ll>& fac, const vector<ll>& inv, ll n, ll r, ll mod) {
    return ((fac[n] * inv[r]) % mod) * inv[n - r] % mod;
}