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

void s()
{
    int n, k;
    cin >> n >> k;
    vector<char> a(n);
    cin >> a;

    vector<int> h(n), p(n), s(n);
    vector<int> sh(n), sp(n), ss(n);

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            h[i] = h[i - 1];
            p[i] = p[i - 1];
            s[i] = s[i - 1];
        }
        h[i] += a[i] == 'H';
        p[i] += a[i] == 'P';
        s[i] += a[i] == 'S';
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
        {
            sh[i] = sh[i + 1];
            sp[i] = sp[i + 1];
            ss[i] = ss[i + 1];
        }
        sh[i] += a[i] == 'H';
        sp[i] += a[i] == 'P';
        ss[i] += a[i] == 'S';
    }

    vector<vector<int>> dh(k + 1, vector<int>(n)), dp(k + 1, vector<int>(n)), ds(k + 1, vector<int>(n));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        dh[0][i] = h[i] + sh[i];
        dp[0][i] = p[i] + sp[i];
        ds[0][i] = s[i] + ss[i];

        dh[0][i] -= a[i] == 'H';
        dp[0][i] -= a[i] == 'P';
        ds[0][i] -= a[i] == 'S';

        ans = max({dh[0][i], dp[0][i], ds[0][i]});
    }

    for (int i = 1; i <= k; i++)
    {

        // dbg(i);
        dh[i][0] = 1;
        dp[i][0] = 1;
        ds[i][0] = 1;
        for (int j = 1; j < n; j++)
        {
            dh[i][j] = max({dh[i][j], dh[i - 1][j], dh[i][j - 1]});
            dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
            ds[i][j] = max({ds[i][j], ds[i - 1][j], ds[i][j - 1]});

            dh[i][j] = max({dh[i][j], dp[i - 1][j - 1] - sp[j] + sh[j], ds[i - 1][j] - ss[j] + sh[j]});
            dp[i][j] = max({dp[i][j], dh[i - 1][j - 1] - sh[j] + sp[j], ds[i - 1][j] - ss[j] + sp[j]});
            ds[i][j] = max({ds[i][j], dp[i - 1][j - 1] - sp[j] + ss[j], dh[i - 1][j] - sh[j] + ss[j]});
            ans = max({ans, dh[i][j], dp[i][j], ds[i][j]});
        }
    }

    // dbg("dh");
    // for (auto v : dh)
    // {
    //     cout << v << "\n";
    // }
    // dbg("dp");
    // for (auto v : dp)
    // {
    //     cout << v << "\n";
    // }
    // dbg("ds");
    // for (auto v : ds)
    // {
    //     cout << v << "\n";
    // }

    cout << ans << "\n";
}

int main()
{
    _;

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}