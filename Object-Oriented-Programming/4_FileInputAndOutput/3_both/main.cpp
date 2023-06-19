#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    ifstream tvfile;
    ifstream salesfile;
    ofstream outfile;

    cout << "Opening files!..." << endl;
    tvfile.open("tv.txt");
    salesfile.open("sales.txt");
    outfile.open("outfile.txt");
    cout << "Opened files!..." << endl;

    if (!tvfile || !salesfile)
    {
        cout << "Problem in opening the files!..." << endl;
        return 1;
    }

    double temptv, tempsale;

    outfile << "TV   "
            << "  "
            << "SALES" << endl;

    while (!tvfile.eof() && !salesfile.eof())
    {
        tvfile >> temptv;
        salesfile >> tempsale;
        outfile << setw(5) << temptv << "  " << setw(5) << tempsale << endl;
    }

    tvfile.close();
    salesfile.close();
    outfile.close();

    cout << "Done!..." << endl;
    return 0;
}