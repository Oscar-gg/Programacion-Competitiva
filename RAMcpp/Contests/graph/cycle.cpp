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
    int n, m, k;
    cin >> n >> m >> k;

    if (k & 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<vector<char>> maze(n, vector<char>(m, '.'));
    vector<vector<int>> mazeW(n, vector<int>(m, INT_MAX));

    pair<int, int> pos{0, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'X')
            {
                pos = {i, j};
                maze[i][j] = '.';
                mazeW[i][j] = 0;
            }
        }
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({pos.first, {pos.second, 0}});

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        vector<pair<int, int>> adjacents{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto adj : adjacents)
        {
            int newR = front.first + adj.first;
            int newC = front.second.first + adj.second;
            if (newR >= 0 && newR < n && newC >= 0 && newC < m && maze[newR][newC] == '.' && mazeW[newR][newC] == INT_MAX)
            {
                mazeW[newR][newC] = front.second.second + 1;
                q.push({newR, {newC, mazeW[newR][newC]}});
            }
        }
    }

    // D, L, R, U
    string ans = "";
    while (k > 0)
    {
        if (pos.first + 1 < n && k >= mazeW[pos.first + 1][pos.second])
        {
            ans += "D";
            pos.first++;
        }
        else if (pos.second - 1 >= 0 && k >= mazeW[pos.first][pos.second - 1])
        {
            ans += "L";
            pos.second--;
        }
        else if (pos.second + 1 < m && k >= mazeW[pos.first][pos.second + 1])
        {
            ans += "R";
            pos.second++;
        }
        else if (pos.first - 1 >= 0 && k >= mazeW[pos.first - 1][pos.second])
        {
            ans += "U";
            pos.first--;
        }
        else
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        k--;
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
