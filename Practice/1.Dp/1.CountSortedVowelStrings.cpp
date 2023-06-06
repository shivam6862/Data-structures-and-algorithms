// Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
// A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

// Dp of tech to take data from dp dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countstring(int n, int start, vector<vector<int>> &dp)
    {
        if (n == 0)
            return 1;
        if (dp[n][start] != -1)
            return dp[n][start];
        int cnt = 0;
        for (int i = start; i < 5; i++)
        {
            cnt += countstring(n - 1, i, dp);
            cout << n << " " << start << " " << cnt << endl;
        }
        return dp[n][start] = cnt;
    }
    int countVowelStrings(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(6, 0));
        // return countstring(n,0,dp);

        for (int i = 1; i <= 5; i++)
            dp[0][i] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 5; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[n][5];
    }
};

// input 5

// DP ARRAY
// 0 1 1 1 1 1
// 0 1 2 3 4 5
// 0 1 3 6 10 15
// 0 1 4 10 20 35
// 0 1 5 15 35 70
// 0 1 6 21 56 126