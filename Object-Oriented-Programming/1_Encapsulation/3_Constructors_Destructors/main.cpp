#include <iostream>
#include <string>
#include "House.h"

using namespace std;
void printHouseData(const House &house);

int main()
{
    House myHouse;

    myHouse.print();

    myHouse.setNumStories(5);
    myHouse.setNumWindoes(7);
    myHouse.setColor("Blue");

    printHouseData(myHouse);
    myHouse.print();

    House testHose(2, 10, "purple");
    testHose.print();

    return 0;
}

void printHouseData(const House &house)
{
    cout << house.getNumStories() << " Stories " << house.getNumWindows() << "  Windows and " << house.getColor() << " color " << endl;
}

// g++ main.cpp House.cpp -o output
// ./output