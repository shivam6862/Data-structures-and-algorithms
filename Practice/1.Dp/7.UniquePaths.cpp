#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int find(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = find(i - 1, j, dp);
        int up = find(i, j - 1, dp);
        return dp[i][j] = left + up;
    }
    int uniquePaths(int m, int n)
    {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return find(m-1,n-1,dp);
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// 3 7
// DP ARRAY
// 1 1 1 1 1 1 1
// 1 2 3 4 5 6 7
// 1 3 6 10 15 21 28

//
//
//
//
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[n - 1][m - 1];
    }
};

//    vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), 0));
//     for(int c = grid[0].size()-2; c >= 0; --c){
//         for(int r = 0; r < grid.size(); ++r ){
//             if(r - 1 >= 0 && grid[r][c] < grid[r-1][c+1])
//                 dp[r][c] = max(dp[r][c], 1 + dp[r-1][c+1]);
//             if( grid[r][c] < grid[r][c+1])
//                 dp[r][c] = max(dp[r][c], 1 + dp[r][c+1]);
//             if(r + 1 < grid.size() && grid[r][c] < grid[r+1][c+1])
//                 dp[r][c] = max(dp[r][c], 1 + dp[r+1][c+1]);
//             if(c == 0)ans = max(ans, dp[r][c]);
//         }
//     }
//     return ans;