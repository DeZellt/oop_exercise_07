cmake_minimum_required(VERSION 3.10)
project(oop7)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_7 main.cpp
        Document.cpp Document.h
        Editor.cpp Editor.h
        Factory.cpp Factory.h
        Figure.h
        Point.h Point.cpp
        Square.h Square.cpp
        Rectangle.h Rectangle.cpp
        Trapeze.h Trapeze.cpp)