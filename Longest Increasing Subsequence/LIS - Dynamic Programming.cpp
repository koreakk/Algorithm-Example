#include <vector>
using namespace std;

template<class T>
T LIS(const vector<T>& A) {
    size_t N = A.size();
    vector<T> dp(N, 1);

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    T ret = 0;
    for (size_t i = 0; i < N; ++i) {
        if (ret < dp[i]) {
            ret = dp[i];
        }
    }

    return ret;
}