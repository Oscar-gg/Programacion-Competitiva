// Code by @Oscar-gg

// Problem from:

// Template from: https://www.geeksforgeeks.org/how-to-setup-competitive-programming-in-visual-studio-code-for-c/

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int findIndex(const v64 &employees, int n)
{
    auto x = upper_bound(employees.begin(), employees.end(), n);
    int diff = x - employees.begin();
    return diff;
}

void solve()
{
    int n, m;

    cin >> n >> m;

    v64 s(n);

    forn(i, n)
    {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    v64 sums(n);

    ll total = 0;
    
    forn(i, n)
    {
        total += s[i];
        sums[i] = total;
    }

    for (int i = 0; i < m; i++)
    {
        ll currScore = 0;
        cin >> currScore;
        int pos = findIndex(s, currScore);
        ll ans = 0;
        if (pos > 0)
        {
            ans = sums[pos - 1] + currScore * (n - pos);
        }
        else
        {
            ans = currScore * n;
        }

        cout << ans << '\n';
    }
}

int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_cin();
    solve();

    return 0;
}