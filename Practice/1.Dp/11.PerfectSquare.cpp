#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        return dp[n];
    }
};

// n = 12
// DP ARRAY = 0 1 2 3 1 2 3 4 2 1 2 3 3