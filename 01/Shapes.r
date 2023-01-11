#ifndef SHAPES_R
#define SHAPES_R

#include "Point.r"

struct Circle
{
    const struct Point _;
    int rad;
};

struct Rectangle
{
    const void * class;
    struct Point * Point; 
    int width, length;

};

#endif