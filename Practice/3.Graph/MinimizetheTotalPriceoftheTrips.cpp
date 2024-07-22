
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> finder(int curr, int parent, vector<int> &price, vector<vector<int>> &adj)
    {
        vector<int> children = adj[curr];
        int notDivide = 0, divide = 0;
        for (auto child : children)
        {
            if (child == parent)
                continue;
            vector<int> childCost = finder(child, curr, price, adj);
            notDivide += childCost[0];
            divide += min(childCost[0], childCost[1]);
        }
        return {price[curr] + divide, price[curr] / 2 + notDivide};
    }

    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        vector<vector<int>> adj(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> nodeVisitredCount(n, 0);
        for (auto trip : trips)
        {
            int src = trip[0], dest = trip[1];
            vector<bool> vis(n, false);
            vector<int> parent(n, -1);
            queue<int> q;
            q.push(src);
            vis[src] = true;
            while (!q.empty())
            {
                auto curr = q.front();
                q.pop();
                if (curr == dest)
                    break;
                for (auto next : adj[curr])
                {
                    if (vis[next] == false)
                    {
                        q.push(next);
                        vis[next] = true;
                        parent[next] = curr;
                    }
                }
            }
            int curr = dest;
            while (curr != -1)
            {
                nodeVisitredCount[curr]++;
                curr = parent[curr];
            }
        }

        for (int i = 0; i < n; i++)
        {
            price[i] = price[i] * nodeVisitredCount[i];
        }

        vector<int> ans = finder(0, -1, price, adj);
        return min({ans[0], ans[1]});
    }
};

int main()
{
}