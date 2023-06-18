#include <iostream>
#include "CustomExceptions.h"
using namespace std;
void dowork(int num);
int main()
{
    int num = 0;
    cin >> num;
    try
    {
        dowork(num);
    }
    catch (const CustomExceptions &err)
    {
        cout << err.what() << endl;
    }
    return 0;
}
void dowork(int num)
{
    if (num < 3)
    {
        throw CustomExceptions();
    }
    cout << num << endl;
}