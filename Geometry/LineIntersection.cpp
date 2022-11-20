#include <utility>
using namespace std;

struct Point { long long x, y; };
struct Line  { Point     s, e; };

bool operator<=(const Point& left, const Point& right) {
    if (left.x == right.x) {
        return left.y <= right.y;
    }
    return left.x <= right.x;
}

int ccw(const Point& p1, const Point& p2, const Point& p3) {
    long long d = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    return (d > 0) ? 1 : (d < 0) ? -1 : 0;
}

bool LineIntersection(const Line& Al, const Line& Bl) {
    Point s1 = Al.s, e1 = Al.e;
    Point s2 = Bl.s, e2 = Bl.e;

    int d1 = ccw(s1, e1, s2), d2 = ccw(s1, e1, e2);
    if (d1 == 0 && d2 == 0) {
        if (e1 <= s1) swap(s1, e1);
        if (e2 <= s2) swap(s2, e2);

        return s1 <= e2 && s2 <= e1;
    }

    return ccw(s2, e2, s1) != ccw(s2, e2, e1) && d1 != d2;
}