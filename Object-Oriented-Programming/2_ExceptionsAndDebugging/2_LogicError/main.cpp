#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
    try
    {

        vector<int> v;
        v.resize(v.max_size() + 1);
        cout << "Yes it is bigger!" << endl;
    }
    catch (const length_error &err)
    {
        cerr << err.what() << endl;
    }
    return 0;
}
