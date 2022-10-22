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

void printArray(v32 v)
{
    forn(i, v.size())
    {
        cout << v[i] << " ";
    }
}

void modifyArray(v32 &v, int add)
{
    forn(i, v.size())
    {
        v[i] += add;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_cin();
    cout << "Get subsets from set of size n\n";

    bitset<10> bset;

    vector<int> subset;
    int n = 4;

    for (int b = 0; b < (1 << n); b++)
    {
        for (int i = 0; i < n; i++){
            if (b & (1 << i)) subset.push_back(i);
        }
        subset.push_back(-1);
    }

    for (auto x : subset){
        if (x == -1) {
            cout << '\n'; // Split sets in rows.
            continue;
        }
        cout << x << " ";
    }

    return 0;
}

/*




*/