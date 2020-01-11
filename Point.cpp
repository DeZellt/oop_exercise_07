#include "Point.h"

Point operator + (Point lhs, Point rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

Point operator - (Point lhs, Point rhs) {
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

Point operator / (Point lhs, double a) {
    return { lhs.x / a, lhs.y / a};
}

Point operator * (Point lhs, double a) {
    return {lhs.x * a, lhs.y * a};
}

bool operator < (Point lhs, Point rhs) {
    return (lhs.x * lhs.x + lhs.y * lhs.y) < (lhs.x * lhs.x + lhs.y * lhs.y);
}

double operator * (Vector lhs, Vector rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

bool is_parallel(const Vector& lhs, const Vector& rhs) {
    return (lhs.x * rhs.y - lhs.y * rhs.y) == 0;
}

bool Vector::operator == (Vector rhs) {
    return
            std::abs(x - rhs.x) < std::numeric_limits<double>::epsilon() * 100
            && std::abs(y - rhs.y) < std::numeric_limits<double>::epsilon() * 100;
}

double Vector::length() const {
    return sqrt(x*x + y*y);
}

Vector::Vector(double a, double b)
        : x(a), y(b) {

}

Vector::Vector(Point a, Point b)
        : x(b.x - a.x), y(b.y - a.y){

}

Vector Vector::operator - () {
    return Vector(-x, -y);
}

bool is_perpendecular(const Vector& lhs, const Vector& rhs) {
    return (lhs * rhs) == 0;
}

std::ostream& operator << (std::ostream& str, const Point& p) {
    return str << p.x << " " << p.y;
}

std::istream& operator >> (std::istream& str, Point& p) {
    return str >> p.x >> p.y;
}