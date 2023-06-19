#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    ifstream infile;
    infile.open("input.txt");

    int inputNum;
    int sum = 0;

    while (!infile.eof())
    {
        infile >> inputNum;
        sum += inputNum;
        v.push_back(inputNum);
    }

    for (int it : v)
        cout << it << endl;

    cout << "Sum of the Number :- " << sum;

    infile.close();
    return 0;
}