#ifndef DOG_H
#define DOG_H
#include <string>
#include "animal.h"

class Dog : public Animal
{
private:
    std::string breed;

public:
    Dog(std::string name, double weight, std::string breed);
    std::string getBreed() const;
    void digHole();
    std::string makeNoise() const;
    ~Dog();
};

#endif