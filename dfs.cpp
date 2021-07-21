// Count the number of connected components in a graph
#include <bits/stdc++.h>
using namespace std;
vector<int> *adj;
vector<int> comp_number;

void dfs(int u, int count, vector<bool> & visited)
{
    visited[u] = true;
    comp_number[u] = count;
    for(auto v: adj[u])
    {
        if(!visited[v])
        {
            dfs(v, count, visited);
        }
    }
}

int components(int n)
{
    vector<bool> visited(n, false);
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(i, count, visited);
        }
    }
    return count;
}

int main()
{
    int n, e;
    cin >> n >> e;
    adj = new vector<int>[n];
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    comp_number.assign(n, 0);
    cout << components(n) << endl;
    for(int i = 0; i < n; i++)
    {
        cout << i << " " << comp_number[i] << endl;
    }
}
