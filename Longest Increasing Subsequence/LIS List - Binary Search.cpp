#include <vector>
#include <algorithm>
using namespace std;

template<class T>
vector<T> LIS(const vector<T>& A) {
    size_t N = A.size();

    vector<T> info(N);

    vector<T> L = { A[0] };
    L.reserve(A.size());

    for (size_t i = 0; i < N; ++i) {
        if (L.back() < A[i]) {
            L.push_back(A[i]);
            info[i] = (T)L.size();
        }
        else {
            auto it = lower_bound(L.begin(), L.end(), A[i]);
            *it     = A[i];
            info[i] = (T)(it - L.begin() + 1);
        }
    }

    size_t retSize = L.size();
    vector<T> ret(retSize);

    size_t i = retSize, j = N - 1;
    for (; j >= 0; --j) {
        if (info[j] == i) {
            ret[--i] = A[j];
        }
    }

    return ret;
}