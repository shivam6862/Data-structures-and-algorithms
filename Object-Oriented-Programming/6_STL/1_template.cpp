#include <iostream>
#include <string>

using namespace std;

template <class T>
T getBigger(T a, T b);

int main()
{
    cout << getBigger(2.4, 5.4);
    return 0;
}

template <class T>
T getBigger(T a, T b)
{
    if (a > b)
        return a;
    return b;
}