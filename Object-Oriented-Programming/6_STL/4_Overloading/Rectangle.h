#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
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
    bool operator==(const Rectangle &other) const;
    Rectangle operator+(const Rectangle &other) const;
    void operator=(const Rectangle &other);
    bool operator!=(const Rectangle &other) const;
};

#endif