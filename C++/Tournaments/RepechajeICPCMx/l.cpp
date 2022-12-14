// Code by @Oscar-gg

// Problem from:

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
bool found = false;
int dist = 0;

struct Node
{
    int value;
    int distance;
};

void dfs(Node node, int target)
{
    if (found)
        return;

    if (visited[node.value])
        return;

    visited[node.value] = true;

    for (int i = 0; i < stations[node.value].size(); i++)
    {
        if (stations[node.value][i] == target)
        {
            found = true;
            dist = node.distance + 1;
            return;
        }
    }

    for (int i = 0; i < stations[node.value].size(); i++)
    {
        if (found)
            return;
        Node newNode{stations[node.value][i], node.distance + 1};
        dfs(newNode, target);
    }
}

void solve()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n - 1; i++)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        stations[A].push_back(B);
        stations[B].push_back(A);
    }

    Node start{0, 0};
    dfs(start, x - 1);

    cout << dist << '\n';
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