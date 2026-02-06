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

void dfs(int node, ll s, vector<ll> &p, vector<bool> &v, vector<vector<pair<int, int>>> &g, bool &possible)
{
    if (!possible)
        return;

    if (v[node])
    {
        if (s != p[node])
            possible = false;
        return;
    }

    v[node] = true;
    p[node] = s;

    for (auto &n : g[node])
    {
        dfs(n.first, s + n.second, p, v, g, possible);
    }
}

void s()
{
    int n, m;
    cin >> n >> m;
    vector<ll> p(n + 1);
    vector<bool> v(n + 1);

    vector<vector<pair<int, int>>> g(n + 1);

    for (int i = 0; i < m; i++)
    {
        int l, r, s;
        cin >> l >> r >> s;
        g[l - 1].push_back({r, s});
        g[r].push_back({l - 1, -s});
    }

    bool possible = true;
    for (int i = 0; i <= n && possible; i++)
    {
        if (!v[i])
            dfs(i, 0, p, v, g, possible);
    }

    if (!possible)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for (int i = 1; i < p.size(); i++)
        {
            cout << p[i] - p[i - 1] << " ";
        }
        cout nl;
    }
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