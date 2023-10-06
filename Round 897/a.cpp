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

// TLE
// void bfs(vector<int> &cur, unordered_set<int> &diff, unordered_set<int> &usedNums, vector<int> &info, int size)
// {

//     if (cur.size() == size)
//         return;

//     for (int i = 1; i <= size; i++)
//     {
//         if (cur.size() == size)
//             return;

//         int diffN = info[cur.size()] - i;
//         if (!usedNums.count(i) && !diff.count(diffN))
//         {
//             cur.push_back(i);
//             usedNums.insert(i);
//             diff.insert(diffN);
//             bfs(cur, diff, usedNums, info, size);
//             if (cur.size() == size)
//             {
//                 return;
//             }
//             else
//             {
//                 usedNums.erase(i);
//                 diff.erase(diffN);
//                 cur.pop_back();
//             }
//         }
//     }
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     v32 info(n);
//     for (auto &v : info)
//     {
//         cin >> v;
//     }
//     v32 ans;
//     unordered_set<int> diff, usedNums;
//     bfs(ans, diff, usedNums, info, n);
    
//     for (auto x : ans){
//         cout << x << " ";
//     }
//     cout << "\n";
//     //void bfs(vector<int> &cur, unordered_set<int> &diff, unordered_set<int> &usedNums, vector<int> &info, int size)

// }

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> info(n);
    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;
        info[i] = {next, i};
    }
    sort(info.rbegin(), info.rend());
    v32 ans(n);
    
    for (int i = 1; i <= n; i++){
        ans[info[i-1].second] = i;
    }

    for (auto x : ans){
        cout << x << " ";
    }

    cout << "\n";
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