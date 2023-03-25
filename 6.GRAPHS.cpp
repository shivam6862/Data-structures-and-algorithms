#include <iostream>
#include <string>
#include <string>
#include <array>
#include <iterator>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cmath>

using namespace std;

// NOTE BOTH CODE OF DFS AND BFS IS THE SAME ONLY CHANGE IN THE (QUEUE AND STACK) DATA STRUCTURE TAKEN

// USEFULL VARIABLE IN BFS AND DFS
const int N = 10e5 + 7;
vector<int> g[N];
int vis[N];
int level[N];
bool visited[N];
bool visited1[N];

// ALGO. OF BREADTH FOR SEARCH GRAPH
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        cout << cur_v << " ";
        for (int child : g[cur_v])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                level[child] = level[cur_v] + 1;
            }
        }
    }
}

// ALGO. OF DEAPTH FIRST SEARCH
void dfs(int source)
{
    stack<int> st;
    st.push(source);
    visited[source] = true;
    while (!st.empty())
    {
        int cur = st.top();
        st.pop();
        cout << cur << " ";
        for (int child : g[cur])
        {
            if (!visited[child])
            {
                st.push(child);
                visited[child] = true;
            }
        }
    }
}

// ALGO. OF DEAPTH FIRST SEARCH in recurrsion approch
void dfs1(int vertex)
{
    // take action on vertex after entering the vertex
    //  if(visited1[vertex]) return;
    cout << vertex << " ";
    visited1[vertex] = true;
    for (int child : g[vertex])
    {
        // cout<<"par"<<vertex<<" child "<<child<<endl;
        if (visited1[child])
            continue;
        // take action on child before entering the child node
        dfs1(child);
        // take action on child after exiting child node
    }
    // take action on vertex before exiting the vertex
}

// BODY OF THE FUNCTION STARTS
int main()
{

    //'m' IS THE NUMBER OF VERTICES OR THE MAXIMUM VALUE OF THE CHILD/VERTICES
    int m;
    cin >> m;

    //'n' IS THE NUMBER OF EDGES
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // ENTER THE ROOT NODE OF BFS
    int k;
    cin >> k;
    bfs(k);
    cout << endl;

    // THE ROOT NODE OF DFS
    dfs(k);
    cout << endl;

    dfs1(k);
    cout << endl;

    // PRINTING THE MINIMUN DISTANCE FROM THE ROOT NODE USING BFS
    for (int i = 0; i <= m; i++)
    {
        cout << i << " " << level[i] << endl;
    }

    int child;
    int cur_v;
    // problem-8  (THIS LINE ARE EXTRA ADDED)
    vector<vector<int>> hh(8, vector<int>(0, 0));
    hh[child].push_back(cur_v);
    int ll;
    cin >> ll;
    cout << k << " ";
    for (int i = 0; i < hh[ll].size(); i++)
        cout << hh[ll][i] << " ";
    cout << ll;
}
// PROGRAM-1 (SHORTEST PATH)
// ALGO. OF BREADTH FOR SEARCH GRAPH USING "DIJKASTRA ALGOITHUM"
const int N = 10e5 + 7;
vector<pair<int, int>> g[N];
vector<int> distTo(N, 10000000);
void bfs(int source)
{
    // KOWW HOW TO MAKE THE PRIORITY QUEUE...........................
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    distTo[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        vector<pair<int, int>>::iterator it;
        for (auto it = g[prev].begin(); it != g[prev].end(); it++)
        {
            int next = it->first;
            int nextDist = it->second;
            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }
}
int main()
{
    int m;
    cin >> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
        g[y].push_back({x, wt});
    }
    int k;
    cin >> k;
    bfs(k);
    cout << "The distances from source '" << k << "' are : \n";
    for (int i = 0; i < m; i++)
        cout << distTo[i] << " ";
}

// problem -2

// MINIMUM SPANNING TREE (KRUSKAL'S ALGO.)

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int main()
{
    int N = 5, m = 6;
    vector<node> edges;
    edges.push_back(node(0, 1, 2));
    edges.push_back(node(0, 3, 6));
    edges.push_back(node(1, 0, 2));
    edges.push_back(node(1, 2, 3));
    edges.push_back(node(1, 3, 8));
    edges.push_back(node(1, 4, 5));
    edges.push_back(node(2, 1, 3));
    edges.push_back(node(2, 4, 7));
    edges.push_back(node(3, 0, 6));
    edges.push_back(node(3, 1, 8));
    edges.push_back(node(4, 1, 5));
    edges.push_back(node(4, 2, 7));
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(N);
    for (int i = 0; i < N; i++)
        parent[i] = i;
    vector<int> rank(N, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findPar(it.u, parent) != findPar(it.v, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << " - " << it.second << endl;
    return 0;
}

// PROBLEM-3
// TOPOLOGICAL SORT when it is not a cyclic function

class Solution
{
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                findTopoSort(it, vis, st, adj);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int N, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (vis[i] == 0)
            {
                findTopoSort(i, vis, st, adj);
            }
        }
        vector<int> topo;
        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};
int main()
{
    int N = 6;
    vector<int> adj[5 + 1];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    Solution obj;
    vector<int> res = obj.topoSort(6, adj);
    cout << "Toposort of the given graph is:" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}

// PROBLEM-4
// KOSARAJU ALGORITHUM

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, st, vis, adj);
        }
    }

    st.push(node);
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[])
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node])
    {
        if (!vis[it])
        {
            revDfs(it, vis, transpose);
        }
    }
}
int main()
{
    int n = 6, m = 7;
    vector<int> adj[n + 1];
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(4);
    adj[6].push_back(5);
    stack<int> st;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj);
        }
    }
    vector<int> transpose[n + 1];
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cout << "SCC: ";
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }
    return 0;
}

// PROBLEM -5
//  TARGEN ALGO
void DFS(int u, vector<int> &disc, vector<int> &low, stack<int> &mystack, vector<bool> &presentInStack)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;
    mystack.push(u);
    presentInStack[u] = true;
    for (int v : adj[u])
    {
        if (disc[v] == -1) // If v is not visited
        {
            DFS(v, disc, low, mystack, presentInStack);
            low[u] = min(low[u], low[v]);
        }
        // Differentiate back-edge and cross-edge
        else if (presentInStack[v]) // Back-edge case
            low[u] = min(low[u], disc[v]);
    }

    if (low[u] == disc[u]) // If u is head node of SCC
    {
        cout << "SCC is: ";
        while (mystack.top() != u)
            cout << mystack.top() << " ";
        present InStack[mystack.top()] = false;
        mystack.pop();
    }
    cout << mystack.top() << "\n";
    presentInStack[mystack.top()] = false;
    mystack.pop();
}

void findSCCs_Tarjan()
{
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> presentInStack(V, false); // Avoids cross-edge
    stack<int> mystack;
    for (int i = 0; i < V; ++i)
        if (disc[i] == -1)
            DFS(i, disc, low, mystack, presentInStack);
}
int main()
{
    adj[0].pb(1);
    adj[1].pb(2);
    adj[1].pb(3);
    adj[3].pb(4);
    adj[4].pb(0);
    adj[4].pb(5);
    adj[4].pb(6);
    adj[5].pb(6);
    adj[6].pb(5);
    findSCCs_Tarjan();
    return 0;
}
