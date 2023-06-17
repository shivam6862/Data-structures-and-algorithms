#include <iostream>
#include <string>
using namespace std;

class House
{
private:
    int numStories;
    int numWindows;
    string color;
    // setter also called mutator and getter also called accessior
public:
    void setNumStories(int numStories)
    {
        this->numStories = numStories;
    }
    void setNumWindoes(int numWindows)
    {
        this->numWindows = numWindows;
    }
    void setColor(string color)
    {
        this->color = color;
    }
    int getNumStories() const
    {
        return numStories;
    }
    int getNumWindows() const
    {
        return numWindows;
    }
    string getColor() const
    {
        return color;
    }
};

// This is a function prototype
void printHouseData(const House &house);

int main()
{
    House myHouse;
    myHouse.setNumStories(5);
    myHouse.setNumWindoes(7);
    myHouse.setColor("Blue");
    printHouseData(myHouse);
    return 0;
}

void printHouseData(const House &house)
{
    cout << house.getNumStories() << " ";
    cout << house.getNumWindows() << " ";
    cout << house.getColor() << endl;
}