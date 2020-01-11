#pragma once

#include <iostream>
#include <cmath>


struct Point {
    double x;
    double y;
};

std::istream& operator >> (std::istream& str, Point& p);
std::ostream& operator << (std::ostream& str, const Point& p);
Point operator + (Point lhs, Point rhs);
Point operator - (Point lhs, Point rhs);
Point operator / (Point lhs, double a);
Point operator * (Point lhs, double a);

class Vector {
public:
    explicit Vector(double a, double b);
    explicit Vector(Point a, Point b);
    bool operator == (Vector rhs);
    Vector operator - ();
    friend double operator * (Vector lhs, Vector rhs);
    double length() const;
    double x;
    double y;
};

bool is_parallel(const Vector& lhs, const Vector& rhs);
bool is_perpendecular(const Vector& lhs, const Vector& rhs);