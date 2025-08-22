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

ll query(ll treePosition, ll leftQ, ll rightQ, ll left, ll right, vector<ll> &tree)
{
    // cout << treePosition << " " << leftQ << " " << rightQ << " " << left << " " << right << "\n";
    if (leftQ <= rightQ)
    {
        if (leftQ == left && rightQ == right)
            return tree[treePosition];

        ll middle = left + (right - left) / 2;

        ll leftSum = query(treePosition * 2, leftQ, min(rightQ, middle), left, middle, tree);
        ll rightSum = query(treePosition * 2 + 1, max(middle + 1, leftQ), rightQ, middle + 1, right, tree);

        return leftSum + rightSum;
    }

    return 0;
}

void update(ll treePosition, ll index, ll value, ll left, ll right, vector<ll> &tree)
{
    if (left <= right)
    {
        if (left == right)
        {
            tree[treePosition] = value;
            return;
        }
        ll middle = left + (right - left) / 2;

        if (index <= middle)
        {
            update(treePosition * 2, index, value, left, middle, tree);
        }
        else
        {
            update(treePosition * 2 + 1, index, value, middle + 1, right, tree);
        }

        tree[treePosition] = tree[treePosition * 2] + tree[treePosition * 2 + 1];
    }
}

void build(ll position, ll left, ll right, vector<ll> &tree, vector<ll> &values)
{
    if (left <= right)
    {
        if (left == right)
        {
            tree[position] = values[left];
            return;
        }
        ll middle = left + (right - left) / 2;
        build(position * 2, left, middle, tree, values);
        build(position * 2 + 1, middle + 1, right, tree, values);
        tree[position] = tree[position * 2] + tree[position * 2 + 1];
    }
}

void solve()
{

    int n, q;
    cin >> n >> q;
    vector<ll> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    vector<ll> tree(4 * n);
    build(1, 0, n - 1, tree, values);
    // for (auto x : tree)
    //     cout << x << " ";
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            b--;
            update(1, b, c, 0, n - 1, tree);
        }
        else
        {
            b--;
            c--;
            cout << query(1, b, c, 0, n - 1, tree) << "\n";
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