#pragma once

#include "Figure.h"
#include <exception>

class Trapeze : public Figure {
public:
    Trapeze(std::istream& is);
    Trapeze(Point p1, Point p2, Point p3, Point p4);
    void Print(std::ostream& os) const override;

private:
    Point p1_, p2_, p3_, p4_;
};

