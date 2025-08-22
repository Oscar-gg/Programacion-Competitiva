// Code by @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1759/D

// solved after reading editorial.

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

int getZeros(ll i)
{
    int count = 0;

    while (i > 0)
    {
        if ((i % 10) == 0){
            count++;
            i /= 10;
        } else {
            break;
        }
    }

    return count;
}

void solve()
{
    ll n, m;
    cin >> n;
    cin >> m;

    ll cn = n, cm = m;

    int c2 = 0, c5 = 0;

    while (cn % 2 == 0 && cn > 0){
        c2++; 
        cn /=2;
    }
    while (cn % 5 == 0 && cn > 0){
        c5++; 
        cn /= 5;
    }
    ll k = 1;

    while (c5 > c2 && k * 2 <= m){
        k *= 2;
        c2++;
    }

    while (c2 > c5 && k *5 <= m){
        k *= 5;
        c5++;
    }

    while (k * 10 <= m){
        k *= 10;
    }

    int q = m/k;

    k *= q;

    ll ans = k * n;

    if (getZeros(n) >= getZeros(ans)){
        ans = n * m;
    }
    cout << ans << '\n';
}


int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_cin();
    ll t;
    cin >> t;

    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}