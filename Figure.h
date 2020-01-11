#pragma once

#include <numeric>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

#include "Point.h"

class Figure {
public:
    virtual void Print(std::ostream& os) const = 0;
    virtual ~Figure() = default;
};
