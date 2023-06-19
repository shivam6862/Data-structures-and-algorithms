#include <string>
#include <iostream>
#include "dm.h"

dm::dm(std::string name, std::string breed)
{
    this->name = name;
    this->breed = breed;
}
dm::~dm()
{
    std::cout << "Dynamic memory destroyed!" << std::endl;
}
std::string dm::getName() const
{
    return name;
}
std::string dm::getBreed() const
{
    return breed;
}