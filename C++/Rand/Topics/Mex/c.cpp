// Code by @Oscar-gg

// Problem from: https://codeforces.com/contest/1867/problem/C

// Template from: https://www.geeksforgeeks.org/how-to-setup-competitive-programming-in-visual-studio-code-for-c/

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <chrono>

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
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
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

/*
Solution approach: 

- Store given numbers in array
- Have a pointer to the smallest number that doesn't appear
- Choose that number
- Choose all numbers that are played by opponent.

*/


int solve()
{
    int n;
    cin >> n;

    v32 s(n);

    // store only first 10^5, because that's the maximum amount of numbers.
    // if a number > 1e5, then it won't be part of MEX computation.
    vector<bool> in(1e5 + 1); 
    for (auto &v : s)
    {
        cin >> v;
        if (v <= 1e5 + 1)
            in[v] = true;
    }

    int max = 0;

    for (; max < in.size(); max++)
    {
        if (!in[max])
            break;
    }

    cout << max << "\n";
    cout.flush();

    int y;
    cin >> y;

    while (y != -1 && y != -2)
    {
        cout << y << "\n";
        cout.flush();
        cin >> y;
    };

    if (y == -2)
        return -1;
    return 1;
}

int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now();
#endif
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        int n = solve();
        if (n == -1)
            return 0;
    }
#ifdef OSCAR_GG
    auto end = chrono::high_resolution_clock::now();
    double executionTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    executionTime *= 1e-6;
    cout << "Execution Time: " << fixed << executionTime << setprecision(6);
    cout << " ms\n";
#endif
    return 0;
}