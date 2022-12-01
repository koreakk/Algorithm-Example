template<class T>
T inverse(T a, T n) {
    auto swap = [](T& a, T& b, T c, T d) {
        a = c, b = d;
    };

    T t = 0, nt = 1;
    T r = n, nr = a;

    while (nr) {
        T quotient = r / nr;
        swap(t, nt, nt, t - quotient * nt);
        swap(r, nr, nr, r - quotient * nr);
    }

    if (r > 1) { return -1; }
    return t < 0 ? t + n : t;
}