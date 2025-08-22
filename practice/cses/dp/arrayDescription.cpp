// Code by @Oscar-gg

// Problem from: https://cses.fi/problemset/task/1746

// Template from: https://www.geeksforgeeks.org/how-to-setup-competitive-programming-in-visual-studio-code-for-c/

// Solved with editorial (https://codeforces.com/blog/entry/70018)

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

#define mod 1000000007

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m + 1));

    vector<int> in(n);

    for (auto &v : in)
    {
        cin >> v;
    }

    if (in[0] == 0)
    {
        fill(dp[0].begin(), dp[0].end(), 1);
    }
    else
    {
        dp[0][in[0]] = 1;
    }

    // Start at 1 because first element is already checked
    for (int i = 1; i < in.size(); i++)
    {
        // Check for all posibilities
        if (in[i] == 0)
        {
            // Start with j = 1 because the numbers must be between 1 and m.
            for (int j = 1; j <= m; j++)
            {
                for (int k : {j - 1, j, j + 1})
                {
                    if (k <= m && k > 0)
                        (dp[i][j] += dp[i - 1][k]) %= mod;
                }
            }
        }
        else
        {
            // Only possibility is dp[i][in[i]] = dp[i-1][in[i] - 1] + dp[i-1][in[i]] + dp[i-1][in[i] + 1]
            int j = in[i];
            for (int k : {j - 1, j, j + 1})
            {
                if (k <= m && k > 0)
                    (dp[i][j] += dp[i - 1][k]) %= mod;
            }
        }
    }

    long long int ans = 0;
    for (int i = 1; i < dp[n-1].size(); i++){
        (ans += dp[n-1][i]) %= mod;
    }

    cout << ans << "\n";
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