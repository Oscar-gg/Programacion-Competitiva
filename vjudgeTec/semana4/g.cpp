

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

bool validPos(vector<vector<char>> board, pair<int, int> pos)
{
    return (pos.first >= 0 && pos.first < board.size() && pos.second >= 0 && pos.second < board[0].size());
}

bool dfs(vector<vector<char>> &board, pair<int, int> pos, int tarX, int tarY)
{
    if (pos.first == tarX && pos.second == tarY)
    {
        return true;
    }

    // for (auto x : board)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n\n";

    vector<pair<int, int>> next{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    for (auto x : next)
    {
        int nextX = x.first + pos.first;
        int nextY = x.second + pos.second;
        if (validPos(board, {nextX, nextY}) && board[nextX][nextY] == '.')
        {
            board[nextX][nextY] = '#';
            if (dfs(board, {nextX, nextY}, tarX, tarY))
            {
                return true;
            }
        }
    }

    return false;
}

bool findPair(vector<pair<int, int>> p, pair<int, int> n)
{
    for (auto x : p)
    {
        if (n.first == x.first && n.second == x.second)
            return true;
    }
    return false;
}

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<pair<int, int>> entry;
    for (int i = 0; i < m; i++)
    {
        if (board[i][0] == '.')
            if (!findPair(entry, {i, 0}))
                entry.push_back({i, 0});
        if (board[0][i] == '.')
            if (!findPair(entry, {0, i}))
                entry.push_back({0, i});
        if (board[i][n - 1] == '.')
            if (!findPair(entry, {i, n - 1}))
                entry.push_back({i, n - 1});
        if (board[m - 1][i] == '.')
            if (!findPair(entry, {m - 1, i}))
                entry.push_back({m - 1, i});
    }

    if (entry.size() != 2)
    {
        cout << "invalid\n";
        return;
    }

    board[entry[0].first][entry[0].second] = '#';

    if (dfs(board, entry[0], entry[1].first, entry[1].second))
    {
        cout << "valid\n";
    }
    else
    {
        cout << "invalid\n";
    }
}
int main()
{

    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }

    return 0;
}