#include <tuple>
using namespace std;

template<class T>
tuple<T, T, T> extended_gcd(T a, T b) {
    auto swap = [](T& a, T& b, T c, T d) {
        a = c, b = d;
    };

    T s = 0, old_s = 1;
    T t = 1, old_t = 0;
    T r = b, old_r = a;

    while (r) {
        T quotient = old_r / r;
        swap(old_r, r, r, old_r - quotient * r);
        swap(old_s, s, s, old_s - quotient * s);
        swap(old_t, t, t, old_t - quotient * t);
    }
    
    return { old_r, old_s, old_t };
}