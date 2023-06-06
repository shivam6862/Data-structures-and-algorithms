#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int lcs(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = 1 + lcs(i - 1, j - 1, s, t, dp);
        return dp[i][j] = max(lcs(i - 1, j, s, t, dp), lcs(i, j - 1, s, t, dp));
    }
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        // vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
        // return lcs(s.length()-1,t.length()-1,s,t,dp);
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
        // return n+m-2*dp[n][m];  {Delete Operation for Two Strings}
        // return s.length() - dp[n][n]; {Minimum Insertion Steps to Make a String Palindrome}
    }
};

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