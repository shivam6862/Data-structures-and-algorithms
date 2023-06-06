#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int finder(int i, int prev, vector<int> &nums, int n, vector<vector<int>> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int ct = 0 + finder(i + 1, prev, nums, n, dp);
        if (prev == -1 || nums[prev] < nums[i])
            ct = max(ct, 1 + finder(i + 1, i, nums, n, dp));
        return dp[i][prev + 1] = ct;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return finder(0 , -1 , nums , n , dp);
        if (n == 0)
            return 0;
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// nums = [10,9,2,5,3,7,101,18]
// DP ARRAY EACH TIMES
// 1 1
// 1 1 1
// 1 1 1 2
// 1 1 1 2 2
// 1 1 1 2 2 3
// 1 1 1 2 2 3 4
// 1 1 1 2 2 3 4 4