// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

// way of starting the data and again using in smarterway

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size(), ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            dp[i][i] = true, ans++;

        for (int i = 0; i < n - 1; i++)
            if (s[i] == s[i + 1])
                dp[i][i + 1] = true, ans++;

        for (int len = 3; len <= n; len++)
        {
            for (int start = 0; start <= n - len; start++)
            {
                int end = start + len - 1;
                if (s[start] == s[end] && dp[start + 1][end - 1])
                {
                    dp[start][end] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};

// "abbaaabbac"  {input}
//
//
// DP ARRAY
//   a b b a a a b b a c
// a 1 0 0 1 0 0 0 0 1 0
// b 0 1 1 0 0 0 0 1 0 0
// b 0 0 1 0 0 0 1 0 0 0
// a 0 0 0 1 1 1 0 0 0 0
// a 0 0 0 0 1 1 0 0 0 0
// a 0 0 0 0 0 1 0 0 1 0
// b 0 0 0 0 0 0 1 1 0 0
// b 0 0 0 0 0 0 0 1 0 0
// a 0 0 0 0 0 0 0 0 1 0
// c 0 0 0 0 0 0 0 0 0 1

//
//
//
//
class Solution
{
public:
    void findPartitions(int start, const string &s, const vector<vector<bool>> &dp, vector<string> &temp, vector<vector<string>> &ans)
    {
        if (start >= s.length())
            ans.push_back(temp);
        for (int end = start; end < s.length(); end++)
        {
            if (dp[start][end])
            {
                temp.push_back(s.substr(start, end - start + 1));
                findPartitions(end + 1, s, dp, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i < n - len + 1; i++)
            {
                int j = i + len - 1;
                if (len == 2)
                    dp[i][i + 1] = (s[i] == s[i + 1]);
                else
                    dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
            }
        }
        vector<vector<string>> ans;
        vector<string> temp;
        findPartitions(0, s, dp, temp, ans);
        return ans;
    }
};

// s = "abbab"
// Output = [["a","b","b","a","b"],["a","b","bab"],["a","bb","a","b"],["abba","b"]]