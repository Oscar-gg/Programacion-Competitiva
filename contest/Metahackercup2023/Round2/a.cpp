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

bool validPos(vector<vector<char>> &board, int row, int col)
{
    if (row >= board.size() || col >= board[0].size())
    {
        return false;
    }
    return true;
}

bool addCell(vector<vector<char>> &board, int row, int col)
{

    vector<pair<int, int>> pos{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    for (auto x : pos)
    {
        int newR = x.first + row;
        int newC = x.second + col;
        if (validPos(board, newR, newC))
        {
            if (board[newR][newC] == '.')
                return false;
        }
    }

    return true;
}

void canBeAdded(vector<vector<char>> &board, int row, int col, int &count, vector<vector<bool>> &v)
{
    if (count == -1)
        return;

    if (!addCell(board, row, col))
    {
        count = -1;
        return;
    }
    if (validPos(board, row, col) && (v[row][col] || board[row][col] == 'B'))
        return;

    if (board[row][col] == 'W')
    {

        count++;
        v[row][col] = true;
        vector<pair<int, int>> pos{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for (auto x : pos)
        {
            int newR = x.first + row;
            int newC = x.second + col;

            if (validPos(board, newR, newC) && board[newR][newC] == 'W')
            {
                canBeAdded(board, newR, newC, count, v);
                // cout << "Second call\n";
                // cout << row << " " << col << "\n\n";
            }
        }
    }
}

void solve()
{
    int r, c;
    cin >> r >> c;

    vector<vector<char>> board(r, vector<char>(c));

    int ans = -1;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '.')
            {
                int temp = 0;

                board[i][j] = 'B';

                vector<pair<int, int>> pos{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

                // cout << "EXPLORED: " << i << " " << j << "\n";
                for (auto x : pos)
                {
                    int newR = x.first + i;
                    int newC = x.second + j;

                    if (validPos(board, newR, newC) && board[newR][newC] == 'W')
                    {
                        int count = 0;
                        vector<vector<bool>> visited(r, vector<bool>(c));
                        canBeAdded(board, newR, newC, count, visited);
                        temp += max(count, 0);
                    }
                }

                board[i][j] = '.';

                ans = max(ans, temp);
            }
        }
    }

    // cout << ans << "\n";
    if (ans > 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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
        cout << "Case #" << it << ": ";
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