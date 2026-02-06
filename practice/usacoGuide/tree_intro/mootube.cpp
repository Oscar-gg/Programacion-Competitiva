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

void dfs(int node, int k, vector<vector<pair<int, int>>> &g, vector<bool> &v, int &count)
{
    if (v[node])
        return;
    v[node] = true;
    count++;

    for (auto &n : g[node])
    {
        if (n.second >= k)
            dfs(n.first, k, g, v, count);
    }
}

void s()
{
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> g(n);

    for (int i = 0; i < n - 1; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        p--;
        q--;
        g[p].push_back({q, r});
        g[q].push_back({p, r});
    }

    for (int i = 0; i < q; i++)
    {
        int k, v;
        cin >> k >> v;
        v--;
        vector<bool> vi(n);
        int c = 0;
        dfs(v, k, g, vi, c);
        cout << c - 1 << "\n";
    }
}

int main()
{
    _;

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}