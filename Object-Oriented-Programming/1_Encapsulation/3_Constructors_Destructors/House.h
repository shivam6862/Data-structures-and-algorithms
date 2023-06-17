#ifndef HOUSE_H
#define HOUSE_H

#include <string>
using namespace std;

class House
{
private:
    int numStories;
    int numWindows;
    string color;

public:
    House();
    House(int numStories, int numWindows, string color);
    ~House();
    void setNumStories(int numStories);
    void setNumWindoes(int numWindows);
    void setColor(string color);
    int getNumStories() const;
    int getNumWindows() const;
    string getColor() const;
    void print() const;
};

#endif