#include <iostream>
#include "Rectangle.h"
#include "Rectangle_helper.h"

void printRectangle(Rectangle &rectangle);

int main()
{
    double l, b;
    std::cout << "Enter the length of Rectangle :- ";
    std::cin >> l;
    std::cout << "Enter the breath of Rectangle :- ";
    std::cin >> b;
    Rectangle newRectangle(l, b);
    printRectangle(newRectangle);

    changeData(newRectangle);
    printRectangle(newRectangle);

    RectangleHelper helper;
    helper.modifyRectangle(newRectangle);
    printRectangle(newRectangle);

    return 0;
}

void printRectangle(Rectangle &rectangle)
{
    std::cout << rectangle.getlength() << "  " << rectangle.getwidth() << std::endl;
    std::cout << "Rectangle area " << rectangle.area() << std::endl;
    std::cout << "Rectangle perimeter " << rectangle.perimeter() << std::endl;
}

void changeData(Rectangle &rect)
{
    rect.length = 200;
    rect.width = 100;
}