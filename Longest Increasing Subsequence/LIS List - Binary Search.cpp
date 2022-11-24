#include <vector>
#include <algorithm>
using namespace std;

vector<int> LIS(const vector<int>& A) {
    int N = (int)A.size();

    vector<int> info(N);

    vector<int> L = { A[0] };
    L.reserve(A.size());

    for (int i = 0; i < N; ++i) {
        if (L.back() < A[i]) {
            L.push_back(A[i]);
            info[i] = (int)L.size();
        }
        else {
            auto it = lower_bound(L.begin(), L.end(), A[i]);
            *it     = A[i];
            info[i] = (int)(it - L.begin() + 1);
        }
    }

    int retSize = (int)L.size();
    vector<int> ret(retSize);

    int i = retSize, j = N - 1;
    for (; j >= 0; --j) {
        if (info[j] == i) {
            ret[--i] = A[j];
        }
    }

    return ret;
}