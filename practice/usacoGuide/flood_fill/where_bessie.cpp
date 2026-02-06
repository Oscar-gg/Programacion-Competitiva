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

void dfs(char c, int i, int j, int x, int y, int x2, int y2, vector<vector<bool>> &v, vector<string> &a)
{
    if (i >= x && i <= x2 && j >= y && j <= y2 && !v[i][j] && a[i][j] == c)
    {
        v[i][j] = true;

        vector<int> xi{0, 0, -1, 1}, yi{-1, 1, 0, 0};

        for (int it = 0; it < 4; it++)
        {
            int ni = i + xi[it];
            int nj = j + yi[it];

            dfs(c, ni, nj, x, y, x2, y2, v, a);
        }
    }
}

bool explore(int x, int y, int x2, int y2, vector<string> &a, vector<vector<bool>> &v)
{
    vector<char> av;
    for (int i = x; i <= x2; i++)
    {
        for (int j = y; j <= y2; j++)
        {
            v[i][j] = false;
        }
    }
    for (int i = x; i <= x2; i++)
    {
        for (int j = y; j <= y2; j++)
        {
            if (!v[i][j])
            {
                dfs(a[i][j], i, j, x, y, x2, y2, v, a);
                av.push_back(a[i][j]);
            }
        }
    }

    unordered_map<int, int> umap;
    for (auto &c : av)
        umap[c]++;

    if (umap.size() != 2)
        return false;

    int hasM = 0;

    for (auto &p : umap)
    {
        if (p.second > 1)
            hasM++;
    }

    return hasM == 1;
}

bool contains(int i, int j, vector<vector<int>> &all)
{
    int ix1 = all[i][0], ix2 = all[i][2], iy1 = all[i][1], iy2 = all[i][3];
    int jx1 = all[j][0], jx2 = all[j][2], jy1 = all[j][1], jy2 = all[j][3];

    bool cx = false, cy = false;
    if (ix1 <= jx1 && jx1 <= ix2 && ix1 <= jx2 && jx2 <= ix2)
    {
        cx = true;
    }
    if (iy1 <= jy1 && jy1 <= iy2 && iy1 <= jy2 && jy2 <= iy2)
    {
        cy = true;
    }
    return cx && cy;
}

void print(vector<int> &p, vector<string> &a)
{

    for (int i = p[0]; i <= p[2]; i++)
    {
        for (int j = p[1]; j <= p[3]; j++)
        {
            cout << a[i][j];
        }
        cout nl;
    }
    cout nl;
}

void s()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &v : a)
        cin >> v;

    vector<vector<int>> all;
    vector<vector<bool>> v(n, vector<bool>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = i; k < n; k++)
            {
                for (int l = j; l < n; l++)
                {
                    if (explore(i, j, k, l, a, v))
                    {
                        all.push_back({i, j, k, l});
                    }
                }
            }
        }
    }

    vector<bool> exc(all.size());

    for (int i = 0; i < exc.size(); i++)
    {
        if (!exc[i])
        {
            for (int j = 0; j < exc.size(); j++)
            {
                if (i == j)
                    continue;

                if (contains(i, j, all))
                {
                    exc[j] = true;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < exc.size(); i++)
    {
        if (!exc[i])
            ans++;
    }

    cout << ans << "\n";
}

int main()
{
    _;

    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}