#pragma once

#include <memory>
#include "Figure.h"
#include "Rectangle.h"
#include "Square.h"
#include "Trapeze.h"

class Factory {
public:

    static std::shared_ptr<Figure> FigureCreate(std::istream& is);

};