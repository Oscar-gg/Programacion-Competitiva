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

void dfs(int node, unordered_map<int, vector<int>> &g, unordered_set<int> &v, vector<int> &gr)
{
    if (v.count(node))
        return;

    v.insert(node);
    gr.push_back(node);

    for (auto n : g[node])
    {
        dfs(n, g, v, gr);
    }
}

void s()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(n);
    unordered_map<int, vector<int>> g;
    for (auto &v : a)
        cin >> v.first >> v.second;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    unordered_set<int> v;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        vector<int> gr;
        dfs(i, g, v, gr);

        if (gr.size() == 0)
            continue;

        int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;

        for (auto node : gr)
        {
            minX = min(minX, a[node].first);
            maxX = max(maxX, a[node].first);
            minY = min(minY, a[node].second);
            maxY = max(maxY, a[node].second);
        }
        ans = min(ans, 2 * (maxX - minX) + 2 * (maxY - minY));
    }
    cout << ans nl;
}

int main()
{
    _;

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}