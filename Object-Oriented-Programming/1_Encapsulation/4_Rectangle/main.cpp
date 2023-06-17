#include <iostream>
#include "Rectangle.h"

int main()
{
    Rectangle myRectangle;
    myRectangle.setlength(4);
    myRectangle.setwidth(2);
    std::cout << myRectangle.getlength() << " cm length and " << myRectangle.getwidth() << " cm width ." << std::endl;
    std::cout << "Myrectangle area " << myRectangle.area() << std::endl;
    std::cout << "Myrectangle perimeter " << myRectangle.perimeter() << std::endl;

    double l, b;
    std::cout << "Enter the length :- ";
    std::cin >> l;
    std::cout << "Enter the breath :- ";
    std::cin >> b;
    Rectangle newRectangle(l, b);
    std::cout << "newRectangle area " << newRectangle.area() << std::endl;
    std::cout << "newRectangle perimeter " << newRectangle.perimeter() << std::endl;

    printRectangle(newRectangle);
    return 0;
}

void printRectangle(const Rectangle &rectangle)
{
    std::cout << rectangle.getlength() << rectangle.getwidth() << std::endl;
}