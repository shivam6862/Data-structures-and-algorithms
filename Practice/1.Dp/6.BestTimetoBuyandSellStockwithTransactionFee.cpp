#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int charge = 0;
    int f(int ind, int buy, vector<int> &values, int n, vector<vector<int>> &dp)
    {
        if (ind == n)
            return 0;
        int profit = 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        if (buy)
            profit = max(-values[ind] - charge + f(ind + 1, 0, values, n, dp), 0 + f(ind + 1, 1, values, n, dp));
        else
            profit = max(values[ind] + f(ind + 1, 1, values, n, dp), 0 + f(ind + 1, 0, values, n, dp));
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // charge=fee;
        // return f(0,1,prices,n,dp);

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[n - 1][1];
    }
};

// prices =[1,3,2,8,4,9]
// fee = 2
// DP ARRAY
// -1 0
// -1 0
// -1 0
// -1 5
// 1 5
// 1 8

// WITH COOLDOWN
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[1][0] = max(dp[0][0], -prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] + prices[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[n - 1][1];
    }
};
