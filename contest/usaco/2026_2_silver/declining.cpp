#include <bits/stdc++.h>

using namespace std;
#define ll long long

void s()
{
    int n, c;
    cin >> n >> c;
    vector<int> f(c), p(n);
    vector<vector<int>> g(n);
    vector<set<int>> g2(c);

    for (auto &v : f)
        cin >> v;

    for (auto &v : p)
    {
        cin >> v;
        v--;
    }

    for (int i = 0; i < n; i++)
    {
        int am;
        cin >> am;
        while (am--)
        {
            int v;
            cin >> v;
            v--;
            g[i].push_back(v);
            g2[v].insert(i);
        }
    }

    ll t = 0;
    unordered_set<int> v;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < c; j++)
        {
            int fo = 0;
            auto it = g2[j].begin();
            while (fo < f[j] && it != g2[j].end())
            {
                if (!v.count(*it))
                {
                    v.insert(*it);
                    t += *it + 1;
                    fo++;
                }
                it++;
            }
        }
        for (auto &e : g[p[i]])
        {
            g2[e].erase(p[i]);
        }
        cout << t << "\n";
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}