#include <iostream>
#include <vector>

using namespace std;
void update(int i, int add, vector<int> &fen, int n)
{
    while (i < n)
    {
        fen[i] += add;
        i = i + (i & (-i));
    }
}
int suming(int i, vector<int> &fen)
{
    int add = 0;
    while (i > 0)
    {
        add += fen[i];
        i = i - (i & (-i));
    }
    return add;
}
int rangsum(int l, int r, vector<int> &fen)
{
    return suming(r, fen) - suming(l - 1, fen);
}
int main()
{
    int n = 17;
    vector<int> fen(n, 0);
    update(1, 5, fen, 17);
    update(3, 10, fen, 17);
    update(7, 3, fen, 17);
    update(10, 15, fen, 17);
    update(14, 12, fen, 17);
    cout << suming(6, fen) << endl;
    cout << suming(8, fen) << endl;
    cout << rangsum(2, 10, fen) << endl;
    cout << rangsum(5, 12, fen) << endl;
}
