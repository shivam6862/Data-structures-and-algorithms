#include <iostream>
#include "Rectangle.h"

void printRectangle(Rectangle &rectangle);

int main()
{
    Rectangle newRectangle1(10, 20);
    Rectangle newRectangle2(50, 100);
    Rectangle newRectangle3(10, 20);
    Rectangle newRectangle4;
    newRectangle4 = newRectangle1 + newRectangle2;
    printRectangle(newRectangle4);

    bool check = newRectangle1 == newRectangle3;
    std::cout << "Checking " << check << std::endl;

    bool checkN = newRectangle1 != newRectangle2;
    std::cout << "Checking " << checkN << std::endl;
    return 0;
}

void printRectangle(Rectangle &rectangle)
{
    std::cout << rectangle.getlength() << "  " << rectangle.getwidth() << std::endl;
    std::cout << "Rectangle area " << rectangle.area() << std::endl;
    std::cout << "Rectangle perimeter " << rectangle.perimeter() << std::endl;
}