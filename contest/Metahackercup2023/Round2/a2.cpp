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
    return row < board.size() && col < board[0].size();
}

void solve()
{
    int r, c;
    cin >> r >> c;

    vector<vector<char>> board(r, vector<char>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
        }
    }
    vector<vector<char>> oBoard = board;

    vector<vector<pair<int, int>>> componentSize(r, vector<pair<int, int>>(c));
    int id = 1;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'W')
            {
                board[i][j] = 'B';
                int count = 1;

                vector<pair<int, int>> current;
                current.push_back({i, j});
                queue<pair<int, int>> q;
                q.push({i, j});
                unordered_set<string> dots;

                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    vector<pair<int, int>> moves{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
                    for (auto x : moves)
                    {
                        int newR = cur.first + x.first;
                        int newC = cur.second + x.second;

                        if (validPos(board, newR, newC))
                        {
                            if (board[newR][newC] == '.')
                            {
                                dots.insert(to_string(newR) + " " + to_string(newC));
                            }
                            else if (board[newR][newC] == 'W')
                            {
                                current.push_back({newR, newC});
                                count++;
                                board[newR][newC] = 'B';
                                q.push({newR, newC});
                            }
                        }
                    }
                }

                if (dots.size() == 1)
                {
                    for (auto x : current)
                    {
                        componentSize[x.first][x.second] = {count, id};
                    }
                }
                id++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (oBoard[i][j] == '.')
            {
                vector<pair<int, int>> moves{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
                unordered_set<int> ids;

                int temp = 0;

                for (auto x : moves)
                {
                    int newR = i + x.first;
                    int newC = j + x.second;

                    if (validPos(board, newR, newC) && !ids.count(componentSize[newR][newC].second))
                    {
                        temp += componentSize[newR][newC].first;
                        ids.insert(componentSize[newR][newC].second);
                    }
                }
                ans = max(ans, temp);
            }
        }
    }

    cout << ans << "\n";
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