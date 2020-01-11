
#include "Factory.h"

std::shared_ptr<Figure> Factory::FigureCreate(std::istream& is)  {
    std::string name;
    is >> name;
    if ( name == "square" ) {
        return std::make_shared<Square>(is);
    } else if ( name == "rectangle") {
        return std::make_shared<Rectangle>(is);
    } else if ( name == "trapeze") {
        return std::make_shared<Trapeze>(is);
    } else {
        throw std::logic_error("Wrong figure name");
    }
};
