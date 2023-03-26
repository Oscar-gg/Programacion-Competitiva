// Code by @Oscar-gg

// Problem from: https://codeforces.com/contest/1791/problem/F

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

unordered_map<int, int> umap;

int dCount(ll n)
{
    if (!umap.count(n))
    {
        int c = 0;
        while (n > 0)
        {
            c += n % 10;
            n /= 10;
        }
        umap[n] = c;
    }

    return umap[n];
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> changes(n);
    vector<int> changed(n);
    vector<pair<int, int>> queries;
    vector<int> qcount(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        qcount[i] = 0;
        changes[i] = 0;
    }

    for (int i = 0; i < q; i++)
    {
        int x, y, z;

        cin >> x;
        if (x == 1)
        {
            cin >> y >> z;
            y--;
            z--;
        }
        else
        {
            cin >> y;
            y--;
        }
        if (x == 1)
        {
            queries.push_back({y, z});
        }
        if (x == 2)
        {
            int start;

            for (start = qcount[y]; start < queries.size(); start++)
            {
                if (changes[y] >= 3)
                    break;
                pair<int, int> p = queries[start];
                if (p.first <= y && y <= p.second)
                {
                    changes[y]++;
                }
            }
            
            qcount[y] = start;
            while (changed[y] != changes[y])
            {
                a[y] = dCount(a[y]);
                changed[y]++;
            }
            cout << a[y] << "\n";
        }
    }
}
int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}