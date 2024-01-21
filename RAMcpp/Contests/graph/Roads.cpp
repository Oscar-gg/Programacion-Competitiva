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

void makeElement(int v, vector<int> &parent, vector<int> &size)
{
    parent[v] = v;
    size[v] = 1;
}

int findParent(int v, vector<int> &parent)
{
    if (parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent);
}

void merge(int a, int b, vector<int> &parent, vector<int> &size)
{
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (size[a] < size[b])
        swap(a, b);

    parent[b] = a;
    size[a] += size[b];
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> size(n + 1);

    for (int i = 1; i <= n; i++)
    {
        makeElement(i, parent, size);
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        merge(u, v, parent, size);
    }

    vector<pair<int, int>> newR;

    for (int i = 2; i <= n; i++)
    {
        if (findParent(i, parent) != findParent(1, parent))
        {
            newR.push_back({1, i});
            merge(1, i, parent, size);
        }
    }

    cout << newR.size() << "\n";

    for (int i = 0; i < newR.size(); i++)
    {
        cout << newR[i].first << " " << newR[i].second << "\n";
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