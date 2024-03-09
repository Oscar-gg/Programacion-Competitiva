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



bool isConnected(int n1, int n2, int st, int end, unordered_map<int, unordered_map<int, pair<int, int>>> &con){
    return con[n1][n2].first < st || con[n1][n2].second > end;
}

void dfs(int cur, unordered_map<int, unordered_map<int, pair<int, int>>> &con, unordered_set<int> &visited, int st, int end){
    // cout << cur << " ";
    visited.insert(cur);
    for(auto ne : con[cur]){
        if (!visited.count(ne.first) && isConnected(cur, ne.first, st, end, con)){
            dfs(ne.first, con, visited, st, end);
        }
    }
}

int connComp(unordered_map<int, unordered_map<int, pair<int, int>>> &con, int st, int end, int n){

    unordered_set<int> visited;

    int count = 0;

    for(int i = 1; i <= n; i++){
        if (!visited.count(i)){
            count++;
            // cout << "Start dfs at " << i <<":\n";
            dfs(i, con, visited, st, end);
            // cout << "\n";
        }
    }

    return count;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, unordered_map<int, pair<int, int>>> con;

    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        if (!con[x].count(y)){
            con[x][y] = {i, i};
            con[y][x] = {i, i};
        } else {
            con[x][y] = {con[x][y].first, i};
            con[y][x] = {con[y][x].first, i};
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << i << ":\n";
    //     for(auto x: con[i]){
    //         cout << x.first << " " << x.second.first << " " << x.second.second << "\n";
    //     }
    //     cout << "\n";
    // }

    int k;
    cin >> k;

    for(int i = 0; i < k; i++){
        int st, end;
        cin >> st >> end;
        cout << connComp(con, st, end, n) << "\n";
    }

}

int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now();
#endif
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