// Code by @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1746/C

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

void solve()
{
    int n;
    cin >> n;

    v32 v(n);
    int next;

    forn(i, n){
        cin >> v[i];
    }

    unordered_map<int, vector<int>> umap;

    int max = 0;

    forn(i, n){
        if (v[i] > max){
            max = v[i];
        }
        if (v[i] - max < 0){
            umap[max-v[i]].push_back(i);
        }
    }

    int counter = 0;
    int internalCounter = 0;

    for (int i = 0; i < n; i++){
        if (umap.count(i)){
            for (int x = 0; x < umap[i].size(); x++){
                cout << (umap[i][x] + 1) << " ";
                counter++;
                internalCounter += counter;
                if (internalCounter < i){
                    x--;
                } else {
                    internalCounter = 0;
                }
            }
        }
    }

    while(counter < v.size()){
        cout << n << " ";
        counter++;
    }

    cout << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 0; it < t; it++)
    {
        solve();
    }
    return 0;
}