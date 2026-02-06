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

void dfs(int node, int w, unordered_map<int, vector<pair<int, int>>> &g, unordered_set<int> &v, int &vinI, unordered_set<int> &vin)
{
    if (v.count(node))
        return;

    v.insert(node);

    if (vin.count(node))
        vinI++;

    for (auto n : g[node])
    {
        if (w <= n.first)
        {
            dfs(n.second, w, g, v, vinI, vin);
        }
    }
}

bool pos(int w, unordered_map<int, vector<pair<int, int>>> &g, unordered_set<int> &v)
{
    unordered_set<int> vi;
    int vin = 0;

    dfs(*v.begin(), w, g, vi, vin, v);

    return v.size() == vin;
}

void s()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    cin >> a;
    int move = 0;
    unordered_set<int> v;

    for (int i = 0; i < n; i++)
    {
        a[i]--;
        if (i != a[i])
        {
            move++;
            v.insert(i);
        }
    }
    if (move == 0)
    {
        cout << "-1\n";
        return;
    }
    unordered_map<int, vector<pair<int, int>>> g;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;

        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }

    int l = 0, r = 1e9;

    while (l < r)
    {
        int m = l + (r - l + 1) / 2;

        if (pos(m, g, v))
        {
            l = m;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << l << "\n";
}

int main()
{
    _;

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}