#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<int> a, seg;
void buildTree(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    buildTree(2 * ind + 1, low, mid);
    buildTree(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}
int search(int ind, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
        return seg[ind];
    if (high < l || low > r)
        return -10000000;
    int mid = (low + high) / 2;
    int left = search(2 * ind + 1, low, mid, l, r);
    int right = search(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}
int main()
{
    int n = 7;
    a.resize(n + 1, 0);
    seg.resize(4 * n, 0);
    a = {1, 4, 6, 7, 9, 7, 3};
    buildTree(0, 0, n - 1);
    cout << search(0, 0, n - 1, 4, 6) << endl;
}
