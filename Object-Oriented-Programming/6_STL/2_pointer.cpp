#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<double> myDubUniPtr1(new double);
    *myDubUniPtr1 = 3.14;
    cout << "Double ptr value :- " << *myDubUniPtr1 << endl;

    unique_ptr<double> myDubUniPtr2 = make_unique<double>();
    *myDubUniPtr2 = 3.14;
    cout << "Double ptr value :- " << *myDubUniPtr2 << endl;

    unique_ptr<double> otherPtr = move(myDubUniPtr1);
    cout << "otherPtr :- " << *otherPtr << endl;

    const int ARR_SIZE = 5;
    auto myArray = make_unique<int[]>(ARR_SIZE);
    for (int i = 0; i < ARR_SIZE; i++)
        myArray[i] = 2 * i;
    for (int i = 0; i < ARR_SIZE; i++)
        cout << myArray[i] << "  ";
    cout << endl;

    // shared_ptr<double> myDubSharPtr(new double);
    // weak_ptr<double> myDubWeaPtr(new double);
    return 0;
}
