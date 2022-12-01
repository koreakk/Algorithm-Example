#include <vector>
using namespace std;

template<class T>
T pow(T base, T exp, T mod) {
    T ret = 1;
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

template<class T>
pair<vector<T>, vector<T>> BinomialCoefficientCompute(T n, T mod) {
    vector<T> fac(n + 1T), inv(n + 1T);

    fac[0] = 1;
    for (T i = 1; i <= n; ++i) {
        fac[i] = i * fac[i - 1];
        fac[i] %= mod;
    }

    inv[n] = pow(fac[n], mod - 2T, mod);
    for (T i = n - 1; i >= 0; --i) {
        inv[i] = (i + 1) * inv[i + 1];
        inv[i] %= mod;
    }

    return { fac, inv };
}

template<class T>
T BinomialCoefficientComputed(const vector<T>& fac, const vector<T>& inv, T n, T r, T mod) {
    return ((fac[n] * inv[r]) % mod) * inv[n - r] % mod;
}

/*
    nCr = n0Cr0 * n1Cr1 * ... * niCri MOD m
    (m == prime)

    Time Complexity  : O(m)
*/
template<class T>
T BinomialCoefficient(T n, T r, T mod) {
    const auto[fac, inv] = BinomialCoefficientCompute(mod - 1T, mod);

    T ret = 1;
    for (; n && r; n /= mod, r /= mod) {
        T ni = n % mod, ri = r % mod;
        if (ri > ni) { return 0; }

        ret *= BinomialCoefficientComputed(fac, inv, ni, ri, mod);
        ret %= mod;
    }

    return ret;
}