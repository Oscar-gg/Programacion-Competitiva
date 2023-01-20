// Code by @Oscar-gg

// Problem from: https://codeforces.com/gym/104120/problem/l

// Template from: https://www.geeksforgeeks.org/how-to-setup-competitive-programming-in-visual-studio-code-for-c/

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
#define dbg(x) cout << #x << " = " << x << ln
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

v32 stations[1000000];
bool visited[1000000];
int parent[1000000];

int dfs(int visit, int parent, bool vis[1000000], int &cont)
{
    vis[visit] = true;
    cont++;

    for (int i = 0; i < stations[visit].size(); i++)
    {
        int current = stations[visit][i];
        if (current == parent)
            continue;
        if (!vis[current])
        {
            dfs(current, parent, vis, cont);
        }
    }
}

void solve()
{
    int n, x;
    cin >> n >> x;
    x--;

    pair<int, int> p{0, 0};

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        stations[a].push_back(b);
        stations[b].push_back(a);
    }

    queue<pair<int, int>> q;
    q.push(p);
    visited[0] = true;

    int distance = -1;
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        if (curr.first == x)
        {
            distance = curr.second;
            break;
        }
        for (int i = 0; i < stations[curr.first].size(); i++)
        {
            int neighbor = stations[curr.first][i];
            if (!visited[neighbor])
            {
                q.push({neighbor, curr.second + 1});
                visited[neighbor] = true;
                parent[neighbor] = curr.first;
            }
        }
    }

    int unvisited = 0;
    for (int i = 0; i < stations[parent[x]].size(); i++)
    {
        int curr = stations[parent[x]][i];
        if (curr == parent[parent[x]])
            continue;

        bool vis[1000000]{};
        dfs(curr, parent[x], vis, unvisited);
    }

    int ans = (n * 2) - distance - (unvisited * 2);
    cout << ans << '\n';
}

int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_cin();
    solve();
    return 0;
}