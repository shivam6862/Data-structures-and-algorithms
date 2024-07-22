#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<int> a, seg;
vector<int> lazy;
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
int rangeUpdate(int ind, int low, int high, int l, int r, int val)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (high - low + 1) * lazy[ind];
        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (r < low || l > high || low > high)
        return;
    if (low >= l && high <= r)
    {
        seg[ind] += (high - low + 1) * val;
        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        return;
    }
    int mid = (low + high) >> 1;
    rangeUpdate(2 * ind + 1, low, mid, l, r, val);
    rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}
int querySumLAzy(int ind, int low, int high, int l, int r, int val)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (high - low + 1) * lazy[ind];
        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (r < low || l > high || low > high)
        return 0;
    if (low >= l && high <= r)
        return seg[ind];
    int mid = (low + high) >> 1;
    return querySumLAzy(2 * ind + 1, low, mid, l, r, val) + querySumLAzy(2 * ind + 2, mid + 1, high, l, r, val);
}
int main()
{
    int n = 7;
    a.resize(n + 1, 0);
    lazy.resize(n + 1, 0);
    seg.resize(4 * n, 0);
    a = {1, 4, 6, 7, 9, 7, 3};
    buildTree(0, 0, n - 1);
}
