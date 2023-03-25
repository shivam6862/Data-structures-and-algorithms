#include <iostream>
#include <string>
#include <string>
#include <array>
#include <iterator>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cmath>

using namespace std;

//  PROBLEM- A******************************************************************************************
// FIBONACI SERIES
using namespace std;

int f(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp);
}

// PROBLEM -B**********************************************************************************************

// MINIMUN COST JUMP FROM ONE STAIR TO OTHER (1 OR 2 STAIR JUMP ALLOWED)

// WITH DP AND RECURRSION
using namespace std;
int f(int ind, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int left = f(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = f(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    return dp[ind] = min(left, right);
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    vector<int> heights(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cout << f(n - 1, heights, dp);
}

// WITH LOOP SAME QUESTION
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n, 0);
    dp[0] = 0;
    vector<int> heights(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    for (int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(fs, ss);
    }
    cout << dp[n - 1];
}

// WITH FOR LOOP AND EXTRA SPACE REDUCING
using namespace std;
int main()
{
    int n;
    cin >> n;
    int prev = 0;
    int prev2 = 0;
    vector<int> heights(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    for (int i = 1; i < n; i++)
    {
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = prev2 + abs(heights[i] - heights[i - 2]);
        int curi = min(fs, ss);
        prev2 = prev;
        prev = curi;
    }
    cout << prev;
}

// PROBLEM-B (PART-2)********************************************************************************************

// FROG JUMPING UPTO Kth POINT (PART PART)

using namespace std;
int jump;
using namespace std;
int find(int ind, vector<int> &a, int k, vector<int> dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int mmstep = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
            jump = find(ind - j, a, k, dp) + abs(a[ind] - a[ind - j]);
        mmstep = min(mmstep, jump);
    }
    return dp[ind] = mmstep;
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    vector<int> heights(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    int k = 3;
    cout << find(n - 1, heights, k, dp);
}

// PROBLEM-C *******************************************************************************************
// Maximum Sum of Non-AdjacentElements

// WITH RECURSION AND DP
using namespace std;
int f(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int pick = nums[ind] + f(ind - 2, nums, dp);
    int notpick = 0 + f(ind - 1, nums, dp);
    return dp[ind] = max(pick, notpick);
}
int main()
{
    int ind;
    cin >> ind;
    vector<int> dp(ind, -1);
    vector<int> nums(ind, 0);
    for (int i = 0; i < ind; i++)
        cin >> nums[i];
    cout << f(ind - 1, nums, dp);
}

// WITH LOOP AND TWO SPACE
using namespace std;
int main()
{
    int ind;
    cin >> ind;
    vector<int> dp(ind, -1);
    vector<int> nums(ind, 0);
    for (int i = 0; i < ind; i++)
        cin >> nums[i];

    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int take = nums[i];
        if (i > 1)
            take += prev2;

        int nottake = 0 + prev;
        int curi = max(take, nottake);
        prev2 = prev;
        prev = curi;
    }
    cout << prev;
}

// WITH FOR LOOP AND DP
using namespace std;
int main()
{
    int ind;
    cin >> ind;
    vector<int> dp(ind, -1);
    vector<int> nums(ind, 0);
    for (int i = 0; i < ind; i++)
        cin >> nums[i];

    dp[0] = nums[0];
    for (int i = 1; i < ind; i++)
    {
        int take = nums[i];
        if (i > 1)
            take += dp[i - 2];

        int nottake = 0 + dp[i - 1];
        dp[i] = max(take, nottake);
    }
    cout << dp[ind - 1];
}

// PROBLEM-D *******************************************************************************************
// Ninja's Training WITHOUT DP

using namespace std;
int f(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + f(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(4, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }
    cout << f(n - 1, 3, points);
}

// WITH DP(N) THE SAME PROGRAM
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + f(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(4, 0));
    vector<vector<int>> dp(n, vector<int>(4, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }
    cout << f(n - 1, 3, points, dp);
}

// WITH FOR LOOP
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(4, 0));
    vector<vector<int>> dp(n, vector<int>(4, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    cout << dp[n - 1][3];
}

// WITH FOR LOOP AND LEAST SPACE TAKEN
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(4, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    cout << prev[3];
}
/*
INPUT
4
2 1 3
3 4 6
10 1 6
8 3 7*/

// PROBLEM- E *******************************************************************************************

// GRID MOTION IN UNIQUE PATH WITHOUT DP
// ONLY RECURRSION

using namespace std;
int f(int i, int j)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = f(i - 1, j);
    int left = f(i, j - 1);
    return up + left;
}
int main()
{
    int m, n;
    cin >> n >> m;
    cout << f(m - 1, n - 1);
}

// WITH DP SAME PROBLEM
using namespace std;
int f(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = f(i - 1, j, dp);
    int left = f(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int main()
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << f(m - 1, n - 1, dp);
}

// WITH FOR LOOP,WITHOUT SPACE REDUCING ,WITH DP(N)
using namespace std;
int main()
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] == 1;
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    cout << dp[m - 1][n - 1];
}

// WITH FOR LOOP,WITH SPACE REDUCING ,WITHOUT DP(N)

using namespace std;
int main()
{
    int m, n;
    cin >> n >> m;
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> cur(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                cur[j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = cur[j - 1];
                cur[j] = up + left;
            }
        }
        prev = cur;
    }
    cout << prev[n - 1];
}

// WITH SOME CONDITION SAME ABOVE PROBLEM WITH RECURSION AND DP(N)

using namespace std;
int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && mat[i][j] == -1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = f(i - 1, j, mat, dp);
    int left = f(i, j - 1, mat, dp);
    return dp[i][j] = up + left;
}
int main()
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    vector<vector<int>> mat(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    cout << f(m - 1, n - 1, mat, dp);
}

// WITH SOME CONDITION SAME ABOVE PROBLEM WITH FOR LOOP AND DP(N)
using namespace std;
int main()
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> dp(m, vector<int>(n, 1));
    vector<vector<int>> mat(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == -1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] == 1;
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    cout << dp[m - 1][n - 1];
}

// PROBLEM- F *******************************************************************************************

// MINIMUN PATH IN THE GRID,WITHOUT DP(N),WITH RECURSION

// ONLY RECURRSION
using namespace std;

int f(int i, int j, vector<vector<int>> &mat)
{
    if (i == 0 && j == 0)
        return mat[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    int up = mat[i][j] + f(i - 1, j, mat);
    int left = mat[i][j] + f(i, j - 1, mat);
    return min(left, up);
}
int main()
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    vector<vector<int>> mat(m, vector<int>(n, 9));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    cout << f(m - 1, n - 1, mat);
}

// WITH DP(N) AND RECURSION FIND IN MIN. PATH IN GRID
using namespace std;

int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return mat[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = mat[i][j] + f(i - 1, j, mat, dp);
    int left = mat[i][j] + f(i, j - 1, mat, dp);
    return dp[i][j] = min(left, up);
}
int main()
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    vector<vector<int>> mat(m, vector<int>(n, 9));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    cout << f(m - 1, n - 1, mat, dp);
}

// WITH FOR LOOP AND DP(N)
using namespace std;
int main()
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    vector<vector<int>> mat(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = mat[i][j];
            else
            {
                int up = mat[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;
                int left = mat[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;
                dp[i][j] = min(left, up);
            }
        }
    }
    cout << dp[m - 1][n - 1];
}

// WITH FOR LOOP AND SPACE LESS
using namespace std;
int main()
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> mat(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> cur(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                cur[j] = mat[i][j];
            else
            {
                int up = mat[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;
                int left = mat[i][j];
                if (j > 0)
                    left += cur[j - 1];
                else
                    left += 1e9;
                cur[j] = min(left, up);
            }
        }
        prev = cur;
    }
    cout << prev[n - 1];
}

// PROBLEM- G *******************************************************************************************

// FINDING MAXIMUM IN THE GRID MOTION FOR ANY LOWEST ROW TO ANY TOPMOST ROW ****WITH DP(N)
using namespace std;

int f(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    if (j < 0 || j >= 3)
        return -1e9;
    if (i == 0)
        return a[0][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int s = a[i][j] + f(i - 1, j, a, dp);
    int ld = a[i][j] + f(i - 1, j - 1, a, dp);
    int rd = a[i][j] + f(i - 1, j + 1, a, dp);
    return dp[i][j] = (max(max(s, ld), rd));
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int ma = -1e9;
    for (int j = m; j >= 0; j--)
    {
        int kk = f(n - 1, j - 1, a, dp);
        ma = max(kk, ma);
    }
    cout << ma;
}

// WITH FOR LOOP AND WITH DP(N)
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int j = 0; j < m; j++)
        dp[0][j] = a[0][j];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = a[i][j] + dp[i - 1][j];
            int ld = a[i][j];
            if (j - 1 >= 0)
                ld += dp[i - 1][j - 1];
            else
                ld += -1e8;
            int rd = a[i][j];
            if (j + 1 < m)
                rd += dp[i - 1][j + 1];
            else
                rd += -1e8;
            dp[i][j] = (max(max(u, ld), rd));
        }
    }

    int ma = -1e8;
    for (int j = 0; j < m; j++)
    {
        ma = max(ma, dp[n - 1][j]);
    }
    cout << ma;
}

// WITH FOR LOOP AND SPACE OPTIMISATION
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<int> prev(m, 0);
    vector<int> cur(m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int j = 0; j < m; j++)
        prev[j] = a[0][j];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = a[i][j] + prev[j];
            int ld = a[i][j];
            if (j - 1 >= 0)
                ld += prev[j - 1];
            else
                ld += -1e8;
            int rd = a[i][j];
            if (j + 1 < m)
                rd += prev[j + 1];
            else
                rd += -1e8;
            cur[j] = (max(max(u, ld), rd));
        }
        prev = cur;
    }

    int ma = -1e8;
    for (int j = 0; j < m; j++)
    {
        ma = max(ma, prev[j]);
    }
    cout << ma;
}

// PROBLEM- H *******************************************************************************************

// WHEN TWO MAN IS MOVING IN 2D MATRIX AND FINDING THE MAXIMUM SUM OF THE ELEMENT (FIRST MAN IS MOVING FROM Oth AND SECOND MAN IS MOVING FROM LAST COLUM

// WITH RECURSION AND WITHOUT DP(N)
int f(int i, int j1, int j2, int r, int c, vector<vector<int>> a)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;
    if (i == r - 1)
    {
        if (j1 == j2)
            return a[i][j1];
        else
            return a[i][j1] + a[i][j2];
    }

    // EXPLORE ALL THE PATH ALICE AND BOB SIMLTANEOUSLY
    int maxi = 0;
    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        for (int dj2 = -1; dj2 <= +1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = a[i][j1];
            else
                value = a[i][j1] + a[i][j2];
            value += f(i + 1, j1 + dj1, j2 + dj2, r, c, a);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cout << f(0, 0, m - 1, n, m, a);
}

// WITH RECURSION AND WITH THE USE OF DP(N)
using namespace std;

int f(int i, int j1, int j2, int r, int c, vector<vector<int>> a, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;
    if (i == r - 1)
    {
        if (j1 == j2)
            return a[i][j1];
        else
            return a[i][j1] + a[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    // EXPLORE ALL THE PATH ALICE AND BOB SIMLTANEOUSLY
    int maxi = 0;
    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        for (int dj2 = -1; dj2 <= +1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = a[i][j1];
            else
                value = a[i][j1] + a[i][j2];
            value += f(i + 1, j1 + dj1, j2 + dj2, r, c, a, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cout << f(0, 0, m - 1, n, m, a, dp);
}

// WITH FOR LOOP WITHOUT REDUCING THE SPACE
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = 0;
                for (int dj1 = -1; dj1 <= +1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            value += 0;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    cout << dp[0][0][m - 1];
}

// WITH FOR LOOP AND SPACE IS ALSO LESS
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = 0;
                for (int dj1 = -1; dj1 <= +1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            value += front[j1 + dj1][j2 + dj2];
                        else
                            value += 0;
                        maxi = max(maxi, value);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }
    cout << front[0][m - 1];
}

// PROBLEM- I *******************************************************************************************

// Subset SUM IS POSSIBLE OR NOT WITH RECURRSION WITHOUT DP(N)
// ONLY RECURSION
bool f(int ind, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[0] == target);

    bool nottake = f(ind - 1, target, arr);
    bool take = false;
    if (arr[ind] <= target)
        take = f(ind - 1, target - arr[ind], arr);
    return take | nottake;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << f(n - 1, k, arr);
}

// WITH DP(N)  AND THE RECURRSION
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[0] == target);
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool nottake = f(ind - 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target)
        take = f(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = take | nottake;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << f(n - 1, k, arr, dp);
}

// WITH FOR LOOP WITH  DP(N) , WITHOUT SPACE LESS
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // cout<<f(n-1,k,arr,dp);

    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nottake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = take | nottake;
        }
    }
    cout << dp[n - 1][k];
}

// WITH SPACE LESS , FOR LOOP IS USING
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<bool> prev(k + 1, 0);
    vector<bool> cur(k + 1, 0);
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    prev[0] = true;
    cur[0] = true;
    if (arr[0] <= k)
        prev[arr[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nottake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];
            cur[target] = take | nottake;
        }
        prev = cur;
    }
    cout << prev[k];
}

// PROBLEM- J *******************************************************************************************

// DIVIDING THE ARRAY INTO TWO PART SUCH THAT DIFFERENCE IS AS MINIMUM AS POSSIBLE

// RECURSION AND DP
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    vector<vector<bool>> dp(n, vector<bool>(n + 1, 0));
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int totsum = 0;
    for (int i = 0; i < n; i++)
        totsum += arr[i];
    int k = totsum;

    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= k)
        dp[0][arr[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nottake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = take | nottake;
        }
    }
    int mini = 1e9;
    for (int s1 = 0; s1 <= totsum / 2; s1++)
    {
        if (dp[n - 1][s1] == true)
            mini = min(mini, (abs((totsum - s1) - s1)));
    }
    cout << mini;
}

// PROBLEM- K *******************************************************************************************

// NUMBER OF SUBSET EQUAL TO GIVEN SUM IN A SET

// RECURSION
using namespace std;

int find(int ind, int sum, vector<int> &num)
{
    if (sum == 0)
        return 1;
    if (ind == 0)
        return num[0] == sum;

    int nottake = find(ind - 1, sum, num);
    int take = 0;
    if (num[ind] <= sum)
        take = find(ind - 1, sum - num[ind], num);
    return nottake + take;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    int tar;
    cin >> tar;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << find(n - 1, tar, v);
}

// SAME PROBLEM WITH DP(N)
using namespace std;

int find(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (ind == 0)
        return num[0] == sum;
    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int nottake = find(ind - 1, sum, num, dp);
    int take = 0;
    if (num[ind] <= sum)
        take = find(ind - 1, sum - num[ind], num, dp);
    return dp[ind][sum] = nottake + take;
}
int main()
{
    int n;
    cin >> n;
    int tar;
    cin >> tar;
    vector<int> v(n, 0);
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << find(n - 1, tar, v, dp);
}

// FOR LOOP AND DP
int main()
{
    int n;
    cin >> n;
    int tar;
    cin >> tar;
    vector<int> num(n, 0);
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (num[0] <= tar)
        dp[0][num[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int nottake = dp[ind - 1][sum];
            int take = 0;
            if (num[ind] <= sum)
                take = dp[ind - 1][sum - num[ind]];
            dp[ind][sum] = nottake + take;
        }
    }
    cout << dp[n - 1][tar];
}

//***********SAME ABAOVE PROBLEM WITH , WHEN ARRAY HAVING ZERO AS ELEMENT***********
using namespace std;
int find(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (sum == 0 && num[0] == 0)
            return 2;
        if (sum == 0 || sum == num[0])
            return 1;
        return 0;
    }
    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int nottake = find(ind - 1, sum, num, dp);
    int take = 0;
    if (num[ind] <= sum)
        take = find(ind - 1, sum - num[ind], num, dp);
    return dp[ind][sum] = nottake + take;
}
int main()
{
    int n;
    cin >> n;
    int tar;
    cin >> tar;
    vector<int> v(n, 0);
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << find(n - 1, tar, v, dp);
}

// PROBLEM- L *******************************************************************************************

// Knapsack PROBLEM WITHOUT USING DP ONLY RECURRSION

// RECURSION
using namespace std;
int f(int ind, int w, vector<int> &wt, vector<int> &val)
{
    if (ind == 0)
    {
        if (wt[0] <= w)
            return val[0];
        return 0;
    }
    int nottake = 0 + f(ind - 1, w, wt, val);
    int take = INT_MIN;
    if (wt[ind] <= w)
        take = val[ind] + f(ind - 1, w - wt[ind], wt, val);
    return max(take, nottake);
}

int main()
{
    int n;
    cin >> n;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    vector<int> value(n, 0);
    for (int i = 0; i < n; i++)
        cin >> value[i];
    int maxweight;
    cin >> maxweight;
    cout << f(n - 1, maxweight, weight, value);
}

// SAME ABOVE PROBLEM WITH DP(N)
using namespace std;
int f(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= w)
            return val[0];
        return 0;
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int nottake = 0 + f(ind - 1, w, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= w)
        take = val[ind] + f(ind - 1, w - wt[ind], wt, val, dp);
    return dp[ind][w] = max(take, nottake);
}

int main()
{
    int n;
    cin >> n;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    vector<int> value(n, 0);
    for (int i = 0; i < n; i++)
        cin >> value[i];
    int maxweight;
    cin >> maxweight;
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, -1));
    cout << f(n - 1, maxweight, weight, value, dp);
}

// SAME ABOVE PROBLEM WITH FOR LOOP WITHOUT SPACE REDUCING
int main()
{
    int n;
    cin >> n;
    vector<int> wt(n, 0);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int maxweight;
    cin >> maxweight;
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, 0));

    for (int w = wt[0]; w <= maxweight; w++)
        dp[0][w] = val[0];
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= maxweight; w++)
        {
            int nottake = 0 + dp[ind - 1][w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + dp[ind - 1][w - wt[ind]];
            dp[ind][w] = max(take, nottake);
        }
    }

    cout << dp[n - 1][maxweight];
}

// FOR LOOP AND SPACE REDUCING THE AREA
int main()
{
    int n;
    cin >> n;
    vector<int> wt(n, 0);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int maxweight;
    cin >> maxweight;
    vector<int> prev(maxweight + 1, 0), cur(maxweight + 1, 0);
    for (int w = wt[0]; w <= maxweight; w++)
        prev[w] = val[0];
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= maxweight; w++)
        {
            int nottake = 0 + prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + prev[w - wt[ind]];
            cur[w] = max(take, nottake);
        }
        prev = cur;
    }

    cout << prev[maxweight];
}

// SPACE REDUCING TWICE TIMES WITH DP(N)
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> wt(n, 0);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int maxweight;
    cin >> maxweight;
    vector<int> prev(maxweight + 1, 0);
    for (int w = wt[0]; w <= maxweight; w++)
        prev[w] = val[0];
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = maxweight; w >= 0; w--)
        {
            int nottake = 0 + prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + prev[w - wt[ind]];
            prev[w] = max(take, nottake);
        }
    }

    cout << prev[maxweight];
}

// PROBLEM- M *******************************************************************************************

// Minimum Coins written by me
using namespace std;
int finder1(int ind, int w, vector<int> &wt)
{
    if (ind == 0)
    {
        if (w % wt[0] == 0)
            return w / wt[0];
        return 100000000;
    }
    int nottake = 0 + finder1(ind - 1, w, wt);
    int take = INT_MAX;
    if (w % wt[ind] >= 0 && w - wt[ind] >= 0)
        take = w / wt[ind] + finder1(ind - 1, w - ((w / wt[ind]) * wt[ind]), wt);
    return min(take, nottake);
}

int main()
{
    int n;
    cin >> n;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    sort(weight.begin(), weight.end());
    int maxweight;
    cin >> maxweight;
    int a = finder1(n - 1, maxweight, weight);
    if (a >= 10000000)
        cout << -1 << endl;
    else
        cout << a << endl;
    // cout<<f(n-1,maxweight,weight,dp);
}

// WITHOUT DP(N) SAME ABOVE PROBLEM
using namespace std;
int finder1(int ind, int w, vector<int> &wt)
{
    if (ind == 0)
    {
        if (w % wt[0] == 0)
            return w / wt[0];
        return 10000000;
    }
    int nottake = 0 + finder1(ind - 1, w, wt);
    int take = INT_MAX;
    if (w >= wt[ind])
        take = 1 + finder1(ind, w - wt[ind], wt);
    return min(take, nottake);
}

int main()
{
    int n;
    cin >> n;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    sort(weight.begin(), weight.end());
    int maxweight;
    cin >> maxweight;
    int a = finder1(n - 1, maxweight, weight);
    if (a >= 10000000)
        cout << -1 << endl;
    else
        cout << a << endl;
    // cout<<f(n-1,maxweight,weight,dp);
}

// SAME PROBLEM WITH DP(N)
using namespace std;
int finder1(int ind, int w, vector<int> &wt, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (w % wt[0] == 0)
            return w / wt[0];
        return 10000000;
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int nottake = 0 + finder1(ind - 1, w, wt, dp);
    int take = INT_MAX;
    if (w >= wt[ind])
        take = 1 + finder1(ind, w - wt[ind], wt, dp);
    return dp[ind][w] = min(take, nottake);
}

int main()
{
    int n;
    cin >> n;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    sort(weight.begin(), weight.end());
    int maxweight;
    cin >> maxweight;
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, -1));
    int a = finder1(n - 1, maxweight, weight, dp);
    if (a >= 10000000)
        cout << -1 << endl;
    else
        cout << a << endl;
    // cout<<f(n-1,maxweight,weight,dp);
}

// USING THE LOOP FOR THE SAME PROBLEM , WITH DP(N) ,WITHOUT SPACE REDUCING

// PROBLEM- M PSRT(2) *******************************************************************************************

// Coin Change 2 | Infinite Supply Problems

// ONLY RECURSION
using namespace std;
int finder1(int ind, int w, vector<int> &wt)
{
    if (ind == 0)
    {
        return w % wt[0] == 0;
    }
    int nottake = 0 + finder1(ind - 1, w, wt);
    int take = 0;
    if (w >= wt[ind])
        take = finder1(ind, w - wt[ind], wt);
    return take + nottake;
}
int main()
{
    int n;
    cin >> n;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    sort(weight.begin(), weight.end());
    int maxweight;
    cin >> maxweight;
    int a = finder1(n - 1, maxweight, weight);
    cout << a << endl;
}

// WITH DP(N)
using namespace std;
int finder1(int ind, int w, vector<int> &wt, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return w % wt[0] == 0;
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int nottake = 0 + finder1(ind - 1, w, wt, dp);
    int take = 0;
    if (w >= wt[ind])
        take = finder1(ind, w - wt[ind], wt, dp);
    return dp[ind][w] = take + nottake;
}
int main()
{
    int n;
    cin >> n;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    sort(weight.begin(), weight.end());
    int maxweight;
    cin >> maxweight;
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, -1));
    int a = finder1(n - 1, maxweight, weight, dp);
    cout << a << endl;
}

// SAME PROBLEM WITH FOR LOOP  without reducing he space  and with dp(n)
int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int value;
    cin >> value;
    vector<vector<int>> dp(n, vector<int>(value + 1, 0));
    for (int t = 0; t <= value; t++)
    {
        dp[0][t] = t % a[0] == 0;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int t = 0; t <= value; t++)
        {
            int nottake = dp[ind - 1][t];
            int take = 0;
            if (a[ind] <= t)
                take = dp[ind][t - a[ind]];
            dp[ind][t] = take + nottake;
        }
    }
    cout << dp[n - 1][value];
}

// WITH FOR LOOP AND REDUCED SPACE ANS DP(N)
int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int value;
    cin >> value;
    vector<int> prev(value + 1, 0), cur(value + 1, 0);
    for (int t = 0; t <= value; t++)
    {
        prev[t] = t % a[0] == 0;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int t = 0; t <= value; t++)
        {
            int nottake = prev[t];
            int take = 0;
            if (a[ind] <= t)
                take = cur[t - a[ind]];
            cur[t] = take + nottake;
        }
        prev = cur;
    }
    cout << prev[value];
}

// PROBLEM- N *******************************************************************************************

// Unbounded Knapsack | 1-D Array Space Optimised Approach

// WITHOUT DP(N) SIMPLE RECURRSION
using namespace std;
int f(int ind, int w, vector<int> &wt, vector<int> &val)
{
    if (ind == 0)
    {
        return (w / wt[0]) * val[0];
    }
    int nottake = 0 + f(ind - 1, w, wt, val);
    int take = INT_MIN;
    if (wt[ind] <= w)
        take = val[ind] + f(ind, w - wt[ind], wt, val);
    return max(take, nottake);
}
int main()
{
    int n;
    cin >> n;
    vector<int> wt(n, 0);
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int maxw;
    cin >> maxw;
    cout << f(n - 1, maxw, wt, val);
}

// SAME PROBLEM WITH DP(N)
using namespace std;
int f(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (w / wt[0]) * val[0];
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int nottake = 0 + f(ind - 1, w, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= w)
        take = val[ind] + f(ind, w - wt[ind], wt, val, dp);
    return dp[ind][w] = max(take, nottake);
}
int main()
{
    int n;
    cin >> n;
    vector<int> wt(n, 0);
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int maxw;
    cin >> maxw;
    vector<vector<int>> dp(n, vector<int>(maxw + 1, -1));
    cout << f(n - 1, maxw, wt, val, dp);
}

// SAME ABOVE PROBLEM WITH FOR LOOP WITH REDUCING THE SPACE WITH DP(N)
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> wt(n, 0);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int maxweight;
    cin >> maxweight;
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, 0));

    for (int w = wt[0]; w <= maxweight; w++)
        dp[0][w] = (w / wt[0]) * val[0];
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= maxweight; w++)
        {
            int nottake = 0 + dp[ind - 1][w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + dp[ind][w - wt[ind]];
            dp[ind][w] = max(take, nottake);
        }
    }

    cout << dp[n - 1][maxweight];
}

// SAME ABOVE PROBLEM WITH REDUCED SPACE

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> wt(n, 0);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int maxweight;
    cin >> maxweight;
    vector<int> prev(maxweight + 1, 0), cur(maxweight + 1, 0);
    for (int w = wt[0]; w <= maxweight; w++)
        prev[w] = (w / wt[0]) * val[0];
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= maxweight; w++)
        {
            int nottake = 0 + prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + cur[w - wt[ind]];
            cur[w] = max(take, nottake);
        }
        prev = cur;
    }

    cout << prev[maxweight];
}

// SAME ABOVE PROBLEM WITH TWICE SPACE REDUCING
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> wt(n, 0);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int maxweight;
    cin >> maxweight;
    vector<int> prev(maxweight + 1, 0);
    for (int w = wt[0]; w <= maxweight; w++)
        prev[w] = (w / wt[0]) * val[0];
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= maxweight; w++)
        {
            int nottake = 0 + prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + prev[w - wt[ind]];
            prev[w] = max(take, nottake);
        }
    }
    cout << prev[maxweight];
}

// PROBLEM- O *******************************************************************************************
// ROD CUTTING PROBLEM BY ME

// RECURRSION
using namespace std;
int f(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (w / wt[0]) * val[0];
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int nottake = 0 + f(ind - 1, w, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= w)
        take = val[ind] + f(ind, w - wt[ind], wt, val, dp);
    return dp[ind][w] = max(take, nottake);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0), v2(n, 0);
    for (int i = 0; i < n; i++)
        v2[i] = i + 1;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << f(n - 1, n, v2, v, dp);
}

// SAME AS ABOVE PROBLEM WITH DP(N)
using namespace std;
int finder1(int ind, int w, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return w * val[0];
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int nottake = 0 + finder1(ind - 1, w, val, dp);
    int take = INT_MIN;
    int rodlength = ind + 1;
    if (rodlength <= w)
        take = val[ind] + finder1(ind, w - rodlength, val, dp);
    return dp[ind][w] = max(take, nottake);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << finder1(n - 1, n, v, dp);
}

// SAME PROBLEM WITH FOR LOOP AND DP(N)
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int N = 0; N < n; N++)
        dp[0][N] = N * val[0];
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= n; w++)
        {
            int nottake = 0 + dp[ind - 1][w];
            int take = INT_MIN;
            int rodlength = ind + 1;
            if (rodlength <= w)
                take = val[ind] + dp[ind][w - rodlength];
            dp[ind][w] = max(take, nottake);
        }
    }
    cout << dp[n - 1][n];
}

// SAME PROBLEM WITH DP(N) AND REDUCED SPACE
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    vector<int> prev(n + 1, 0), cur(n + 1, 0);
    for (int N = 0; N < n; N++)
        prev[N] = N * val[0];
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= n; w++)
        {
            int nottake = 0 + prev[w];
            int take = INT_MIN;
            int rodlength = ind + 1;
            if (rodlength <= w)
                take = val[ind] + cur[w - rodlength];
            cur[w] = max(take, nottake);
        }
        prev = cur;
    }
    cout << prev[n];
}

// Same problem with for loop and twice space reducing
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    vector<int> prev(n + 1, 0);
    for (int N = 0; N < n; N++)
        prev[N] = N * val[0];
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= n; w++)
        {
            int nottake = 0 + prev[w];
            int take = INT_MIN;
            int rodlength = ind + 1;
            if (rodlength <= w)
                take = val[ind] + prev[w - rodlength];
            prev[w] = max(take, nottake);
        }
    }
    cout << prev[n];
}

// PROBLEM- P *******************************************************************************************
//**************************************************************************************************************
//**************************************************************************************************************
//**************************************************************************************************************
//**************************************************************************************************************

// FINDING THE NUMBER OF COMMAN CHARACTER IN TWO DIFFERENT STRING
// USING DP(N)

using namespace std;
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        return dp[i][j] = 1 + f(i - 1, j - 1, s, t, dp);
    return dp[i][j] = max(f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp));
}
int main()
{
    string n, m;
    cin >> n >> m;
    int l1, l2;
    l1 = n.length();
    l2 = m.length();
    vector<vector<int>> dp(l1, vector<int>(l2, -1));
    cout << f(l1 - 1, l2 - 1, n, m, dp);
}

// same above PROBLEM WITH FOR LOOP

using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    int n, m;
    n = s.length();
    m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m];
}

// SAME ABOVE PROBLEM WITH SPACE REDUCED FORM
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    int n, m;
    n = s.length();
    m = t.length();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int j = 0; j <= m; j++)
        prev[j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    cout << prev[m];
}

// PROBLEM- Q *******************************************************************************************

// LONGEST COMMON SUBSEQUENCE IN TWO STRING BUT IN INCREASING WAY

void lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int len = dp[n][m];
    string ans = "";
    for (int i = 0; i < len; i++)
        ans += '$';
    int index = len - 1;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans[index] = s[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    lcs(s1, s2);
}

// PROBLEM- R *******************************************************************************************

// LONGEST COMMON SUBSTRING IN TWO STRING answer is integer
using namespace std;

void lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    int anss = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                anss = max(anss, dp[i][j]);
            }
            else
                dp[i][j] = 0;
            // max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << anss;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    lcs(s1, s2);
}

// PROBLEM- R PART-2 *******************************************************************************************

// LONGEST PALINDROMIC SEQUENCE IN A STRING IN INCEASING WAY

// SAME ABOVE CONCEPT WITH ONE STRING “S” AND ANOTHER STRING IS IT’S “REVERSE”…………

// PROBLEM- R PART-3 *******************************************************************************************

// MINIMUM OF STRING YOU SHOULD ADD TO CONVERT INTO PALINDRON STRING ==  TOTAL LENGTH – (LCS)

// PROBLEM- R PART-4 *******************************************************************************************

// Minimum INSERTION OR DELETION TO CONVERT “A” STRING TO “B” STRING IS === LENGTH (A) + LENGTH(B) – 2*(LCS)

// PROBLEM- R PART-5 *******************************************************************************************

// GIVEN TWO STRING , NOW YOU HAVE TO CREATE A NEW STRING SUCH THST IT CONTAIN MINIMUM NUMBER OF CHARACTER , AND NEW STRING IS IN INCREASING ORDER  {MINIMUM LENGTH} == {LENGTH(A)+LENGTH(B)-(LCS)}

using namespace std;

void lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans += s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += s[i - 1];
            i--;
        }
        else
        {
            ans += t[j - 1];
            j--;
        }
    }
    while (i > 0)
    {
        ans += s[i - 1];
        i--;
    }
    while (j--)
    {
        ans += t[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    lcs(s1, s2);
}

// PROBLEM- S *******************************************************************************************

// Distinct Subsequences
// WITH RECURRSION AND WITHOUT DP(N)

using namespace std;
int f(int i, int j, string s, string t)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (s[i] == t[j])
        return f(i - 1, j - 1, s, t) + f(i - 1, j, s, t);
    return f(i - 1, j, s, t);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int a, b;
    a = s1.length();
    b = s2.length();
    cout << f(a - 1, b - 1, s1, s2);
}

// SAME ABOVE PROBLEM WITH DP(N)
using namespace std;
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
    return dp[i][j] = f(i - 1, j, s, t, dp);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int a, b;
    a = s1.length();
    b = s2.length();
    vector<vector<int>> dp(a, vector<int>(b, -1));
    cout << f(a - 1, b - 1, s1, s2, dp);
}

//***************************************Same above with slight changes
// DP
using namespace std;
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
    return dp[i][j] = f(i - 1, j, s, t, dp);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int a, b;
    a = s1.length();
    b = s2.length();
    vector<vector<int>> dp(a, vector<int>(b, -1));
    cout << f(a - 1, b - 1, s1, s2, dp);
}

// Same above problem with FOR LOOP , reduced space form
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n, m;
    n = s1.length();
    m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][m];
}

// SPACE REDUCING TWICE A TIME (in two array formate)
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n, m;
    n = s1.length();
    m = s2.length();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    prev[0] = 1;
    cur[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                cur[j] = prev[j - 1] + prev[j];
            else
                cur[j] = prev[j];
        }
        prev = cur;
    }
    cout << prev[m];
}

// SPACE REDUCING TRICE A TIME ; (IN ONE “D” , ONE ARRAY)
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n, m;
    n = s1.length();
    m = s2.length();
    vector<int> prev(m + 1, 0);
    prev[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (s1[i - 1] == s2[j - 1])
                prev[j] = prev[j - 1] + prev[j];
        }
    }
    cout << prev[m];
}

// PROBLEM- T *******************************************************************************************

// EDIT DISTANCE (INSERT ; DELETE ; REPLACE ) MINIMUM NUMBER OF TIMES WITH DP(N)

// DP
using namespace std;

// METHOD 1
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i - 1] == t[j - 1])
        return dp[i][j] = f(i - 1, j - 1, s, t, dp);
    return dp[i][j] = 1 + min({f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp), f(i - 1, j - 1, s, t, dp)});
}
int minDistance(string s1, string s2)
{
    int a, b;
    a = s1.length();
    b = s2.length();
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
    return f(a, b, s1, s2, dp);
}

// METHOD 2
int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
    return dp[i][j] = 1 + min(f(i - 1, j, s1, s2, dp), min(f(i, j - 1, s1, s2, dp), f(i - 1, j - 1, s1, s2, dp)));
} // DELETE ; INSERT ; REPLACE
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n, m;
    n = s1.length();
    m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << f(n - 1, m - 1, s1, s2, dp);
}

// same above problem with one addition ; dp(n);removing negative index
using namespace std;

int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
    return dp[i][j] = 1 + min(f(i - 1, j, s1, s2, dp), min(f(i, j - 1, s1, s2, dp), f(i - 1, j - 1, s1, s2, dp)));
} // DELETE ; INSERT ; REPLACE
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n, m;
    n = s1.length();
    m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << f(n, m, s1, s2, dp);
}

// WRITTEN THE SAME ABOVE PROBLEM WITH DFOR LOOP AND DP(n)
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n, m;
    n = s1.length();
    m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j >= m; j++)
        dp[0][j] = j;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }
    cout << dp[n][m];
}

// AND SPACE REDUCING INTO SINGLE VECTOR AND FOR LOOP
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n, m;
    n = s1.length();
    m = s2.length();
    vector<int> prev(m + 1, 0), cur(n + 1, 0);
    for (int j = 0; j >= m; j++)
        prev[j] = j;
    for (int i = 1; i <= n; i++)
    {
        cur[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                cur[j] = prev[j - 1];
            else
                cur[j] = 1 + min(prev[j], min(cur[j - 1], prev[j - 1]));
        }
        prev = cur;
    }
    cout << prev[m];
}
//   PROBLEM -U ********************************************************************************************************************************

// WILD MATCHING {matching two string A and B such that something missing in A is sme as complete in B} { asdf*fgh? :: asdfrtyuifghk}  SOLVING USING DP(N)

// RECURSION
using namespace std;

int f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
    {
        for (int ii = 0; ii <= i; ii++)
        {
            if (pattern[ii] != '*')
                return false;
        }
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (pattern[i] == text[j] || pattern[i] == '?')
        return dp[i][j] = f(i - 1, j - 1, pattern, text, dp);
    if (pattern[i] == '*')
        return dp[i][j] = f(i - 1, j, pattern, text, dp) | f(i, j - 1, pattern, text, dp);
    return dp[i][j] = false;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int m, n;
    n = s1.length();
    m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << f(n - 1, m - 1, s1, s2, dp);
}

// SAME SBOVE PROBLEM WITH FOR LOOP AND DP(N)
int main()
{
    string pattern, text;
    cin >> pattern >> text;
    int m, n;
    n = pattern.length();
    m = text.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
        dp[0][j] = false;
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
                flag = false;
        }
        dp[i][0] = flag;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (pattern[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    cout << dp[n][m];
}

// SAME PROBLEM WITH FOR LOOP AND REDUCED IN TWO VECTOR FORM
int main()
{
    string pattern, text;
    cin >> pattern >> text;
    int m, n;
    n = pattern.length();
    m = text.length();
    vector<bool> prev(m + 1, false), cur(m + 1, false);
    prev[0] = true;
    for (int j = 1; j <= m; j++)
        prev[j] = false;
    for (int i = 1; i <= n; i++)
    {

        bool flag = true;
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
                flag = false;
            break;
        }
        cur[0] = flag;

        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                cur[j] = prev[j - 1];
            else if (pattern[i - 1] == '*')
                cur[j] = prev[j] | cur[j - 1];
            else
                cur[j] = false;
        }
        prev = cur;
    }
    cout << prev[m];
}

// PROBLEM- V*****************************************************************************************************************************************
//************************************************************************************************************************************************************
//************************************************************************************************************************************************************
//************************************************************************************************************************************************************

// 1.	(A) LONGEST INCREASING SUBSEQUENCE (COUNTING THE NUMBER) using recurrsion
using namespace std;
int f(int ind, int prev_ind, vector<int> v, int n)
{
    if (ind == n)
        return 0;
    int len = 0 + f(ind + 1, prev_ind, v, n);
    if (prev_ind == -1 || v[ind] > v[prev_ind])
        len = max(len, 1 + f(ind + 1, ind, v, n));
    return len;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << f(0, -1, v, n);
}
// 1 . (B) same above problem using dp(n)
using namespace std;
int checker(int ind, int prev_ind, vector<int> v, int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];
    int len = 0 + checker(ind + 1, prev_ind, v, n, dp);
    if (prev_ind == -1 || v[ind] > v[prev_ind])
        len = max(len, 1 + checker(ind + 1, ind, v, n, dp));
    return dp[ind][prev_ind + 1] = len;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << checker(0, -1, v, n, dp);
}
// 1 . (C)   SAME ABOVE PROBLEM USING FOR LOOP AND DP(N)
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = 0 + dp[ind + 1][prev_ind + 1];
            if (prev_ind == -1 || v[ind] > v[prev_ind])
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            dp[ind][prev_ind + 1] = len;
        }
    }
    cout << dp[0][0];
}
// 1 . (D)  same above problem using twice space reducing
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<int> next(n + 1, 0), cur(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = 0 + next[prev_ind + 1];
            if (prev_ind == -1 || v[ind] > v[prev_ind])
                len = max(len, 1 + next[ind + 1]);
            cur[prev_ind + 1] = len;
        }
        next = cur;
    }
    cout << cur[0];
}
// 1 .  (E )  SAME ABOVE PROBLEM WITH FOR LOOP WITH SPACE-N  ;; AN TIME- (N^2)
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (v[prev] < v[i])
                dp[i] = max(dp[i], 1 + dp[prev]);
        }
        maxi = max(maxi, dp[i]);
    }
    cout << maxi;
}
// 1 . ( F ) SAME ABOVE PROBLEM ::  PRINT ALL ELEMENT ALSO

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int lastindex = 0;
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (v[prev] < v[i] && (1 + dp[prev]) > dp[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastindex = i;
        }
    }
    vector<int> temp;
    temp.push_back(v[lastindex]);
    while (hash[lastindex] != lastindex)
    {
        lastindex = hash[lastindex];
        temp.push_back(v[lastindex]);
    }
    reverse(temp.begin(), temp.end());

    for (auto it : temp)
        cout << it << " ";
    cout << endl;

    cout << maxi;
}

// 1 . ( G)  SAME ABOVE PROBLEM USING DP(N) and binary search

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> temp(n, 0);
    temp.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (v[i] > temp.back())
            temp.push_back(v[i]);
        else
        {
            int ind = 0;
            // ind= lower_bound(temp,v[i]);
            temp[ind] = v[i];
        }
    }
    cout << temp.size();
}

// PROBLEM -W ********************************************************************************************************************************

// 2.	DP(44)  LARGEST DIVISIBLE SUBSET
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int lastindex = 0;
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (v[i] % v[prev] == 0 && (1 + dp[prev]) > dp[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastindex = i;
        }
    }
    vector<int> temp;
    temp.push_back(v[lastindex]);
    while (hash[lastindex] != lastindex)
    {
        lastindex = hash[lastindex];
        temp.push_back(v[lastindex]);
    }
    reverse(temp.begin(), temp.end());

    for (auto it : temp)
        cout << it << " ";
    cout << endl;

    cout << maxi;
}

// PROBLEM -X ********************************************************************************************************************************

// 3.	LONGEST STRING CHAIN DP(N)

using namespace std;

bool checkpossible(string &s1, string &s2)
{
    if (s1.length() != s2.length() + 1)
        return false;
    int first = 0;
    int second = 0;
    while (first < s1.length())
    {
        if (second < s2.length() && s1.at(first) == s2.at(second))
        {
            first++;
            second++;
        }
        else
        {
            first++;
        }
    }
    if (first == s1.length() && second == s2.length())
        return true;
    else
        return false;
}
bool comp(string &s1, string &s2)
{
    return s1.length() < s2.length();
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> dp(n + 1, 1);
    int maxi = 1;
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (checkpossible(v[i], v[prev]) && (1 + dp[prev]) > dp[i])
            {
                dp[i] = 1 + dp[prev];
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }
    cout << maxi;
}

// PROBLEM -Y ********************************************************************************************************************************

// 4.	NUMBER OF LONGEST INCREASING SUBSEQUENCE ( MEANS IT HAVE TO FIRST INCRESING THE MAY BE DECREASING AND VICE VERSA )

using namespace std;
int longestbitonicsequence(vector<int> &v, int n)
{
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (v[prev] < v[i] && (1 + dp1[prev]) > dp1[i])
            {
                dp1[i] = 1 + dp1[prev];
            }
        }
    }
    vector<int> dp2(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (v[prev] < v[i] && (1 + dp2[prev]) > dp2[i])
            {
                dp2[i] = 1 + dp2[prev];
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    return maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << longestbitonicsequence(v, n);
}

// PROBLEM -Z ********************************************************************************************************************************

// 5.	NUMBER OF LONGEST INCREASING SUBSEQUENCE

using namespace std;
int longest(vector<int> &v, int n)
{
    vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (v[prev] < v[i] && (1 + dp[prev]) > dp[i])
            {
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev];
            }
            else if (v[prev] < v[i] && (1 + dp[prev]) == dp[i])
            {
                cnt[i] += cnt[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    int nos = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            nos += cnt[i];
    }
    return nos;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << longest(v, n);
}

//***********************************STOCK BASE PROBLEM ******************************************************************************************************
//*****************************************************************************************************************************************
//*****************************************************************************************************************************************
//*****************************************************************************************************************************************

// 1.	BEST TIME TO BUY NAD SELL A STOCK WITH FOR LOOP (note buy one’s and sell one’s)

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> price(n, 0);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    int mini = price[0];
    int maxprofit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = price[i] - mini;
        maxprofit = max(maxprofit, cost);
        mini = min(mini, price[i]);
    }
    cout << maxprofit;
}

// 2.	(A)  BUY AND SELL STOCK AS MANY TIMES AS POSSIBLE ANS THEN FINDING THE MAXIMUM PROFIT WITHOUT ONLY RECURRISION……………..

long finder(int ind, int buy, vector<int> values, int n)
{
    if (ind == n)
        return 0;
    long profit = 0;
    if (buy)
    {
        profit = max(-values[ind] + finder(ind + 1, 0, values, n), 0 + finder(ind + 1, 1, values, n));
    }
    else
    {
        profit = max(values[ind] + finder(ind + 1, 1, values, n), 0 + finder(ind + 1, 0, values, n));
    }
    return profit;
}
int main()
{
    int n;
    cin >> n;
    vector<int> price(n, 0);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    cout << finder(0, 1, price, n);
}

// (B)  SAME ABOVE PROBLEM WITH DP(N)

long long f(int ind, int buy, vector<int> values, int n, vector<vector<int>> dp)
{
    if (ind == n)
        return 0;
    long profit = 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
    {
        profit = max(-values[ind] + f(ind + 1, 0, values, n, dp), 0 + f(ind + 1, 1, values, n, dp));
    }
    else
    {
        profit = max(values[ind] + f(ind + 1, 1, values, n, dp), 0 + f(ind + 1, 0, values, n, dp));
    }
    return dp[ind][buy] = profit;
}
int main()
{
    int n;
    cin >> n;
    vector<int> price(n, 0);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << f(0, 1, price, n, dp);
}

//(C)  SAME ABOVE PROBLEM WITH FOR LOOP AND DP(N)

int main()
{
    int n;
    cin >> n;
    vector<int> values(n, 0);
    for (int i = 0; i < n; i++)
        cin >> values[i];
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;
            if (buy)
            {
                profit = max(-values[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            }
            else
            {
                profit = max(values[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    cout << dp[0][1] << endl;
}

//( D ) EXTRA SPACE REDUCING INTO TWO ARRAY

int main()
{
    int n;
    cin >> n;
    vector<int> values(n, 0);
    for (int i = 0; i < n; i++)
        cin >> values[i];
    vector<long> ahead(2, 0), cur(2, 0);
    ahead[0] = 0;
    ahead[1] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;
            if (buy)
            {
                profit = max(-values[ind] + ahead[0], ahead[1]);
            }
            else
            {
                profit = max(values[ind] + ahead[1], 0 + ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }
    cout << ahead[1] << endl;
}

// 3.	Similar above problem with some boundary condition with only recursion

long f(int ind, int buy, int cap, vector<int> values, int n)
{
    if (ind == n || cap == 0)
        return 0;
    if (buy)
        return max(-values[ind] + f(ind + 1, 0, cap, values, n), 0 + f(ind + 1, 1, cap, values, n));
    else
        return max(values[ind] + f(ind + 1, 1, cap - 1, values, n), 0 + f(ind + 1, 0, cap, values, n));
}
int main()
{
    int n;
    cin >> n;
    vector<int> values(n, 0);
    for (int i = 0; i < n; i++)
        cin >> values[i];
    int cap = 2;
    cout << f(0, 1, cap, values, n);
}

// 3 . (B) SAME ABOVE PROBLEM WITH DP(N)

long f(int ind, int buy, int cap, vector<int> values, int n, vector<vector<vector<int>>> &dp)
{
    if (ind == n || cap == 0)
        return 0;
    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
    if (buy)
        return dp[ind][buy][cap] = max(-values[ind] + f(ind + 1, 0, cap, values, n, dp), 0 + f(ind + 1, 1, cap, values, n, dp));
    else
        return dp[ind][buy][cap] = max(values[ind] + f(ind + 1, 1, cap - 1, values, n, dp), 0 + f(ind + 1, 0, cap, values, n, dp));
}
int main()
{
    int n;
    cin >> n;
    vector<int> values(n, 0);
    for (int i = 0; i < n; i++)
        cin >> values[i];
    int cap = 2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    cout << f(0, 1, cap, values, n, dp);
}

// 3 . ( c )  SAME ABOVE PROBLEM WITH FOR LOOP

int main()
{
    int n;
    cin >> n;
    vector<int> values(n, 0);
    for (int i = 0; i < n; i++)
        cin >> values[i];
    int cap = 2;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                    dp[ind][buy][cap] = max(-values[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
                else
                    dp[ind][buy][cap] = max(values[ind] + dp[ind + 1][1][cap - 1], 0 + dp[ind + 1][0][cap]);
            }
        }
    }
    cout << dp[0][1][2];
}

// 3  . (D)   SAME ABOVE PROBLEM WITH  TWO VECTOR FORMATE

int main()
{
    int n;
    cin >> n;
    vector<int> values(n, 0);
    for (int i = 0; i < n; i++)
        cin >> values[i];
    int cap = 2;
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                    cur[buy][cap] = max(-values[ind] + after[0][cap], 0 + after[1][cap]);
                else
                    cur[buy][cap] = max(values[ind] + after[1][cap - 1], 0 + after[0][cap]);
            }
        }
        after = cur;
    }
    cout << after[1][2];
}

// 4.	Same similar type of problem with “k th”  choose you get………….

int main()
{
    int n;
    cin >> n;
    vector<int> values(n, 0);
    for (int i = 0; i < n; i++)
        cin >> values[i];
    int k;
    cin >> k;
    vector<vector<int>> after(2, vector<int>(k + 1, 0));
    vector<vector<int>> cur(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                if (buy)
                    cur[buy][cap] = max(-values[ind] + after[0][cap], 0 + after[1][cap]);
                else
                    cur[buy][cap] = max(values[ind] + after[1][cap - 1], 0 + after[0][cap]);
            }
        }
        after = cur;
    }
    cout << after[1][k];
}

// 5.	SAME ABOVE PROBLEM WITH , ONE CONDITION THAT WE CANNOT BUY JUST AFTER THE SELL

long long f(int ind, int buy, vector<int> values, int n, vector<vector<int>> dp)
{
    if (ind >= n)
        return 0;
    long profit = 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
    {
        profit = max(-values[ind] + f(ind + 1, 0, values, n, dp), 0 + f(ind + 1, 1, values, n, dp));
    }
    else
    {
        profit = max(values[ind] + f(ind + 2, 1, values, n, dp), 0 + f(ind + 1, 0, values, n, dp));
    }
    return dp[ind][buy] = profit;
}
int main()
{
    int n;
    cin >> n;
    vector<int> price(n, 0);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << f(0, 1, price, n, dp);
}

// 6.	SAME AS ABOVE PROBLEM WITH TRANSACTION FEE

using namespace std;
int fee = 0;
long long f(int ind, int buy, vector<int> values, int n, vector<vector<int>> dp)
{
    if (ind >= n)
        return 0;
    long profit = 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
    {
        profit = max(-values[ind] + f(ind + 1, 0, values, n, dp), 0 + f(ind + 1, 1, values, n, dp));
    }
    else
    {
        profit = max(values[ind] - fee + f(ind + 2, 1, values, n, dp), 0 + f(ind + 1, 0, values, n, dp));
    }
    return dp[ind][buy] = profit;
}
int main()
{
    int n;
    cin >> n;
    vector<int> price(n, 0);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    fee;
    cin >> fee;
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << f(0, 1, price, n, dp);
}

//***************************************************************************************************************
//***************************************************************************************************************
//***************************************************************************************************************
//***************************************************************************************************************
//***************************************************************************************************************

// 1.	(A)  Lecture (48  Matrix Chain Multiplication | MCM)    	WITH ONLY RECURSION

using namespace std;
int finder(int i, int j, vector<int> &arr)
{
    if (i == j)
        return 0;
    int mini = 1000000;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + finder(i, k, arr) + finder(k + 1, j, arr);
        if (steps < mini)
            mini = steps;
    }
    return mini;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << finder(1, n - 1, arr);
}
// 1.	(b) SAME ABOVE PROBLEM WITH DP(N)
using namespace std;
int finder(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1000000;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + finder(i, k, arr, dp) + finder(k + 1, j, arr, dp);
        if (steps < mini)
            mini = steps;
    }
    return dp[i][j] = mini;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << finder(1, n - 1, arr, dp);
}
// 1.	( c)  SAME ABOVE PROBLEM WITH FOR LOOP

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 10000000;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if (steps < mini)
                    mini = steps;
            }
            dp[i][j] = mini;
        }
    }
    cout << dp[1][n - 1];
}
// 2.	(A) LECTURE (50)  WITH RECURRSION { MINIMUM COST TO CUT THE STICK}

using namespace std;
int finder(int i, int j, vector<int> &cuts)
{
    if (i > j)
        return 0;
    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + finder(i, ind - 1, cuts) + finder(ind + 1, j, cuts);
        mini = min(mini, cost);
    }
    return mini;
}
int main()
{
    int n;
    cin >> n;
    int c;
    cin >> c;
    vector<int> cuts(n, 0);
    for (int i = 0; i < n; i++)
        cin >> cuts[i];
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    cout << finder(1, c, cuts);
}

// 2.(B) SAME ABOVE PROBLEM WITH DP(N)
using namespace std;
int finder(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + finder(i, ind - 1, cuts, dp) + finder(ind + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int main()
{
    int n;
    cin >> n;
    int c;
    cin >> c;
    vector<int> cuts(n, 0);
    for (int i = 0; i < n; i++)
        cin >> cuts[i];
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    cout << finder(1, c, cuts, dp);
}
// 2.(C) SAME ABOVE PROBLEM WITH FOR LOOP
int main()
{
    int n;
    cin >> n;
    int c;
    cin >> c;
    vector<int> cuts(n, 0);
    for (int i = 0; i < n; i++)
        cin >> cuts[i];
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue;
            int mini = INT_MAX;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    cout << dp[1][c];
}
// 3.	(a) LECTURE (52) BURST BALLON ,,, WITH RECURRSION

using namespace std;
int finder(int i, int j, vector<int> &a)
{
    if (i > j)
        return 0;
    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = a[i - 1] * a[ind] * a[j + 1] + finder(i, ind - 1, a) + finder(ind + 1, j, a);
        maxi = max(maxi, cost);
    }
    return maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    a.push_back(1);
    a.insert(a.begin(), 1);
    cout << finder(1, n, a);
}
// 3.(B) SAME ABOVE PROBLEM WITH DP(N)
using namespace std;
int finder(int i, int j, vector<int> &a, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    int maxi = INT_MIN;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int ind = i; ind <= j; ind++)
    {
        int cost = a[i - 1] * a[ind] * a[j + 1] + finder(i, ind - 1, a, dp) + finder(ind + 1, j, a, dp);
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    a.push_back(1);
    a.insert(a.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << finder(1, n, a, dp);
}
// 3.(C) SAME ABOVE PROBLEM WITH FOR LOOP
int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    a.push_back(1);
    a.insert(a.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = a[i - 1] * a[ind] * a[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    cout << dp[1][n];
}
// 4.	(a)  LECTURE 52  (Evaluate Boolean Expression to True)

using namespace std;
int mod = 100000007;
long long f(int i, int j, int istrue, string &exp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (istrue)
        {
            return exp[i] == 'T';
        }
        else
        {
            return exp[i] == 'F';
        }
    }
    long long ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind++)
    {
        long long lt = f(i, ind - 1, 1, exp);
        long long lf = f(i, ind - 1, 0, exp);
        long long rt = f(ind + 1, j, 1, exp);
        long long rf = f(ind + 1, j, 0, exp);

        if (exp[ind] == '&')
        {
            if (istrue)
                ways = (ways + (rt * lt) % mod) % mod;
            else
                ways = (ways + (rt * lf) % mod + (rf & lt) % mod + (rf & lf) % mod) % mod;
        }
        else if (exp[ind] == '|')
        {
            if (istrue)
                ways = (ways + (lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
            else
                ways = (ways + (rf * lf) % mod) % mod;
        }
        else
        {
            ways = (ways + (rf * lf) % mod) % mod;
        }
    }
}
int main()
{
}
// 5.	(A) lecture 53, palindrion partion ,,,, with recursion

using namespace std;
bool ispal(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int f(int i, int n, string &str)
{
    if (i == n)
        return 0;
    int mincost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (ispal(i, j, str))
        {
            int cost = 1 + f(j + 1, n, str);
            mincost = min(mincost, cost);
        }
    }
    return mincost;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << f(0, n, s) - 1;
}
// 5.(b) same above problem with dp(n)
using namespace std;
bool ispal(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int f(int i, int n, string &str, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int mincost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (ispal(i, j, str))
        {
            int cost = 1 + f(j + 1, n, str, dp);
            mincost = min(mincost, cost);
        }
    }
    return dp[i] = mincost;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n, -1);
    cout << f(0, n, s, dp) - 1;
}
// 5.(c) SAME ABOV EPROBLEM WITH FOR LOOP
using namespace std;
bool ispal(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int mincost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (ispal(i, j, s))
            {
                int cost = 1 + dp[j + 1];
                mincost = min(mincost, cost);
            }
        }
        dp[i] = mincost;
    }
    cout << dp[0] - 1;
}
// 6.	(A) LECTURE 54 ;;; PARTITION OF ARRAY TO GET MAXIMUM SUM ;;;;  WITH RECURRSION

using namespace std;
int f(int ind, vector<int> &num, int k)
{
    int n = num.size();
    if (ind == n)
        return 0;
    int len = 0;
    int maxi = INT_MIN;
    int maxans = INT_MIN;
    for (int j = ind; j < min(ind + k, n); j++)
    {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, num, k);
        maxans = max(maxans, sum);
    }
    return maxans;
}
int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    cout << f(0, num, k);
}
// 6.(B) SAME ABOVE PROBLEM WITH DP(N)
using namespace std;
int f(int ind, vector<int> &num, int k, vector<int> &dp)
{
    int n = num.size();
    if (ind == n)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int len = 0;
    int maxi = INT_MIN;
    int maxans = INT_MIN;
    for (int j = ind; j < min(ind + k, n); j++)
    {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, num, k, dp);
        maxans = max(maxans, sum);
    }
    return dp[ind] = maxans;
}
int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    vector<int> dp(n, -1);
    cout << f(0, num, k, dp);
}
// 6.(c)  same above problem with for loop
int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    vector<int> dp(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        int len = 0;
        int maxi = INT_MIN;
        int maxans = INT_MIN;
        for (int j = ind; j < min(ind + k, n); j++)
        {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxans = max(maxans, sum);
        }
        dp[ind] = maxans;
    }
    cout << dp[0];
}
// 7.	LECTURE 55 .. (Maximum Rectangle Area with all 1's)
using namespace std;
int largestrectanglearea(vector<int> &histo)
{
    stack<int> st;
    int maxa = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxa = max(maxa, width * height);
        }
        st.push(i);
    }
    return maxa;
}
int maximalareaofsubmatrixofall(vector<vector<int>> &mat, int n, int m)
{
    int maxarea = 0;
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        }
        int area = largestrectanglearea(height);
        maxarea = max(area, maxarea);
    }
    return maxarea;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << maximalareaofsubmatrixofall(v, n, m);
}
// 8.	LECTURE 56… with error ( Count Square Submatrices with All Ones)
using namespace std;
int countsquares(int n, int m, vector<vector<int>> &arr)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
        dp[0][j] = arr[0][j];
    for (int i = 0; i < n; i++)
        dp[i][0] = arr[i][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum = sum + dp[i][j];
        }
    }
    return sum;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << countsquares(n, m, v);
}

// ######################################################################################################
//                             ####################################################
//                                       #############################
//                                                #############
//                                                    #####

// PROBLEM- 5

// Minimum cost to reach a point N from 0 with two different operations allowed

// Function to return minimum
// cost to reach destination
int minCost(int N, int P, int Q)
{
    // Initialize cost to 0
    int cost = 0;

    // going backwards until we
    // reach initial position
    while (N > 0)
    {

        if (N & 1)
        {
            cost += P;
            N--;
        }
        else
        {
            int temp = N / 2;

            // if 2*X jump is
            // better than X+1
            if (temp * P > Q)
                cost += Q;
            // if X+1 jump is better
            else
                cost += P * temp;

            N /= 2;
        }
    }

    // return cost
    return cost;
}

int main()
{
    int N = 9, P = 5, Q = 1;

    cout << minCost(N, P, Q);

    return 0;
}

// PROBLEM -7

// Optimal Strategy for a Game

// The recursive top down solution in is shown below

using namespace std;

vector<int> arr;
map<vector<int>, int> memo;
int n = arr.size();

// recursive top down memoized solution
int solve(int i, int j)
{
    if ((i > j) || (i >= n) || (j < 0))
        return 0;

    vector<int> k{i, j};
    if (memo[k] != 0)
        return memo[k];

    // if the user chooses ith coin, the opponent can choose
    // from i+1th or jth coin. if he chooses i+1th coin,
    // user is left with [i+2,j] range. if opp chooses jth
    // coin, then user is left with [i+1,j-1] range to
    // choose from. Also opponent tries to choose in such a
    // way that the user has minimum value left.
    int option1 = arr[i] + min(solve(i + 2, j), solve(i + 1, j - 1));

    // if user chooses jth coin, opponent can choose ith
    // coin or j-1th coin. if opp chooses ith coin,user can
    // choose in range [i+1,j-1]. if opp chooses j-1th coin,
    // user can choose in range [i,j-2].
    int option2 = arr[j] + min(solve(i + 1, j - 1), solve(i, j - 2));

    // since the user wants to get maximum money
    memo[k] = max(option1, option2);
    return memo[k];
}

int optimalStrategyOfGame()
{

    memo.clear();
    return solve(0, n - 1);
}

int main()
{
    arr.push_back(8);
    arr.push_back(15);
    arr.push_back(3);
    arr.push_back(7);
    n = arr.size();
    cout << optimalStrategyOfGame() << endl;

    arr.clear();
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    n = arr.size();
    cout << optimalStrategyOfGame() << endl;

    arr.clear();
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(10);
    n = arr.size();
    cout << optimalStrategyOfGame() << endl;
}

// The bottom up approach is shown below.

using namespace std;

// Returns optimal value possible
// that a player can collect from
// an array of coins of size n.
// Note than n must be even
int optimalStrategyOfGame(int *arr, int n)
{
    // Create a table to store
    // solutions of subproblems
    // int table[n][n];

    vector<vector<int>> table(n, vector<int>(n, 0));
    // Fill table using above
    // recursive formula. Note
    // that the table is filled
    // in diagonal fashion (similar
    // to http:// goo.gl/PQqoS),
    // from diagonal elements to
    // table[0][n-1] which is the result.
    for (int gap = 0; gap < n; ++gap)
    {
        for (int i = 0, j = gap; j < n; ++i, ++j)
        {
            // Here x is value of F(i+2, j),
            // y is F(i+1, j-1) and
            // z is F(i, j-2) in above recursive
            // formula
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1))
                        ? table[i + 1][j - 1]
                        : 0;
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0;

            table[i][j] = max(arr[i] + min(x, y),
                              arr[j] + min(y, z));
        }
    }

    return table[0][n - 1];
}

int main()
{
    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", optimalStrategyOfGame(arr1, n));

    int arr2[] = {2, 2, 2, 2};
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", optimalStrategyOfGame(arr2, n));

    int arr3[] = {20, 30, 2, 2, 2, 10};
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n", optimalStrategyOfGame(arr3, n));

    return 0;
}
