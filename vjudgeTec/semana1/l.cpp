// Code by @Oscar-gg

// Problem from:

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

void explore2(int current, vector<int> &dp, unordered_map<int, int> umap, int currentSum, int max){
    if (current > max)
        return;
    
    for (int i = 1; i < dp.size(); i++){
        // dp[]
    }

}

void solve2()
{
    ll n;
    cin >> n;
    int max_ = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;
        umap[next]++;
        max_ = max(max_, next);
    }
    // current, val
    vector<int> dp(10e5+1);
    // cout << "End";
    // explore(0, dp, umap, 0, max_);  

}


int explore(int current, vector<vector<int>> &dp, unordered_map<int, int> umap, int currentSum)
{
    if (current <= 0)
        return 0;

    if (dp[current][currentSum] != -1)
        return dp[current][currentSum];

    return dp[current][currentSum] = currentSum + max(explore(current - 2, dp, umap, currentSum) + umap[current] * current, explore(current - 1, dp, umap, currentSum));
}

void solve()
{
    ll n;
    cin >> n;
    int max_ = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;
        umap[next]++;
        max_ = max(max_, next);
    }
    // current, val
    vector<vector<int>> dp(10e5, vector<int> (10e3, -1));
    // cout << "End";
    cout << explore(max_, dp, umap, 0) << "\n";
}

int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now();
#endif
    fast_cin();
    solve();

#ifdef OSCAR_GG
    auto end = chrono::high_resolution_clock::now();
    double executionTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    executionTime *= 1e-6;
    cout << "Execution Time: " << fixed << executionTime << setprecision(6);
    cout << " ms\n";
#endif
    return 0;
}