struct Point { int x, y; };

// Counter-ClockWise Algorithm
int ccw(Point p1, Point p2, Point p3) {
    return (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
}