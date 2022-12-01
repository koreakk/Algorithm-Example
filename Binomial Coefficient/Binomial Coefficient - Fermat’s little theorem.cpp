#include <utility>
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
T factorial(T n, T mod) {
    T ret = 1;
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
template<class T>
T BinomialCoefficient(T n, T r, T mod) {
    T nF  = factorial(n, mod);
    T rF  = factorial(r, mod);
    T nrF = factorial(n - r, mod);

    return (nF * pow(rF * nrF, mod - 2T, mod)) % mod;
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