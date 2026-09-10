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

ll fast_pow(ll a, ll exp, ll mod)
{
    ll pow = a % mod;
    ll res = 1;

    while (exp > 0)
    {
        if (exp & 1)
        {
            res *= pow;
            res %= mod;
        }
        exp >>= 1;
        pow = pow * pow;
        pow %= mod;
    }

    return res;
}

ll tot(ll tar)
{
    ll ans = 1;
    for (ll i = 2; i * i <= tar; i++)
    {
        int exp = 0;
        while (tar % i == 0)
        {
            tar /= i;
            exp++;
        }

        if (exp > 0)
        {
            ans = ans * fast_pow(i, exp - 1, MOD) * (i - 1);
        }
    }
    if (tar > 1)
    {
        ans = ans * (tar - 1);
    }
    return ans;
}

ll phi(ll n)
{
    ll ans = n;
    for (ll p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
            {
                n /= p;
            }
            ans -= ans / p;
        }
    }
    if (n > 1)
    {
        ans -= ans / n;
    }
    return ans;
}

void s()
{
    int n;
    cin >> n;
    ll sum = 1, divNum = 1, prod = 1;
    vector<pair<int, int>> a(n);
    ll mul = 1;
    // ll exp_tar = tot(MOD - 1);
    // ll exp_tar = phi(MOD - 1);
    // dbg(exp_tar);

    bool halved = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        ll t = a[i].second + 1;
        if (!halved && t % 2 == 0)
        {
            halved = true;
            t /= 2;
        }
        mul *= t;
        mul %= MOD - 1;
    }

    for (int i = 0; i < n; i++)
    {
        ll x = a[i].first, k = a[i].second;

        divNum = divNum * (k + 1);
        divNum %= MOD;

        sum = sum * (fast_pow(x, k + 1, MOD) - 1);
        sum %= MOD;
        sum = sum * fast_pow(x - 1, MOD - 2, MOD);
        sum %= MOD;

        ll exp = ((halved ? k % (MOD - 1) : k / 2 % (MOD - 1)) * mul) % (MOD - 1);

        prod = prod * fast_pow(x, exp, MOD);
        prod %= MOD;
    }

    cout << divNum << " " << sum << " " << prod << "\n";
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