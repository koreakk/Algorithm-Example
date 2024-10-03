#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull mod_mul(ull a, ull b, ull mod) {
    return (__int128)a * b % mod;
}

ull mod_pow(ull base, ull exp, ull mod) {
    ull ret = 1;
    while (exp) {
        if (exp & 1) {
            ret = mod_mul(ret, base, mod);
        }
        base = mod_mul(base, base, mod);
        exp >>= 1;
    }
    return ret;
}

bool miller_rabin_primality_test(ull n, ull a) {
    ull d = n - 1;
    ull r = 0;

    while (!(d & 1)) {
        d >>= 1;
        ++r;
    }

    ull x = mod_pow(a, d, n);
    if (x == 1 || x == n-1) {
        return true;
    }

    while (--r) {
        x = mod_mul(x, x, n);
        if (x == 1) {
            return false;
        }
        if (x == n-1) {
            return true;
        }
    }

    return false;
}

bool is_prime(ull n) {
    if (n < 10) {
        for (ull p : {2, 3, 5, 7}) {
            if (n == p) {
                return true;
            }
        }
        return false;
    }

    if (!(n & 1)) {
        return false;
    }

    for (ull a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) {
            return true;
        }
        if (!miller_rabin_primality_test(n, a)) {
            return false;
        }
    }

    return true;
}

/* O(N^0.25) */
ull pollard_rho(ull n) {
    if (n == 1) {
        return 1;
    }

    if (!(n&1)) {
        return 2;
    }

    if (is_prime(n)) {
        return n;
    }

    ull x, y, c, d;
    auto f = [&c, &n](ull x) { return (mod_mul(x, x, n) + c) % n; };

    x = y = rand() % (n - 2) + 2;
    c = rand() % 20 + 1;
    d = 1;

    while (d == 1) {
        x = f(x);
        y = f(f(y));
        d = gcd(max(x, y) - min(x, y), n);
    }

    return pollard_rho(d);
}

vector<ull> factorize(ull n) {
    vector<ull> ret;

    while (n != 1) {
        ull prime_factor = pollard_rho(n);
        while (n % prime_factor == 0) {
            ret.push_back(prime_factor);
            n /= prime_factor;
        }
    }

    sort(begin(ret), end(ret));
    return ret;
}