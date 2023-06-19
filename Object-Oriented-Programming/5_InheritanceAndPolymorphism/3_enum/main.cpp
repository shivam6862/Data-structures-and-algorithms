#include <iostream>
using namespace std;

int main()
{
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    Direction myDirection = DOWN;
    if (myDirection == DOWN)
        cout << "myDirection is Down!" << endl;

    return 0;
}