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

/*
    nCr = n0Cr0 * n1Cr1 * ... * niCri MOD m
    (m == prime)

    Time Complexity  : O(m)
*/
ll BinomialCoefficient(ll n, ll r, ll mod) {
    const auto[fac, inv] = BinomialCoefficientCompute(mod - 1ll, mod);

    ll ret = 1;
    for (; n && r; n /= mod, r /= mod) {
        ll ni = n % mod, ri = r % mod;
        if (ri > ni) { return 0; }

        ret *= BinomialCoefficientComputed(fac, inv, ni, ri, mod);
        ret %= mod;
    }

    return ret;
}