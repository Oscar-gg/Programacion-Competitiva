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

void dfs(int node, unordered_map<int, unordered_set<int>> &graph, unordered_set<int> &v)
{
    v.insert(node);

    for (auto n : graph[node])
    {
        if (!v.count(n))
        {
            dfs(n, graph, v);
        }
    }
}

int main()
{
    _;

    int n,
        m;
    cin >> n >> m;

    unordered_map<int, unordered_set<int>> umap;

    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        vector<int> g(a);
        if (!a)
            continue;

        for (auto &x : g)
        {
            cin >> x;
            x--;
        }
        int f = g[0];

        for (int j = 1; j < a; j++)
        {
            umap[f].insert(g[j]);
            umap[g[j]].insert(f);
        }
    }


    unordered_map<int, int> v;

    for (int i = 0; i < n; i++)
    {
        // cout << i << "(";
        if (v.count(i))
        {
            cout << v[i] << " ";
        }
        else
        {
            unordered_set<int> newG;
            dfs(i, umap, newG);
            for (auto x : newG)
            {
                v[x] = newG.size();
            }
            cout << v[i] << " ";
        }
    }

    cout << "\n";

    return 0;
}