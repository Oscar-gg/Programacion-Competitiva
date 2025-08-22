#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define RFOR(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define FORC(cont, it) for (typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for (typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

bool assign(bool in, vector<unordered_set<int>> &g)
{
    vector<unordered_set<int>> out(g.size());

    queue<pair<bool, int>> q;
    q.push({in, 1});
    unordered_set<int> v;

    unordered_map<int, int> ein, eout;

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        if (v.count(f.second))
            continue;
        v.insert(f.second);

        // cout << f.first << " " << f.second << "\n";

        for (auto n : g[f.second])
        {
            q.push({!f.first, n});

            if (f.first)
            {
                out[f.second].insert(n);
            }
        }
    }

    bool sol = false;

    g = out;

    for (int i = 0; i < g.size(); i++)
    {
        for (auto v : g[i])
        {
            ein[v]++;
            eout[i]++;
        }
    }

    for (int i = 0; i < g.size(); i++)
    {
        if (sol)
            break;
        for (auto v : g[i])
        {
            // cout << eout[i] << ' ' << ein[v] << "\n";
            // cout << i << " " << v << "\n";
            if (eout[i] == 2 && ein[v] == 1 || eout[i] == 1 && ein[v] == 2)
            {
                // cout << "break";
                g[v].insert(i);
                g[i].erase(v);
                sol = true;
                break;
            }
        }
    }
    return sol;
}

void solve()
{
    int n;
    cin >> n;
    vector<unordered_set<int>> g(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    vector<unordered_set<int>> c = g;

    // cout << "it1:\n";
    if (assign(true, c))
    {
        cout << "YES\n";
        for (int i = 0; i < c.size(); i++)
        {
            for (auto ne : c[i])
            {
                cout << i << " " << ne << "\n";
            }
        }
        return;
    }

    c = g;

    // cout << "it2:\n";
    if (assign(false, c))
    {
        cout << "YES\n";
        for (int i = 0; i < c.size(); i++)
        {
            for (auto ne : c[i])
            {
                cout << i << " " << ne << "\n";
            }
        }
        return;
    }

    cout << "NO\n";
}

int main()
{
    _

        int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}