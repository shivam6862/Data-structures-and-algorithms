#include <iostream>
#include "House.h"

House::House()
{
    this->numStories = 1;
    this->numWindows = 4;
    this->color = "lime";
    cout << "Constructor is called!" << endl;
}
House::House(int numStories, int numWindows, string color)
{
    this->numStories = numStories;
    this->numWindows = numWindows;
    this->color = color;
    cout << "Constructor is called!" << endl;
}
House::~House()
{
    std::cout << "The House is " << color << " and has " << numStories << " stories and has " << numWindows << " windows is being destroyed!" << endl;
}
void House::setNumStories(int numStories)
{
    this->numStories = numStories;
}
void House::setNumWindoes(int numWindows)
{
    this->numWindows = numWindows;
}
void House::setColor(string color)
{
    this->color = color;
}
int House::getNumStories() const
{
    return numStories;
}
int House::getNumWindows() const
{
    return numWindows;
}
string House::getColor() const
{
    return color;
}
void House::print() const
{
    std::cout << "The House is " << color << " and has " << numStories << " stories and has " << numWindows << " windows." << endl;
}