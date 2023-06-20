#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    friend void changeData(Rectangle &rect);
    friend class RectangleHelper; // forward decleration

private:
    double length;
    double width;

public:
    Rectangle();
    Rectangle(double length, double width);
    ~Rectangle();
    double getlength() const;
    double getwidth() const;
    void setlength(int length);
    void setwidth(int width);
    double area() const;
    double perimeter() const;
};

#endif