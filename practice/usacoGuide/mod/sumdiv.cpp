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

ll fast_pow(ll a, ll exp)
{
    ll pow = a % MOD;
    ll res = 1;

    while (exp > 0)
    {
        if (exp & 1)
        {
            res *= pow;
            res %= MOD;
        }
        exp >>= 1;

        pow *= pow;
        pow %= MOD;
    }

    return res;
}

ll s(ll a, ll b)
{
    ll ans = 1;

    for (ll i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            ll exp = 0;
            while (a % i == 0)
            {
                exp++;
                a /= i;
            }

            ans = (ans * ((fast_pow(i, ((exp * (b % (MOD - 1)) + 1) % (MOD - 1))) - 1 + MOD) % MOD)) % MOD;
            ans = ans * fast_pow(i - 1, MOD - 2);
            ans %= MOD;
        }
    }

    if (a > 1 && ((a - 1) % MOD == 0))
    {
        ans = ans * ((b + 1) % MOD);
        ans %= MOD;
    }
    else if (a > 1)
    {
        ans = (ans * ((fast_pow(a, (((b % (MOD - 1)) + 1) % (MOD - 1))) - 1 + MOD) % MOD)) % MOD;
        ans = ans * fast_pow(a - 1, MOD - 2);
        ans %= MOD;
    }
    return ans;
    // cout << ans << "\n";
}

int main()
{
    _;

    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);
    int t = 1;
    // cin >> t;
    ll a, b;
    cin >> a >> b;
    cout << s(a, b) << "\n";

    return 0;
}