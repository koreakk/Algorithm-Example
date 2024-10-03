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