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

ll sToNum(string s)
{
    unordered_map<char, int> tmap;

    string alph = "abcdefghijklmnopqrstuvwxyz";
    v32 val{2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

    for (int i = 0; i < alph.length(); i++)
    {
        tmap[alph[i]] = val[i];
    }

    ll num = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char curr = s[i];
        int numCurr = tmap[curr];
        num += numCurr;
        num *= 10;
    }
    num /= 10;

    return num;
}

void solve()
{
    ll n, q;
    cin >> n >> q;

    unordered_map<ll, ll> umap;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ll key = sToNum(s);

        if (umap.count(key))
        {
            umap[key]++;
        }
        else
        {
            umap[key] = 1;
        }
    }

    for (ll i = 0; i < q; i++)
    {
        ll query;
        cin >> query;
        cout << umap[query] << '\n';
    }
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