#include <string>
#include <iostream>
#include "dm.h"
using namespace std;

void print(dm &create);

int main()
{
    dm *createDM = new dm("jake", "abc");
    print(*createDM);

    cout << "Dog " << (*createDM).getName() << " breed " << (*createDM).getBreed() << endl;
    cout << "Dog " << createDM->getName() << " breed " << createDM->getBreed() << endl;

    delete createDM;
    createDM = nullptr;

    int arr_size;
    cout << "Enter the lemgth of array :- ";
    cin >> arr_size;

    int *myarray = new int[arr_size];
    for (int i = 0; i < arr_size; i++)
        myarray[i] = i + 1;
    for (int i = 0; i < arr_size; i++)
        cout << myarray[i] << "  ";

    cout << endl;
    delete[] myarray;

    return 0;
}

void print(dm &create)
{
    cout << "Dog " << create.getName() << " breed " << create.getBreed() << endl;
}