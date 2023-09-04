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

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> hours(n);

    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        hours[i] = h;
    }

    vector<vector<int>> depOut(n);

    vector<int> depIn(n);
    for (int i = 0; i < m; i++)
    {
        int dep1, dep2;
        cin >> dep1 >> dep2;
        dep1--;
        dep2--;
        depOut[dep1].push_back(dep2);
        depIn[dep2]++;
    }

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (!depIn[i])
            q.push(i);
    }

    int ans = 0;
    bool first = true;

    while (q.size())
    {
        int level = q.size();
        int minHours = k;
        int maxHours = 0;
        for (int i = 0; i < level; i++)
        {
            int next = q.front();
            q.pop();
            minHours = min(hours[next], minHours);
            maxHours = max(hours[next], maxHours);

            for (auto x : depOut[next])
            {
                depIn[x]--;
                if (depIn[x] == 0)
                    q.push(x);
                if (depIn[x] == 0 && hours[x] >= hours[next])
                    level++;
            }
        }

        if (first && !q.size())
        {
            ans = maxHours - minHours;
        }
        else if (first)
        {
            ans = k - minHours;
        }
        else if (!q.size())
        {
            ans += maxHours;
        }
        else
        {
            ans += k;
        }
        first = false;
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
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
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