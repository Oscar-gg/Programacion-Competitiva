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
#define all(x) x.begin(), x.end()
#define nl << "\n"

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

void s()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    map<pair<int, int>, pair<int, int>> m;
    set<pair<int, int>> vis;
    vector<int> permut(n);
    vector<int> edges(n);
    int largest = n, smallest = 1;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--;
        v--;
        edges[u]++;
        edges[v]++;
        g[u].push_back(v);
        g[v].push_back(u);

        m[{u, v}] = {x, y};
    }
    vector<int> explore;
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[i] == 1)
            explore.push_back(i);
    }

    while (!explore.empty())
    {
        vector<int> nextExplore;

        while (!explore.empty())
        {
            int ex = explore.back();
            explore.pop_back();

            // dbg(ex);

            for (auto neighbour : g[ex])
            {
                int a = neighbour, b = ex;
                if (a > b)
                    swap(a, b);

                if (vis.count({a, b}))
                    continue;

                vis.insert({a, b});

                edges[neighbour]--;

                if (edges[neighbour] == 1)
                    nextExplore.push_back(neighbour);

                pair<int, int> p{a, b};
                // dbg(m[p].first);
                // dbg(m[p].second);
                // dbg(p.first);
                // dbg(p.second);

                if (m[{a, b}].first > m[{a, b}].second)
                {
                    if (ex == a)
                    {
                        permut[ex] = largest--;
                    }
                    else
                    {
                        permut[ex] = smallest++;
                    }
                }
                else
                {
                    if (ex == a)
                    {
                        permut[ex] = smallest++;
                    }
                    else
                    {
                        permut[ex] = largest--;
                    }
                }
            }
            // dbg(permut[ex]);
        }
        explore = nextExplore;
    }

    for (auto v : permut)
    {
        if (v == 0)
        {
            v = smallest;
        }
        cout << v << " ";
    }
    cout nl;
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        s();
    return 0;
}