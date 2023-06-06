// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

// Dp of tech to take data from moving from the last postion of array and again going forward to check and update the current value

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &num, int k)
    {
        int n = num.size();
        vector<int> dp(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            int len = 0, maxi = INT_MIN, maxans = INT_MIN;
            for (int j = ind; j < min(ind + k, n); j++)
            {
                len++;
                maxi = max(maxi, num[j]);
                int sum = maxi * len + dp[j + 1];
                maxans = max(maxans, sum);
            }
            dp[ind] = maxans;
        }
        return dp[0];
    }
};

// [1,15,7,9,2,5,10]  {input}
// 84 75 48 39 30 20 10 0  {dp array}