#include "Trapeze.h"


Trapeze::Trapeze(Point p1, Point p2, Point p3, Point p4)
:  p1_(p1), p2_(p2), p3_(p3), p4_(p4){
    Vector v1(p1_, p2_), v2(p3_, p4_);
    if (v1 = Vector(p1_, p2_), v2 = Vector(p3_, p4_), is_parallel(v1, v2)) {
        if (v1 * v2 < 0) {
            std::swap(p3_, p4_);
        }
    } else if (v1 = Vector(p1_, p3_), v2 = Vector(p2_, p4_), is_parallel(v1, v2)) {
        if (v1 * v2 < 0) {
            std::swap(p2_, p4_);
        }
        std::swap(p2_, p3_);
    } else if (v1 = Vector(p1_, p4_), v2 = Vector(p2_, p3_), is_parallel(v1, v2)) {
        if (v1 * v2 < 0) {
            std::swap(p2_, p3_);
        }
        std::swap(p2_, p4_);
        std::swap(p3_, p4_);
    } else {
        throw std::logic_error("At least 2 sides of trapeze must be parallel");
    }

}


void Trapeze::Print(std::ostream& os) const {
    os << "trapeze\n"
       << p1_ << "\n"
       << p2_ << "\n"
       << p3_ << "\n"
       << p4_ << "\n";
}

Trapeze::Trapeze(std::istream &is) {
    Point p1,p2,p3,p4;
    is >> p1 >> p2 >> p3 >> p4;
    *this = Trapeze(p1,p2,p3,p4);
}