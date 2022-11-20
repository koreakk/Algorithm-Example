#include <vector>
using namespace std;

double PolygonArea(const vector<int>& X, const vector<int>& Y) {
    const size_t N = X.size();

    double area = 0;
    for (int i = 0, j = N - 1; i < N; j = i++) {
        area += (double)(X[j] + X[i]) * (Y[j] - Y[i]) / 2;
    }

    return abs(area);
}