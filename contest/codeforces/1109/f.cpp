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

void explore(int node, vector<vector<int>> &g, vector<int> &a, vector<pair<int, int>> &r, bool &pos)
{
    if (!pos)
        return;

    if (g[node].size() == 0)
    {
        r[node] = {a[node], a[node]};
        return;
    }

    int max_ = -1, maxInd = 0;
    int min_ = INT_MAX;

    for (int i = 0; i < g[node].size(); i++)
    {
        int sub = g[node][i];
        explore(sub, g, a, r, pos);
        if (r[sub].second > max_)
        {
            max_ = r[sub].second;
            maxInd = i;
        }
        min_ = min(min_, r[sub].first);
    }

    for (int i = maxInd - 1; i >= 0; i--)
    {
        if (i + 1 < g[node].size())
        {
            if (r[g[node][i]].second >= r[g[node][i + 1]].first)
            {
                pos = false;
                return;
            }
        }
    }

    for (int i = g[node].size() - 1; i > maxInd; i--)
    {
        if (i == g[node].size() - 1)
        {
            if (g[node].size() > 1 && r[g[node][i]].second >= r[g[node][0]].first)
            {
                pos = false;
                return;
            }
        }
        else if (i + 1 < g[node].size())
        {
            if (r[g[node][i]].second >= r[g[node][i + 1]].first)
            {
                pos = false;
                return;
            }
        }
    }

    r[node] = {min_, max_};
}

void s()
{
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    vector<int> a(n);
    vector<pair<int, int>> r(n);
    for (int i = 0; i < n - 1; i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i + 1);
    }

    cin >> a;

    bool pos = true;
    explore(0, g, a, r, pos);

    if (pos)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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