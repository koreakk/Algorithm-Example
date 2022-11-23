#include <vector>
using namespace std;

int LIS(const vector<int>& A) {
    vector<int> L = { A[0] };
    L.reserve(A.size());

    for (int x : A) {
        if (L.back() < x) {
            L.push_back(x);
        }
        else {
            *lower_bound(L.begin(), L.end(), x) = x;
        }
    }

    return static_cast<int>(L.size());
}