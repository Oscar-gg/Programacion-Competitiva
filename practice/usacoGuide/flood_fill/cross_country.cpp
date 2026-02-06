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

pair<int, int> parent(int i, int j, vector<vector<pair<int, int>>> &p)
{
    if (i == p[i][j].first && j == p[i][j].second)
    {
        return {i, j};
    }
    return p[i][j] = parent(p[i][j].first, p[i][j].second, p);
}

void mnodes(int i, int j, int i2, int j2, vector<vector<pair<int, int>>> &p, vector<vector<int>> &s)
{
    pair<int, int> p1 = parent(i, j, p), p2 = parent(i2, j2, p);

    if (p1 != p2)
    {
        if (s[p1.first][p1.second] < s[p2.first][p2.second])
        {
            swap(p1, p2);
        }

        s[p1.first][p1.second] += s[p2.first][p2.second];
        p[p2.first][p2.second] = p1;
    }
}

void s()
{
    int n, m;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<pair<int, int>>> p(m, vector<pair<int, int>>(n));
    vector<vector<int>> s(m, vector<int>(n));

    vector<vector<int>> e;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            p[i][j] = {i, j};

            if (i > 0)
            {
                e.push_back({abs(a[i - 1][j] - a[i][j]), i - 1, j, i, j});
            }
            if (j > 0)
            {
                e.push_back({abs(a[i][j - 1] - a[i][j]), i, j - 1, i, j});
            }
        }
    }

    sort(all(e));
    int t = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
            if (s[i][j])
                t++;
        }
    }

    int d = 0;

    for (int it = 0; it < e.size(); it++)
    {
        d = max(d, e[it][0]);
        int i = e[it][1], j = e[it][2], i2 = e[it][3], j2 = e[it][4];

        mnodes(i, j, i2, j2, p, s);
        pair<int, int> pi = parent(i, j, p);

        if (s[pi.first][pi.second] == t)
            break;
    }

    cout << d << "\n";
}

int main()
{
    _;

    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}