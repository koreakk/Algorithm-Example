#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull powmod(ull n, ull r, ull m) {
    ull ret = 1;
    while (r) {
        if (r & 1) {
            ret = (ret * n) % m;
        }
        n = (n * n) % m;
        r >>= 1;
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
    
    ull x = powmod(a, d, n);
    if (x == 1 || x == n-1) {
        return true;
    }

    while (--r) {
        x = powmod(x, 2, n);
        if (x == 1) {
            return false;
        }
        if (x == n - 1) {
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

    for (ull a : {2, 7, 61}) {  // n < 2^64  {2, 3, 5, 7, 11, 13, 17, 23, 29, 31}
        if (n == a) { 
            return true; 
        }
        if (!miller_rabin_primality_test(n, a)) {
            return false;
        }
    }
    return true;
}
