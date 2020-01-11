#pragma once

#include "Figure.h"

class Rectangle : public Figure {
public:
    Rectangle(std::istream& is);
    Rectangle(Point p1, Point p2, Point p3, Point p4);
    void Print(std::ostream& os) const override;

private:
    Point p1_, p2_, p3_, p4_;
};