#include <vector>
using namespace std;

template<class T>
T LIS(const vector<T>& A) {
    vector<T> L = { A[0] };
    L.reserve(A.size());

    for (T x : A) {
        if (L.back() < x) {
            L.push_back(x);
        }
        else {
            *lower_bound(L.begin(), L.end(), x) = x;
        }
    }

    return static_cast<T>(L.size());
}