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
#define FOR(i, a, b) for (ll i = ll(a); i < ll(b); i++)
#define RFOR(i, a, b) for (ll i = ll(a) - 1; i >= ll(b); i--)
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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
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
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> a(n);
    cin >> a;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    vector<vector<int>> dp(1000, vector<int>(n, INT_MIN));
    dp[0][0] = 0;

    for (int i = 0; i < dp.size() - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }

            if (dp[i][j] != INT_MIN)
            {
                for (auto n : g[j])
                {
                    dp[i + 1][n] = max(dp[i + 1][n], dp[i][j] + a[n]);
                }
            }
        }
    }

    // dbg("aa");

    int ans = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        if (dp[i][0] != INT_MIN)
            ans = max(ans, dp[i][0] - c * i * i);
    }

    cout << ans << "\n";
}

int main()
{
    _;

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}