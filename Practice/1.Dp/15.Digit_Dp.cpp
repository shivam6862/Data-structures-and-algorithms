
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
class Solution
{
public:
    int finder(int currentIndex, bool tight, int evenDigitcount, int oddDigitcount, int rem, string str, vector<vector<vector<vector<vector<int>>>>> &dp, int k, bool allZero)
    {
        if (currentIndex == str.length())
            return evenDigitcount == oddDigitcount && rem == 0;

        if (dp[currentIndex][tight ? 1 : 0][evenDigitcount][oddDigitcount][rem] != -1)
            return dp[currentIndex][tight ? 1 : 0][evenDigitcount][oddDigitcount][rem];

        int end = tight ? (str[currentIndex] - '0') : 9;
        int count = 0;

        for (int currentDigit = 0; currentDigit <= end; currentDigit++)
        {

            int newRem = (rem * 10 + currentDigit) % k;
            bool newTight = tight && (currentDigit == end);
            bool newAllzero = allZero && (currentDigit == 0);

            if (currentDigit % 2 == 0)
                count += finder(currentIndex + 1, newTight, newAllzero ? evenDigitcount : evenDigitcount + 1, oddDigitcount, newRem, str, dp, k, newAllzero);
            else
                count += finder(currentIndex + 1, newTight, evenDigitcount, oddDigitcount + 1, newRem, str, dp, k, newAllzero);
        }

        return dp[currentIndex][tight ? 1 : 0][evenDigitcount][oddDigitcount][rem] = count;
    }

    int numberOfBeautifulIntegers(int low, int high, int k)
    {

        string lowString = to_string(low - 1);
        int n = lowString.length();
        vector<vector<vector<vector<vector<int>>>>> dp1(n, vector<vector<vector<vector<int>>>>(2, vector<vector<vector<int>>>(11, vector<vector<int>>(11, vector<int>(21, -1)))));

        string highString = to_string(high);
        n = highString.length();
        vector<vector<vector<vector<vector<int>>>>> dp2(n, vector<vector<vector<vector<int>>>>(2, vector<vector<vector<int>>>(11, vector<vector<int>>(11, vector<int>(21, -1)))));

        int answer = finder(0, true, 0, 0, 0, highString, dp2, k, true) - finder(0, true, 0, 0, 0, lowString, dp1, k, true);

        return answer;
    }
};