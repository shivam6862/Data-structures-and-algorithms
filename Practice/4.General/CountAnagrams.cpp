
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    long long MOD = 1e9 + 7;
    int countAnagrams(string s)
    {
        s += ' ';
        long long ans = 1;
        int n = s.length();
        unordered_map<char, int> map;
        int length = 0;
        vector<int> inv(n, 1), fact(n), inv_fact(n);
        fact[0] = 1;
        inv_fact[0] = 1;
        fact[1] = 1;
        inv_fact[1] = 1;

        for (long long i = 2; i < n; ++i)
        {
            // Calculate factorial of 'i' modulo MOD using previously calculated factorial of (i - 1)
            fact[i] = i * fact[i - 1] % MOD;
            // Calculate modular inverse of 'i' using the property MOD - (MOD / i) * inv[MOD % i]
            // inv[MOD % i] is the modular inverse of (MOD % i) which is already calculated
            inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
            // Calculate inverse factorial of 'i' modulo MOD using previously calculated inverse factorial of (i - 1)
            // and the modular inverse of 'i'
            inv_fact[i] = 1LL * inv_fact[i - 1] * inv[i] % MOD;
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                long long temp = fact[length];
                for (auto it : map)
                {
                    temp = (temp * inv_fact[it.second]) % MOD;
                }
                ans = (ans * temp) % MOD;
                map.clear();
                length = 0;
            }
            else
            {
                ++length;
                map[s[i]]++;
            }
        }

        return ans;
    }
};