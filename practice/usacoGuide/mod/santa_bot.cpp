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
#define MOD 998244353

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

ll fast_pow(ll n, ll exp, ll mod)
{
    ll ans = 1;
    ll pow = n % mod;

    while (exp > 0)
    {
        if (exp & 1)
        {
            ans *= pow;
            ans %= mod;
        }
        exp >>= 1;
        pow = pow * pow;
        pow %= mod;
    }

    return ans % mod;
}

ll inv(ll v)
{
    ll res = fast_pow(v, MOD - 2, MOD);
    return res % MOD;
}

void s()
{
    ll n;
    cin >> n;
    ll x = 1, y = 1;

    unordered_map<ll, ll> umap;

    vector<vector<ll>> a(n);

    for (ll i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; j++)
        {
            ll next;
            cin >> next;
            a[i].push_back(next);
            umap[next]++;
        }
    }

    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < a[i].size(); j++)
        {
            ll cur = (umap[a[i][j]] % MOD) * inv(n * n * (ll)a[i].size());
            cur %= MOD;
            ans += cur;
            ans %= MOD;
        }
    }
    // x = 7;
    // y = 8;
    // dbg(x);
    // dbg(y);

    cout << ans % MOD << "\n";

    // cout << (x * inv(y)) % MOD << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}