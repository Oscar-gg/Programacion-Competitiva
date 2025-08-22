// Code by @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1167/C

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

vector<int> edges[500000];
bool visited[500000];

vector<ll> locs;

ll dfs(ll person)
{
    visited[person] = 1;

    ll count = 1;

    for (int i = 0; i < edges[person].size(); i++)
    {
        if (!visited[edges[person][i]])
        {
            count += dfs(edges[person][i]);
            locs.push_back(edges[person][i]);
        }
    }

    return count;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> ans(n);

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        if (k == 0)
            continue;
        if (k == 1){
            int t; cin >> t;
            continue;
        }

        int next;
        cin >> next;
        next--;

        for (int i = 1; i < k; i++)
        {
            int next2;
            cin >> next2;
            next2--;

            edges[next].push_back(next2);
            edges[next2].push_back(next);
            next = next2;
        }
    }
#if 0
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < edges[i].size(); x++)
        {
            cout << edges[i][x] << " ";
        }
        cout << "\n";
    }
#endif
    
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            ll max = dfs(i);
            locs.push_back(i);

            for (int x = 0; x < locs.size(); x++){
                ans[locs[x]] = max;
            }
            locs.clear();
        }
    }

    for (auto i : ans){
        cout << i << " ";
    }

    cout << '\n';
}

int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_cin();
    ll t;
    t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}