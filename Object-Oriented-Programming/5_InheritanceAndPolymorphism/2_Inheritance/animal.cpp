#include <iostream>
#include <string>
#include "animal.h"

Animal::Animal(string name, double weight)
{
    this->name = name;
    this->weight = weight;
    cout << "Created Animal!" << endl;
}
string Animal::getName() const
{
    return name;
}
void Animal::setName(string name)
{
    this->name = name;
}
double Animal::getWeight() const
{
    return weight;
}
void Animal::setWeight(double weight)
{
    this->weight = weight;
}
// string Animal::makeNoise() const
// {
//     return "unknown";
// }
Animal::~Animal()
{
    std::cout << "Destroyed animal!" << std::endl;
}