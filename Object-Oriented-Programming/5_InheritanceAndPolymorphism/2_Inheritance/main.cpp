#include <iostream>
#include <string>
#include "animal.h"
#include "dog.h"

using namespace std;

int main()
{
    // Animal mypet("abcd", 45.8);
    // cout << "Pet Name " << mypet.getName() << endl;
    // cout << "Pet Weight " << mypet.getWeight() << endl;
    // cout << "Pet Noise " << mypet.makeNoise() << endl
    //      << endl
    //      << endl;

    Dog myDog("abcd2", 32.6, "new");
    cout << "myDog Name " << myDog.getName() << endl;
    cout << "myDog Weight " << myDog.getWeight() << endl;
    cout << "myDog Breed " << myDog.getBreed() << endl;
    cout << "myDog Noise " << myDog.makeNoise() << endl;
    myDog.digHole();
    cout << "myDog Noise " << myDog.makeNoise() << endl;

    Animal *dogptr = new Dog("joker", 45.8, "kklkl");
    cout << "dogptr " << dogptr->makeNoise() << endl;
    delete dogptr;
    dogptr = nullptr;

    return 0;
}