#ifndef Animal_H
#define Animal_H
#include <string>
using namespace std;

class Animal
{
private:
    string name;
    double weight;

public:
    Animal(string name, double weight);
    string getName() const;
    void setName(string name);
    double getWeight() const;
    void setWeight(double weight);
    string getAnimalNoise() const;
    ~Animal();
};

#endif
