// Code by @Oscar-gg

// Problem from: https://codeforces.com/contest/1375/problem/D (Replace by MEX)

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

- Given the current array of values, find the mex.
- Place the mex in its index, updating the values and computing the new mex. This ensures the result is always non-decreasing.
- If the position hasn't been visited, increase the count of 'done' elements, continue
  the process until the elements are of size n.

- If the mex is equal to n, place the mex in n-1 position (otherwise, it's out of bounds).
  Update the new max unfilled element.

*/

void solve()
{
    int n;
    cin >> n;

    v32 a(n);

    for (auto &v : a)
    {
        cin >> v;
    }

    set<int> missing;
    unordered_set<int> visited;
    unordered_map<int, int> umap;

    for (int i = 0; i <= n; i++)
    {
        missing.insert(i);
    }

    for (auto x : a)
    {
        umap[x]++;
        missing.erase(x);
    }

    int done = 0;
    v32 indeces;
    int topUnsorted = n;

    while (done < n)
    {
        int mex = *missing.begin();

        if (mex == topUnsorted)
        {
            indeces.push_back(topUnsorted - 1);
            umap[a[topUnsorted - 1]]--;

            if (umap[a[topUnsorted - 1]] == 0)
                missing.insert(a[topUnsorted - 1]);

            a[topUnsorted - 1] = topUnsorted;

            if (umap[topUnsorted] == 0)
                missing.erase(topUnsorted);

            umap[topUnsorted]++;
            topUnsorted--;

            if (!visited.count(mex))
            {
                done++;
                visited.insert(mex);
            }
        }
        else
        {
            indeces.push_back(mex);

            umap[a[mex]]--;

            if (umap[a[mex]] == 0)
                missing.insert(a[mex]);

            if (umap[mex] == 0)
            {
                missing.erase(mex);
            }

            umap[mex]++;

            if (!visited.count(mex))
            {
                done++;
                visited.insert(mex);
            }

            a[mex] = mex;
        }

        // cout << "mex: " << mex << ", ";
        // cout << "it: ";
        // for (auto x : a)
        // {
        //     cout << x << " ";
        // }
        // cout << "\n";
    }

    cout << indeces.size() << "\n";
    for (auto x : indeces)
        cout << x + 1 << " ";
    cout << "\n";
    // for (auto x : a)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
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