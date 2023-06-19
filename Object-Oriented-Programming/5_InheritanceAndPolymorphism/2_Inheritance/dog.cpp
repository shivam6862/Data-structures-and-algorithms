#include <iostream>
#include <string>
#include "dog.h"
using namespace std;

Dog::Dog(std::string name, double weight, std::string breed) : Animal(name, weight)
{
    this->breed = breed;
    cout << "Created Dog!" << endl;
}
std::string Dog::getBreed() const
{
    return breed;
}
void Dog::digHole()
{
    cout << "I am digging a hol1!" << endl;
}
Dog::~Dog()
{
    cout << "Destroyed Dog!" << endl;
}

string Dog::makeNoise() const
{
    return "Bark";
}