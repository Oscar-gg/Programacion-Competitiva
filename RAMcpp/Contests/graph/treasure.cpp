// Code by @Oscar-gg
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> parent(n + 1, INT_MAX);
    vector<vector<int>> graph(n + 1);

    parent[0] = 0;
    parent[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++)
        {
            int b;
            cin >> b;
            graph[i].push_back(b);
        }
    }

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        sort(graph[front].begin(), graph[front].end());
        for (int i = 0; i < graph[front].size(); i++)
        {
            int neigbour = graph[front][i];
            if (parent[neigbour] == INT_MAX)
            {
                parent[neigbour] = front;
                q.push(neigbour);
            }
        }
    }

    if (parent[n] == INT_MAX)
    {
        cout << "-1\n";
    }
    else
    {
        vector<int> tb;
        int cur = parent[n];
        while (parent[cur] != cur)
        {
            tb.push_back(cur);
            cur = parent[cur];
        }
        // tb.pop_back();
        cout << tb.size() << "\n";

        while (!tb.empty())
        {
            cout << tb.back() << " ";
            tb.pop_back();
        }

        cout << "\n";
    }
}

int main()
{

    int t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }

    return 0;
}