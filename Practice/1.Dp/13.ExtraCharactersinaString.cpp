#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = s.length();
        vector<int> dp(n + 1, n);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (const string &word : dictionary)
            {
                int wordLen = word.length();
                if (s.compare(i, wordLen, word) == 0)
                {
                    dp[i] = min(dp[i], dp[i + wordLen]);
                }
            }
            dp[i] = min(dp[i], 1 + dp[i + 1]);
        }
        return dp[0];
    }
};

// vector<int> dp;
// int finder(int i, vector<string> &v, string s)
// {
//     if (i == s.length())
//         return 0;
//     if (dp[i] == -1)
//     {
//         dp[i] = 1 + finder(i + 1, v, s); // not Take
//         for (auto &st : v)
//             if (s.compare(i, st.size(), st) == 0)
//                 dp[i] = min({dp[i], finder(i + st.size(), v, s)}); // Take when it is applicable
//     }
//     return dp[i];
// }
// dp.resize(51,-1);
// return finder(0,dictionary,s);