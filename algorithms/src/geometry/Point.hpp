#ifndef Point_hpp
#define Point_hpp

const double epsilon = 1e-9;

struct Point {
    double x, y;
    Point() { x = y = 0.0; }
    Point(double x, double y) : x(x), y(y) {}

    Point& operator = (const Point& point) {
        x = point.x; y = point.y;
        return *this;
    }

    Point& operator += (const Point& point) {
        x += point.x; y += point.y;
        return *this;
    }

    Point& operator -= (const Point& point) {
        x -= point.x; y -= point.y;
        return *this;
    }

    Point& operator *= (double k) {
        x *= k; y *= k;
        return *this;
    }

    Point& operator /= (double k) {
        x /= k; y /= k;
        return *this;
    }

    bool operator < (const Point& point) {
        if (fabs(x - point.x) > epsilon) {
            return x < point.x;
        }
        return y < point.y;
    }

    bool operator == (const Point& point) {
        return (fabs(x - point.x) < epsilon && (fabs(y - point.y) < epsilon));
    }

};

#endif