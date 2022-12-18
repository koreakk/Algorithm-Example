#include <vector>
using namespace std;

template<class T>
vector<vector<T>> combinations(const vector<T>& base, int r) {
    const int N = int(base.size());

    vector<vector<T>> result;
    if (r > N) return result;

    auto Add = [&](const vector<int>& indices) {
        vector<T> ret(r);
        for (int i = 0; i < r; ++i) {
            ret[i] = base[indices[i]];
        }

        result.emplace_back(ret);
    };

    vector<int> indices(r);
    for (int i = 0; i < r; ++i) {
        indices[i] = i; 
    }

    Add(indices);

    if (r == N) return result;

    while (true) {
        int i = -1;
        for (int j = r - 1; j >= 0; --j) {
            if (indices[j] != j + N - r) {
                i = j;
                break;
            }
        }
        if (i == -1) { break; }

        ++indices[i];
        for (int j = i + 1; j < r; ++j) {
            indices[j] = indices[j - 1] + 1;
        }
        Add(indices);
    }

    return result;
}