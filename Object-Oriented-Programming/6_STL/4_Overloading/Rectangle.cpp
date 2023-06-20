#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle()
{
    length = 1.0;
    width = 1.0;
    std::cout << "Creating the Rectangle!\n";
}
Rectangle::Rectangle(double length, double width)
{
    this->length = length;
    this->width = width;
}
Rectangle::~Rectangle()
{
    std::cout << "Destorying the Rectangle!\n";
}
double Rectangle::getlength() const
{
    return length;
}
double Rectangle::getwidth() const
{
    return width;
}
void Rectangle::setlength(int length)
{
    this->length = length;
}
void Rectangle::setwidth(int width)
{
    this->width = width;
}
double Rectangle::area() const
{
    return length * width;
}
double Rectangle::perimeter() const
{
    return 2 * (length + width);
}

// Operator
bool Rectangle::operator==(const Rectangle &other) const
{
    return length == other.length && width == other.width;
}
Rectangle Rectangle::operator+(const Rectangle &other) const
{
    Rectangle newRect(length + other.length, width + other.width);
    return newRect;
}
void Rectangle::operator=(const Rectangle &other)
{
    length = other.length;
    width = other.width;
}
bool Rectangle::operator!=(const Rectangle &other) const
{
    return length != other.length || width != other.width;
}