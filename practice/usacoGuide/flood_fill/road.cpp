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

void dfs(pair<int, int> p, vector<vector<int>> &m, int &cur, map<pair<int, int>, set<pair<int, int>>> &g)
{
    if (p.first < 0 || p.second < 0 || p.first >= m.size() || p.second >= m.size() || !m[p.first][p.second])
    {
        return;
    }

    if (m[p.first][p.second] == 1)
        cur++;

    m[p.first][p.second] = 0;

    vector<int> x{0, 0, -1, 1};
    vector<int> y{1, -1, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        auto p2 = p;
        p2.first += x[i];
        p2.second += y[i];

        if (!g[p].count(p2))
            dfs(p2, m, cur, g);
    }
}

void s()
{
    int n, k, r;
    cin >> n >> k >> r;

    map<pair<int, int>, set<pair<int, int>>> g;

    for (int i = 0; i < r; i++)
    {
        int x, y, x2, y2;
        cin >> x >> y >> x2 >> y2;

        x--;
        y--;
        x2--;
        y2--;

        g[{x, y}].insert({x2, y2});
        g[{x2, y2}].insert({x, y});
    }

    vector<vector<int>> m(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        m[a][b] = 1;
    }

    vector<int> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = 0;
            dfs({i, j}, m, temp, g);
            if (temp > 0)
                c.push_back(temp);
        }
    }
    int ans = 0;

    for (int i = 0; i < c.size(); i++)
    {
        for (int j = i + 1; j < c.size(); j++)
        {
            ans += c[i] * c[j];
        }
    }
    cout << ans << "\n";
}

int main()
{
    _;

    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}