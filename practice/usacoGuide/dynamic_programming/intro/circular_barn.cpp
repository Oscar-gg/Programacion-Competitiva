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

    vector<int> a(n);
    cin >> a;

    ll ans = LLONG_MAX;

    for (int ith = 0; ith <= n; ith++)
    {
        a.push_back(a[0]);
        a.erase(a.begin());
        vector<ll> pref(n);
        ll cur = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (i != n - 1)
            {
                pref[i] = pref[i + 1];
            }
            pref[i] += cur;
            cur += a[i];
            // dbg(cur);
        }
        vector<vector<ll>> dp(k, vector<ll>(n, LLONG_MAX));

        ans = min(ans, pref[0]);

        // dbg("a");
        // cout << a << "\n\n";
        // dbg("pref");
        // cout << pref << "\n\n";

        dp[0][0] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = dp[0][i - 1] + a[i] * i;
        }

        for (int i = 1; i < k; i++)
        {
            dp[i][0] = 0;
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = min({dp[i][j], dp[i - 1][j]});

                ll cur = 0;
                for (int l = j; l < n; l++)
                {
                    cur += a[l] * (l - j);
                    dp[i][l] = min({dp[i][l], dp[i - 1][j - 1] + cur});
                }
            }
            ans = min(ans, dp[i].back());
        }
        // dbg(ith);
        // for (auto r : dp)
        // {
        //     for (auto v : r)
        //         cout << v << " ";
        //     cout nl;
        // }
        // cout nl;
    }

    // for (int i = 1; i <= k; i++)
    // {
    //     // dp[i][j]
    //     dp[i][0] = dp[i - 1][0];
    //     for (int j = 1; j < n; j++)
    //     {
    //         dp[i][j] = min({dp[i][j],
    //                         dp[i - 1][j],
    //                         dp[i][j - 1],
    //                         dp[i - 1][j - 1] + pref[j] + suff[j] - pref[j - 1] - suff[j - 1] - a[j] + a[j - 1]});

    //         ans = min(ans, dp[i][j]);
    //     }
    // }

    cout << ans << "\n";
}

int main()
{
    _;

    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);

    // dbg("asdf");
    int t = 1;
    // // cin >> t;
    while (t--)
        s();
    return 0;
}