#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ofstream outfile;

    cout << "Writing to file!" << endl;

    outfile.open("output.txt");

    outfile << "My name is shivam kumar." << endl;

    outfile << fixed << showpoint;
    cout << fixed << showpoint;

    int n;
    cout << "Enter the number of times :- ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        outfile << setw(12) << setprecision(2) << (i * 5.7575) << setw(10) << setprecision(3) << (i * 3.4523) << endl;
        cout << setw(12) << setprecision(2) << (i * 5.7575) << setw(10) << setprecision(3) << (i * 3.4523) << endl;
    }

    outfile.close();

    cout << "Done!" << endl;

    return 0;
}