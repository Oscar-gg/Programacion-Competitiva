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

ll sum(ll s, ll e, ll modinv)
{
    return (((s + e) % MOD) * ((((e - s + 1) % MOD) * modinv) % MOD)) % MOD;
}

ll fastpow(ll v, ll e)
{
    if (e == 0)
        return 1;

    ll res = 1;
    v %= MOD;

    while (e > 0)
    {
        if (e & 1)
        {
            res = (res * v) % MOD;
        }
        e >>= 1;
        v = (v * v) % MOD;
    }

    return res;
}

void s(ll t)
{
    ll n;
    cin >> n;

    ll ans = 0;

    ll l = 1;

    ll modinv = fastpow(2, MOD - 2);
    // dbg(modinv);

    while (l <= n)
    {
        ll add = (n / l);
        ll end = n / add;

        ans = ans + ((add * sum(l, end, modinv)) % MOD);
        ans %= MOD;
        l = end + 1;
    }

    cout << ans << "\n";
}

void s2()
{

    ll n;
    cin >> n;
    ll ans = 0;

    for (ll i = 1; i <= n; i++)
    {
        cout << "(" << n / i << "," << n / i * i << ") ";
        ans += n / i * i;
    }
    cout nl;

    cout << ans << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    // cin >> t;
    // s2();
    while (t--)
        s(t);
    return 0;
}