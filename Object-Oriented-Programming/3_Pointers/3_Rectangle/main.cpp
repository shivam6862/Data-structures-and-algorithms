#include <iostream>
#include "Rectangle.h"

void printRectangle(Rectangle &rectangle);

int main()
{
    const int arrsize = 3;
    // Rectangle *newRectangle[arrsize];
    Rectangle **newRectangle = new Rectangle *[arrsize];
    for (int i = 0; i < arrsize; i++)
    {

        double l, b;
        std::cout << "Enter the length of " << i + 1 << " Rectangle :- ";
        std::cin >> l;
        std::cout << "Enter the breath of " << i + 1 << " Rectangle :- ";
        std::cin >> b;

        newRectangle[i] = new Rectangle(l, b);
        std::cout << "Rectangle area " << newRectangle[i]->area() << std::endl;
        std::cout << "Rectangle perimeter " << newRectangle[i]->perimeter() << std::endl;

        printRectangle(*newRectangle[i]);
        delete newRectangle[i];
        newRectangle[i] = nullptr;
    }

    return 0;
}

void printRectangle(Rectangle &rectangle)
{
    std::cout << rectangle.getlength() << "  " << rectangle.getwidth() << std::endl;
}
