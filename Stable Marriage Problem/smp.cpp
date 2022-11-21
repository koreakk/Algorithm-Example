#include <vector>
#include <queue>
using namespace std;

vector<int> smp(const vector<vector<int>>& mPrefer, const vector<vector<int>>& wPrefer, int N) {
    vector<queue<int>> mInfo(N);
    for (int i = 0; i < N; ++i) {
        for (int w : mPrefer[i]) {
            mInfo[i].push(w);
        }
    }

    vector<int>  wPartner(N, -1);
    vector<bool> mFree(N, false);

    int freeCount = N;

    while (freeCount) {
        for (int m = 0; m < N; ++m) {
            if (mFree[m]) { continue; }

            int w = mInfo[m].front();
            mInfo[m].pop();

            if (wPartner[w] == -1) {
                wPartner[w] = m;
                mFree[m] = true;
                --freeCount;
            }
            else if (wPrefer[w][wPartner[w]] > wPrefer[w][m]) {
                mFree[wPartner[w]] = false;
                wPartner[w] = m;
                mFree[m] = true;
            }

        }
    }

    return wPartner;
}