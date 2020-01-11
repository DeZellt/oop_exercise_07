#pragma once

#include "Figure.h"

class Square : public Figure {
public:
    Square(std::istream& is);
    Square(Point p1, Point p2, Point p3, Point p4);
    void Print(std::ostream& os) const override;

private:
    Point p1_, p2_, p3_, p4_;
};