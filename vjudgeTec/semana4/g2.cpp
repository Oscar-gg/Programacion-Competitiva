// Rbrgs.cpp
#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define RFOR(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define FORC(it, cont) for (auto it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(it, cont) for (auto it = (cont).rbegin(); it != (cont).rend(); it++)
#define aFor(i, a) for (auto &i : a)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;
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
        if (board[i][n - 1] == '.')
            if (!findPair(entry, {i, n - 1}))
                entry.push_back({i, n - 1});
    }
    for (int i = 0; i < n; i++)
    {
        if (board[0][i] == '.')
            if (!findPair(entry, {0, i}))
                entry.push_back({0, i});
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
    sync;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}