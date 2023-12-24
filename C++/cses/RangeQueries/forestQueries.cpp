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
    int n, q;
    cin >> n >> q;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<vector<int>> values(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char next;
            cin >> next;
            if (next == '*')
            {
                values[i][j]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + values[i - 1][j - 1];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1-1][x1-1] << "\n";
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

// TLE 2
// int query(int treeIndex, int leftQ, int rightQ, int left, int right, vector<int> &tree)
// {
//     if (leftQ <= rightQ)
//     {
//         if (leftQ == left && rightQ == right)
//         {
//             return tree[treeIndex];
//         }
//         int middle = left + (right - left) / 2;
//         int leftCount = query(treeIndex * 2, leftQ, min(rightQ, middle), left, middle, tree);
//         int rightCount = query(treeIndex * 2 + 1, max(middle + 1, leftQ), rightQ, middle + 1, right, tree);
//         return leftCount + rightCount;
//     }

//     return 0;
// }

// void querySegment(int treeIndex, int leftQ, int rightQ, int left, int right, vector<vector<int>> &tree, int n, vector<int> &segment)
// {
//     if (leftQ <= rightQ)
//     {
//         if (leftQ == left && rightQ == right)
//         {
//             for (int i = 0; i < segment.size(); i++)
//             {
//                 segment[i] += tree[treeIndex][i];
//             }
//             return;
//         }
//         int middle = left + (right - left) / 2;
//         querySegment(treeIndex * 2, leftQ, min(rightQ, middle), left, middle, tree, n, segment);
//         querySegment(treeIndex * 2 + 1, max(middle + 1, leftQ), rightQ, middle + 1, right, tree, n, segment);

//         // for (int i = 0; i < 4 * n; i++)
//         // {
//         //     newSegment[i] = leftSegment[i] + rightSegment[i];
//         // }

//         // return newSegment;
//     }
//     // vector<int> empty(4 * n, 0);
//     // return empty;
// }

// void buildOneSegment(int treeIndex, int left, int right, vector<int> &dest, vector<int> &values)
// {
//     if (left <= right)
//     {
//         if (left == right)
//         {
//             dest[treeIndex] = values[left];
//             return;
//         }
//         int middle = left + (right - left) / 2;
//         buildOneSegment(treeIndex * 2, left, middle, dest, values);
//         buildOneSegment(treeIndex * 2 + 1, middle + 1, right, dest, values);
//         dest[treeIndex] = dest[treeIndex * 2] + dest[treeIndex * 2 + 1];
//     }
// }

// void build(int treeIndex, int left, int right, vector<vector<int>> &tree, vector<vector<int>> &values, int n)
// {

//     if (left <= right)
//     {
//         if (left == right)
//         {
//             buildOneSegment(1, 0, n - 1, tree[treeIndex], values[left]);
//             return;
//         }

//         int middle = left + (right - left) / 2;

//         build(treeIndex * 2, left, middle, tree, values, n);
//         build(treeIndex * 2 + 1, middle + 1, right, tree, values, n);

//         vector<int> segment(4 * n);

//         for (int i = 0; i < 4 * n; i++)
//         {
//             segment[i] = tree[treeIndex * 2][i] + tree[treeIndex * 2 + 1][i];
//         }
//         tree[treeIndex] = segment;
//     }
// }

// int queryTree(int x, int x2, int y, int y2, vector<vector<int>> &tree, int n)
// {
//     int yMin = min(y, y2);
//     int yMax = max(y, y2);
//     int xMin = min(x, x2);
//     int xMax = max(x, x2);
//     vector<int> segment(4 * n);
//     querySegment(1, yMin, yMax, 0, n - 1, tree, n, segment);

//     // cout << "Segment for " << yMin << " " << yMax << "\n";
//     // for (auto x : segment)
//     // {
//     //     cout << x << " ";
//     // }

//     // cout << "\n";

//     return query(1, xMin, xMax, 0, n - 1, segment);
// }

// TLE

// int query(int treeIndex, int leftQ, int rightQ, int left, int right, vector<int> &tree)
// {
//     if (leftQ <= rightQ)
//     {
//         if (leftQ == left && rightQ == right)
//         {
//             return tree[treeIndex];
//         }
//         int middle = left + (right - left) / 2;
//         int leftCount = query(treeIndex * 2, leftQ, min(rightQ, middle), left, middle, tree);
//         int rightCount = query(treeIndex * 2 + 1, max(middle + 1, leftQ), rightQ, middle + 1, right, tree);
//         return leftCount + rightCount;
//     }

//     return 0;
// }

// void build(int treeIndex, int left, int right, vector<int> &tree, vector<char> &values)
// {
//     if (left <= right)
//     {
//         if (left == right)
//         {
//             if (values[left] == '*')
//                 tree[treeIndex] = 1;
//             return;
//         }

//         int middle = left + (right - left) / 2;

//         build(treeIndex * 2, left, middle, tree, values);
//         build(treeIndex * 2 + 1, middle + 1, right, tree, values);
//         tree[treeIndex] = tree[treeIndex * 2] + tree[treeIndex * 2 + 1];
//     }
// }

// void solve()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<vector<int>> segTree(n, vector<int>(4 * n));
//     vector<bool> forest(n);

//     for (int i = 0; i < n; i++)
//     {
//         vector<char> values(n);
//         for (int j = 0; j < n; j++)
//         {
//             cin >> values[j];
//         }
//         build(1, 0, n - 1, segTree[i], values);
//     }

//     for (int i = 0; i < q; i++)
//     {
//         int y1, x1, y2, x2;
//         cin >> y1 >> x1 >> y2 >> x2;
//         y1--;
//         y2--;
//         x1--;
//         x2--;

//         int yMin = min(y1, y2);
//         int yMax = max(y1, y2);

//         int xMin = min(x1, x2);
//         int xMax = max(x1, x2);

//         int answer = 0;

//         for (int i = yMin; i <= yMax; i++)
//         {
//             answer += query(1, xMin, xMax, 0, n - 1, segTree[i]);
//         }

//         cout << answer << "\n";
//     }
// }