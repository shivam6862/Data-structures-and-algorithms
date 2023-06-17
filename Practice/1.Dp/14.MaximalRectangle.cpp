#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestrectanglearea(vector<int> &histo)
    {
        stack<int> st;
        int maxa = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
            {
                int height = histo[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxa = max(maxa, width * height);
            }
            st.push(i);
        }
        return maxa;
    }
    int maximalareaofsubmatrixofall(vector<vector<char>> &mat, int n, int m)
    {
        int maxarea = 0;
        vector<int> height(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            int area = largestrectanglearea(height);
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        return maximalareaofsubmatrixofall(mat, n, m);
    }
};