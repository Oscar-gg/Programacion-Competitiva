// Code by @Oscar-gg

// Problem from: https://codeforces.com/contest/1881/problem/F
// Checked editorial

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

void bfs(int start, int &furthest, int &distance, vector<vector<int>> &g, unordered_set<int> &uset)
{
    queue<pair<int, int>> q;
    unordered_set<int> v;
    q.push({start, 0});
    v.insert(start);

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        if (uset.count(front.first) && front.second > distance)
        {
            furthest = front.first;
            distance = front.second;
        }

        for (auto n : g[front.first])
        {
            if (!v.count(n))
            {
                v.insert(n);
                q.push({n, front.second + 1});
            }
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    unordered_set<int> m;
    int some = 0;
    for (int i = 0; i < k; i++)
    {
        int next;
        cin >> next;
        m.insert(next);
        some = next;
    }

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (k == 1)
    {
        cout << 0 << "\n";
    }
    else
    {
        int furthest = 0, ig = 0, d2 = 0;
        int distance = 0;
        bfs(some, furthest, distance, g, m);
        // cout << "d1: " << distance << "\n";
        bfs(furthest, ig, d2, g, m);
        // cout << "d2: " << d2 << "\n";
        cout << (d2 + 1) / 2 << "\n";
    }
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