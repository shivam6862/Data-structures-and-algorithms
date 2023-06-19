#include <iostream>

using namespace std;

int main()
{
    int n = 190;
    int *m = &n;
    int **c = &m;

    cout << m << endl;
    cout << *m << endl;

    cout << c << endl;
    cout << *c << endl;
    cout << **c << endl;

    long long *i = new long long(9781800564084);

    cout << i << endl;
    cout << *i << endl;

    delete i;
    i = nullptr;
    cout << i << endl;

    return 0;
}
