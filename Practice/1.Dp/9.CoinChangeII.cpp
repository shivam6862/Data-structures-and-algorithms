#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[n][amount];
    }
};

// amount = 5
// coins = [1,2,5]
// DP ARRAY
// 1 0 0 0 0 0
// 1 1 1 1 1 1
// 1 1 2 2 3 3
// 1 1 2 2 3 4
//
//
//
//
// class Solution {
// public:
//     int finder(int i,vector<int>&v ,int a,vector<vector<int>>&dp){
//         if(i<0) return 0;
//         if(a==0) return 1;
//         if(dp[i][a]!=-1) return dp[i][a];
//         int nottake=finder(i-1,v,a,dp);
//         int take=0;
//         if(a>=v[i])
//         take=finder(i,v,a-v[i],dp);
//         return dp[i][a]=take+nottake;
//     }
//     int change(int amount, vector<int>& coins) {
//         sort(coins.rbegin(),coins.rend());
//         vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
//         return finder(coins.size()-1,coins,amount,dp);
//     }
// };