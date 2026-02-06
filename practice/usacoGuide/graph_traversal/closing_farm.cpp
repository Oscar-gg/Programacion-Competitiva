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

void dfs(int node, unordered_set<int> &v, unordered_map<int, vector<int>> &g)
{
    if (v.count(node))
        return;
    v.insert(node);

    for (auto n : g[node])
    {
        if (g[n].size() > 0)
            dfs(n, v, g);
    }
}

string fully_connected(unordered_map<int, vector<int>> &g, int n)
{
    unordered_set<int> v;

    for (auto node : g)
    {
        if (node.second.size() > 0)
        {
            dfs(node.first, v, g);
            break;
        }
    }

    if (v.size() == n)
        return "YES";
    return "NO";
}

void s()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> g;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> a(n);
    cin >> a;

    for (int i = 0; i < n; i++)
    {
        cout << fully_connected(g, n - i) << "\n";
        g[a[i]] = {};
    }
}

int main()
{
    _;

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}