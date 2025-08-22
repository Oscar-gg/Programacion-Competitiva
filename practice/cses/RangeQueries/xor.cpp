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

int query(int treePosition, int leftQ, int rightQ, int left, int right, vector<int> &tree)
{
    if (leftQ <= rightQ)
    {
        if (leftQ == left && rightQ == right)
        {
            return tree[treePosition];
        }
        int middle = left + (right - left) / 2;
        int leftValue = query(treePosition * 2, leftQ, min(middle, rightQ), left, middle, tree);
        int rightValue = query(treePosition * 2 + 1, max(middle + 1, leftQ), rightQ, middle + 1, right, tree);
        return leftValue ^ rightValue;
    }

    return 0;
}

void build(int treePosition, int left, int right, vector<int> &tree, vector<int> &values)
{
    if (left <= right)
    {
        if (left == right)
        {
            tree[treePosition] = values[left];
            return;
        }
        int middle = left + (right - left) / 2;
        build(treePosition * 2, left, middle, tree, values);
        build(treePosition * 2 + 1, middle + 1, right, tree, values);
        tree[treePosition] = tree[treePosition * 2] ^ tree[treePosition * 2 + 1];
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> values(n);

    vector<int> tree(4 * n);

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    build(1, 0, n - 1, tree, values);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << query(1, a, b, 0, n - 1, tree) << "\n";
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