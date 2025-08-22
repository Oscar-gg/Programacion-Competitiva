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
    int n, m, j;
    cin >> n >> m >> j;

    vector<vector<char>> maze(n, vector<char>(m));
    pair<int, int> start;
    pair<int, int> end;

    vector<vector<int>> v(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'x')
                start = {i, j};
            else if (maze[i][j] == '@')
                end = {i, j};
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, start});

    v[start.first][start.second] = 0;

    vector<pair<int, int>> positions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool cont = true;

    while (!pq.empty() && cont)
    {
        auto front = pq.top();
        pq.pop();
        int curR = front.second.first;
        int curC = front.second.second;

        for (auto pos : positions)
        {
            int newR = curR + pos.first;
            int newC = curC + pos.second;
            if (newR >= 0 && newR < n && newC >= 0 && newC < m && v[newR][newC] == -1)
            {
                char c = maze[newR][newC];
                if (c == '#')
                    v[newR][newC] = INT_MAX;
                else if (c == '.')
                {
                    v[newR][newC] = front.first;
                    pq.push({front.first, {newR, newC}});
                }
                else if (c == 's')
                {
                    v[newR][newC] = front.first + 1;
                    pq.push({front.first + 1, {newR, newC}});
                }
                else if (c == '@')
                {
                    cont = false;
                    v[newR][newC] = front.first;
                    break;
                }
            }
        }
    }

    // for (auto x : v)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }

    if (v[end.first][end.second] == -1 || j < v[end.first][end.second] * 2)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << "SUCCESS\n";
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