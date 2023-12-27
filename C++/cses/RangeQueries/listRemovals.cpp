// Code by @Oscar-gg

// Problem from: https://cses.fi/problemset/task/1749

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

void update(int treeIndex, int position, int left, int right, vector<int> &segTree)
{
    // cout << leftQ << " " << rightQ << " " << left << " " << right << "\n";

    if (left <= right)
    {
        if (left == right)
        {
            segTree[treeIndex] = 0;
            return;
        }
        int middle = (left + right) / 2;
        
        if (position <= middle){
            update(treeIndex * 2, position, left, middle, segTree);
        } else{
            update(treeIndex * 2 + 1, position, middle + 1, right, segTree);
        }

        segTree[treeIndex] = segTree[treeIndex * 2] + segTree[treeIndex * 2 + 1];
    }
}

int compute(int position, int index, int left, int right, vector<int> &segTree)
{
    // cout << position << " " << segTree[position * 2] << " " << index << " " << left << " " << right << "\n";
    if (left <= right)
    {
        if (left == right)
        {
            return left;
        }

        int remainingLeft = segTree[position * 2];
        int middle = left + (right - left) / 2;
        // cout << "remleft: " << remainingLeft << ", index: " << index << "\n";
        // dbg(middle);
        if (index <= remainingLeft)
        {
            return compute(position * 2, index, left, middle, segTree);
        }
        else
        {
            return compute(position * 2 + 1, index - remainingLeft, middle + 1, right, segTree);
        }
    }

    return -1;
}

void build(int position, int left, int right, vector<int> &tree)
{
    if (left <= right)
    {
        if (left == right)
        {
            tree[position] = 1;
            return;
        }
        int middle = left + (right - left) / 2;
        build(position * 2, left, middle, tree);
        build(position * 2 + 1, middle + 1, right, tree);
        tree[position] = tree[position * 2] + tree[position * 2 + 1];
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> list(n);

    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }

    vector<int> updates(4 * n);

    build(1, 0, n - 1, updates);

    for (int i = 0; i < n; i++)
    {
        int index;
        cin >> index;

        int result = compute(1, index, 0, n - 1, updates);
        // cout << "res: " << result << "\n";
        cout << list[result] << " ";
        update(1, result, 0, n - 1, updates);
        // for (auto x : updates)
        // {
        //     cout << x << " ";
        // }
        // cout << "\n";
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