#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, int s, int e, vector<int> adj[])
{
    // solve(s) function
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    vector<int> prev(n, INT_MIN);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v: adj[u])
        {
            if(visited[v])
                continue;
            visited[v] = true;
            q.push(v);
            prev[v] = u;
        }
    }

    vector<int> path;
    // reconstructPath() function
    for(int at = e; at != INT_MIN; at = prev[at])
        path.push_back(at);
    reverse(path.begin(), path.end());
    if(path[0] == s)
        return path;
    return {};
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start = 0, end = 6;
    vector<int> path = bfs(n, start, end, adj);
    if(path.size() == 0)
        cout << "No path exists from " << start << " to " << end << endl;
    else
    {
        cout << "BFS traversal from " << start << " to " << end << ": ";
        for(int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

