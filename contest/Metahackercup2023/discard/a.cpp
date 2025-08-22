// Code by @Oscar-gg

// Problem from:

// Template from: https://www.geeksforgeeks.org/how-to-setup-competitive-programming-in-visual-studio-code-for-c/

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <chrono>
#include <iomanip> // Include the iomanip header for setprecision and fixed manipulators

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

void solve()
{
    int n;
    cin >> n;
    priority_queue<int> pq;                            // 3 greatest elements
    priority_queue<int, vector<int>, greater<int>> gq; // 3 smallest elements

    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;
        pq.push(next);
        gq.push(next);
        if (pq.size() > 3)
            pq.pop();
        if (gq.size() > 3)
            gq.pop();
    }

    vector<long double> vals;
    while (!pq.empty())
    {
        vals.push_back(pq.top());
        pq.pop();
    }
    while (!gq.empty())
    {
        vals.push_back(gq.top());
        gq.pop();
    }
    sort(vals.begin(), vals.end());

    if (n != 5)
    {
        long double s1 = vals[0];
        long double s2 = vals[1];
        long double e1 = vals[vals.size() - 2];
        long double e2 = vals[vals.size() - 1];
        cout << (e1 + e2) / 2 - (s1 + s2) / 2 << endl;
    }
    else
    {
        long double s1 = vals[0];
        long double s2 = vals[1];
        long double s3 = vals[3];

        long double e1 = vals[vals.size() - 2];
        long double e2 = vals[vals.size() - 1];
        long double e3 = vals[vals.size() - 3];

        long double op1 = (e3 + e1) / 2 - (s1 + s2) / 2;
        long double op2 = (e2 + e1) / 2 - (s1 + s3) / 2;

        long double ans = max(op1, op2);
        std::cout << std::fixed << std::setprecision(11) << ans << std::endl;
    }
}

int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now();
#endif
    // fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        cout << "Case #" << it << ": ";
        solve();
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