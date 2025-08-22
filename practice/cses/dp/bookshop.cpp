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

// Recursive - TLE
// int knapSack(int book, int cost, vector<int> &pr, vector<int> &pa, vector<vector<int>> &dp)
// {
//     if (book <= 0)
//         return 0;

//     if (dp[book][cost] != -1)
//         return dp[book][cost];

//     if (pr[book - 1] > cost)
//     {
//         return dp[book][cost] = knapSack(book - 1, cost, pr, pa, dp);
//     }
//     else
//     {
//         dp[book][cost] = max(pa[book - 1] + knapSack(book - 1, cost - pr[book - 1], pr, pa, dp),
//                              knapSack(book - 1, cost, pr, pa, dp));
//         return dp[book][cost];
//     }
// }

// Bottom up (de aquí para arriba)
int knapSack(vector<int> &pr, vector<int> &pa, vector<vector<int>> &dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (j - pr[i - 1] >= 0)
                {
                    dp[i][j] = max(dp[i - 1][j], pa[i - 1] + dp[i - 1][j - pr[i - 1]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    return dp[dp.size() - 1][dp[dp.size() - 1].size() - 1];
}

void solve()
{
    int n, x;
    cin >> n >> x;

    v32 pr(n), pa(n);
    for (auto &y : pr)
        cin >> y;

    for (auto &y : pa)
        cin >> y;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));

    cout << knapSack(pr, pa, dp) << "\n";
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

/*
// Recursive - TLE
int knapSack(int book, int cost, vector<int> &pr, vector<int> &pa, vector<vector<int>> &dp)
{
    if (book <= 0)
        return 0;

    if (dp[book][cost] != -1)
        return dp[book][cost];

    if (pr[book - 1] > cost)
    {
        return dp[book][cost] = knapSack(book - 1, cost, pr, pa, dp);
    }
    else
    {
        dp[book][cost] = max(pa[book - 1] + knapSack(book - 1, cost - pr[book - 1], pr, pa, dp),
                             knapSack(book - 1, cost, pr, pa, dp));
        return dp[book][cost];
    }
}

void solve()
{
    int n, x;
    cin >> n >> x;

    v32 pr(n), pa(n);
    for (auto &y : pr)
        cin >> y;

    for (auto &y : pa)
        cin >> y;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));

    cout << knapSack(n, x, pr, pa, dp) << "\n";

}
*/