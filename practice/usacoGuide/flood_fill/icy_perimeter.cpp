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

bool dfs(int i, int j, int n, vector<vector<bool>> &v, vector<string> &a, int &p, int &area)
{
    if (i >= n || j >= n || i < 0 || j < 0 || a[i][j] == '.')
        return false;

    if (v[i][j])
        return true;

    v[i][j] = true;
    area++;

    vector<int> x{0, 0, 1, -1};
    vector<int> y{1, -1, 0, 0};

    for (int it = 0; it < 4; it++)
    {
        int ni = i + x[it];
        int nj = j + y[it];
        if (!dfs(ni, nj, n, v, a, p, area))
            p++;
    }

    return true;
}

void s()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &v : a)
        cin >> v;

    vector<vector<bool>> v(n, vector<bool>(n));

    int maxA = 0, minP = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int p = 0, area = 0;
            ;

            dfs(i, j, n, v, a, p, area);
            if (area > maxA)
            {
                maxA = area, minP = p;
            }
            else if (area == maxA)
                minP = min(minP, p);
        }
    }

    cout << maxA << " " << minP << "\n";
}

int main()
{
    _;

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}