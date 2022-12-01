#include <vector>
using namespace std;

template<class T>
vector<T> LIS(const vector<T>& A) {
    size_t N = A.size();
    vector<T> dp(N, 1);

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    size_t i = 0;
    for (size_t j = 0; j < N; ++j) {
        if (i < dp[j]) {
            i = dp[j];
        }
    }

    vector<T> ret(i);

    for (size_t j = N - 1; j >= 0; --j) {
        if (dp[j] == i) {
            ret[--i] = A[j];
        }
    }
    
    return ret;
}