#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<int> a;
vector<pair<int, int>> seg;
void buildTree(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = {a[low], a[low]};
        return;
    }
    int mid = (low + high) / 2;
    buildTree(2 * ind + 1, low, mid);
    buildTree(2 * ind + 2, mid + 1, high);
    seg[ind] = {min(seg[2 * ind + 1].first, seg[2 * ind + 2].first), max(seg[2 * ind + 1].second, seg[2 * ind + 2].second)};
}
pair<int, int> search(int ind, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
        return seg[ind];
    if (high < l || low > r)
        return {10000000, -10000000};
    int mid = (low + high) / 2;
    pair<int, int> left = search(2 * ind + 1, low, mid, l, r);
    pair<int, int> right = search(2 * ind + 2, mid + 1, high, l, r);
    return {min(left.first, right.first), max(left.second, right.second)};
}
int main()
{
    int n = 7;
    a.resize(n + 1, 0);
    seg.resize(4 * n, {0, 0});
    a = {1, 4, 6, 7, 9, 7, 3};
    buildTree(0, 0, n - 1);
    int a, b;
    cin >> a >> b;
    pair<int, int> answer = search(0, 0, n - 1, a, b);
    cout << answer.first << " " << answer.second << endl;
}
