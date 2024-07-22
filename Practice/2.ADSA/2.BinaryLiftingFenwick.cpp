#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void update(int i, int add, vector<int> &fen, int n)
{
    while (i < n)
    {
        fen[i] += add;
        i = i + (i & (-i));
    }
}

int finder(int k, int n, vector<int> &fen)
{
    int curr = 0, ans = 0, prevSum = 0;
    for (int i = log2(n); i >= 0; i--)
    {
        if (fen[curr + 1 << i] + prevSum < k)
        {
            curr += (1 << i);
            prevSum += fen[curr];
        }
    }
    return curr + 1;
}

int main()
{
    int n = 17;
    vector<int> fen(n, 0);
    update(1, 5, fen, n);
    update(3, 10, fen, n);
    update(7, 3, fen, n);
    update(10, 15, fen, n);
    update(14, 12, fen, n);
    cout << finder(17, n, fen);
}
