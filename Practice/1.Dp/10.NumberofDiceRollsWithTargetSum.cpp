#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int finder(int n, int target, int i, vector<vector<int>> &dp)
    {
        if (n < 0)
            return 0;
        if (n == 0 && target == 0)
            return 1;
        if (dp[n][target] != -1)
            return dp[n][target];
        int take = 0;
        if (target > 0)
        {
            for (int j = 1; j <= i; j++)
            {
                if (target >= j)
                    take = (take + finder(n - 1, target - j, i, dp)) % 1000000007;
            }
        }
        return dp[n][target] = (take) % 1000000007;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        // if(target>900) return 0;
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return finder(n,target,k,dp);
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= target; ++j)
                for (int dice = 1; dice <= k; ++dice)
                    if (j >= dice)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - dice]) % 1000000007;
        return dp[n][target];
    }
};

//
//
//
//
//
//  CODESTUDIO PROBLEM
// int xorOrNot(int n, int k, vector<int>a)
// {
//     // Write you code here.
//     int x=k;
//     vector<vector<int>> dp(n, vector<int>(2));
//     dp[0][0] = 0;
//     dp[0][1] = 0;
//     for (int i = 1; i < n; i++) {
//         int diff_a = a[i]^x;
//         int diff_b = a[i-1] ^ x;
//         dp[i][0] = max(dp[i-1][0] + abs(a[i]-a[i-1])  , dp[i-1][1] + abs(a[i]-diff_b));
//         dp[i][1] = max(dp[i-1][1] + abs(diff_a-diff_b), dp[i-1][0] + abs(a[i-1]-diff_a));
//     }
//     return max(dp[n-1][0], dp[n-1][1]);
// }