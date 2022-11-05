#include <vector>
using namespace std;

template<class T>
vector<vector<T>> combinations(const vector<T>& base, int r) {
    const int n = (int)base.size();

    vector<vector<T>> result;
    if (r > n) return result;

    auto Add = [&](const vector<int>& indices) {
        vector<T> res;
        for (int i : indices) {
            res.emplace_back(base[i]);
        }
        result.emplace_back(res);
    };

    vector<int> indices(r);
    for (int i = 0; i < r; ++i) { indices[i] = i; }

    Add(indices);
    if (r == n) return result;

    while (true) {
        int i = -1;
        for (int j = r - 1; j >= 0; --j) {
            if (indices[j] != j + n - r) {
                i = j;
                break;
            }
        }
        if (i == -1) break;

        ++indices[i];
        for (int j = i + 1; j < r; ++j) {
            indices[j] = indices[j - 1] + 1;
        }
        Add(indices);
    }

    return result;
}