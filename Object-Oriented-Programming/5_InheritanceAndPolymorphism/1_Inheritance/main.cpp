#include <iostream>
#include <string>
#include "animal.h"
#include "dog.h"

using namespace std;

int main()
{
    Animal mypet("abcd", 45.8);
    cout << "Pet Name " << mypet.getName() << endl;
    cout << "Pet Weight " << mypet.getWeight() << endl;
    cout << "Pet Noise " << mypet.getAnimalNoise() << endl
         << endl
         << endl;

    Dog myDog("abcd2", 32.6, "new");
    cout << "Pet Name " << myDog.getName() << endl;
    cout << "Pet Weight " << myDog.getWeight() << endl;
    cout << "Pet Breed " << myDog.getBreed() << endl;
    cout << "Pet Noise " << myDog.getAnimalNoise() << endl;
    myDog.digHole();
    cout << "Pet Noise " << myDog.getmakeNoise() << endl;
    return 0;
}