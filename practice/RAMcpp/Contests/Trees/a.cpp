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

void getAncestors(int curr, vector<int> &current, vector<vector<int>> &tree, vector<vector<int>> &ancestors)
{
    current.push_back(curr);
    ancestors[curr] = current;

    for (int i = 0; i < tree[curr].size(); i++)
    {
        getAncestors(tree[curr][i], current, tree, ancestors);
    }

    current.pop_back();
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int next;
            cin >> next;
            tree[i].push_back(next);
        }
    }

    // for(int i = 1; i < tree.size(); i++){
    //     cout << i << ": ";
    //     for(int j = 0; j < tree[i].size(); j++){
    //         cout << tree[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    vector<vector<int>> ancestors(n + 1);
    vector<unordered_set<int>> ancestorsS(n + 1);
    vector<int> curr;

    getAncestors(1, curr, tree, ancestors);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < ancestors[i].size(); j++)
        {
            ancestorsS[i].insert(ancestors[i][j]);
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int v, w;
        cin >> v >> w;
        int l = 0;
        int r = ancestors[v].size() - 1;

        while (l < r)
        {
            int middle = l + (r - l) / 2;
            int tar = ancestors[v][middle];

            if (ancestorsS[w].count(tar))
            {
                l = middle;
            }
            else
            {
                r = middle - 1;
            }

            if (r - l == 1)
            {
                if (ancestorsS[w].count(ancestors[v][r]))
                {
                    cout << ancestors[v][r] << "\n";
                }
                else
                {
                    cout << ancestors[v][l] << "\n";
                }
                break;
            }
            if (r == l)
            {
                cout << ancestors[v][l] << "\n";
            }
        }
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
        cout << "Case " << it << ":\n";
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
