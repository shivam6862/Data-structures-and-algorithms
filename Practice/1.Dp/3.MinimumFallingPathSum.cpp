// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// dp in a matrix filling the bottom most part and starting from last bootoom and fullfuil our need

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
            dp[n - 1][j] = matrix[n - 1][j];

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = matrix[i][j] + dp[i + 1][j];
                if (j - 1 >= 0)
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j - 1]);
                if (j + 1 < m)
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j + 1]);
            }
        }
        int answer = INT_MAX;
        for (int j = 0; j < m; j++)
            answer = min(answer, dp[0][j]);
        return answer;
    }
};

// matrix = [[2,1,3],[6,5,4],[7,8,9]]
//
// DP ARRAY
// 14 13 15
// 13 12 12
// 7 8 9
//
//

class Solution1
{
public:
    int find(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= v.size())
            return 99999;
        if (i == v.size() - 1)
            return v[i][j];
        if (dp[i][j] != -10000)
            return dp[i][j];
        int a = v[i][j] + find(i + 1, j + 1, v, dp);
        int b = v[i][j] + find(i + 1, j - 1, v, dp);
        int c = v[i][j] + find(i + 1, j, v, dp);
        return dp[i][j] = min(a, min(b, c));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int mini = 2000000;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -10000));
        for (int i = 0; i < matrix.size(); i++)
        {
            int a = find(0, i, matrix, dp);
            mini = min(mini, a);
        }
        for (auto it : dp)
        {
            for (auto i : it)
                cout << i << " ";
            cout << endl;
        }
        return mini;
    }
};
