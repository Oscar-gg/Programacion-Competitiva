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

void dfs(ll node, ll time, unordered_map<ll, set<vector<ll>>> &g, vector<ll> &a, vector<ll> &v, bool skipL)
{
    if (time >= v[node])
        return;

    v[node] = time;

    if (!skipL)
        time += a[node];

    while (!g[node].empty())
    {
        auto f = (*g[node].rbegin());

        if (time <= f[0])
        {
            ll newNode = f[2], newTime = f[1];
            g[node].erase(f);
            dfs(newNode, newTime, g, a, v, false);
        }
        else
        {
            break;
        }
    }
}

void s()
{
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, set<vector<ll>>> g;
    vector<ll> a(n);

    for (ll i = 0; i < m; i++)
    {
        vector<ll> t(4);
        cin >> t[0] >> t[1] >> t[2] >> t[3];
        t[0]--;
        t[2]--;
        g[t[0]].insert({t[1], t[3], t[2]});
    }

    cin >> a;
    vector<ll> v(n, LLONG_MAX);
    dfs(0, 0, g, a, v, true);

    for (int i = 0; i < n; i++)
    {
        if (v[i] != LLONG_MAX)
        {
            cout << v[i] << "\n";
        }
        else
        {
            cout << "-1\n";
        }
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