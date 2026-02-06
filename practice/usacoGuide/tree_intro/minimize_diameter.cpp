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
#define MAXN 10
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};

void dfs(int node, int d, int par, unordered_map<int, vector<int>> &g, unordered_map<int, int> &parent, int &maxD, int &f, bool de = false)
{
    parent[node] = par;

    if (d > maxD)
    {
        f = node;
        maxD = d;
    }

    for (auto n : g[node])
    {
        if (n != par)
            dfs(n, d + 1, node, g, parent, maxD, f, de);
    }
}

void s()
{
    int n;
    cin >> n;

    unordered_map<int, vector<int>> g;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m;
    cin >> m;

    for (int i = 0; i < m - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a += n;
        b += n;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    int f = 0, f2 = 0, d = 0;
    unordered_map<int, int> p, p1;
    dfs(1, 0, -1, g, p, d, f);
    p = {}, d = 0;
    dfs(f, 0, -1, g, p, d, f, true);
    vector<int> v1, v2;
    while (f != -1)
    {
        v1.push_back(f);
        f = p[f];
    }
    d = 0;
    dfs(n + 1, 0, -1, g, p1, d, f2);
    p1 = {}, d = 0;

    dfs(f2, 0, -1, g, p1, d, f2);

    while (f2 != -1)
    {
        v2.push_back(f2);
        f2 = p1[f2];
    }

    int c1 = v1[v1.size() / 2], c2 = v2[v2.size() / 2];
    g[c1].push_back(c2);
    g[c2].push_back(c1);
    p = {}, d = 0;
    dfs(1, 0, -1, g, p, d, f);
    p = {}, d = 0;
    dfs(f, 0, -1, g, p, d, f);
    cout << d << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}