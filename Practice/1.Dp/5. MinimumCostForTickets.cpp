#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n + 1, 0);
        vector<int> ct = {costs[0], costs[1], costs[2]};
        for (int i = n - 1; i >= 0; i--)
        {
            int take1 = ct[0] + dp[i + 1];
            auto it7 = upper_bound(days.begin(), days.end(), days[i] + 6);
            int take7 = ct[1] + (it7 != days.end() ? dp[it7 - days.begin()] : 0);
            auto it30 = upper_bound(days.begin(), days.end(), days[i] + 29);
            int take30 = ct[2] + (it30 != days.end() ? dp[it30 - days.begin()] : 0);
            dp[i] = min({take1, take7, take30});
        }
        return dp[0];
    }
};

// days = [1,4,6,7,8,20]
// costs = [2,7,15]
// DP ARRRRAY  = 11 9 8 6 4 2 0