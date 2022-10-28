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


void pV(vector<pair<int, int>> v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << " ";
    }
    cout << '\n';
}

void solve()
{
    int m;
    cin >> m;
    vector<pair<int, int>> ranges;
    int counter = 0;
    bool finish = false;

    if (m == 1){
        cin >> m;
        cout << 0 << '\n';
        return;
    }

    forn(i, m/2)
    {
        int a, b, temp;
        cin >> a;
        cin >> b;
        if (a > b)
        {
            temp = b;
            b = a;
            a = temp;
            counter++;
        }

        if (abs(a - b) > 1)
        {
            finish = true;
        }

        pair<int, int> p(a, b);
        ranges.push_back(p);
    }

    if (finish){
        cout << -1 << '\n';
        return;
    }

    vector<pair<int, int>> copy;
    forn(i, (m - 1 - m / 2))
    {
        for (int x = 0; x < ranges.size() - 1; x+=2)
        {
            bool cond1 = false, cond2 = false;
            if (abs(ranges[x].first - ranges[x+1].second) > 1)
                cond1 = true;


            if (abs(ranges[x].second - ranges[x+1].first) > 1)
                cond2 = true;

            if (cond1 && cond2){
                cout << -1 << '\n';
                return;
            }

            if (ranges[x].second < ranges[x+1].first){
                pair<int, int> p(ranges[x].first, ranges[x+1].second);
                copy.push_back(p);
            } else {
                pair<int, int> p(ranges[x+1].first, ranges[x].second);
                copy.push_back(p);
                counter++;
            }
        }
        ranges = copy;
        copy.clear();
        if (ranges.size() == 1) break;
    }

    cout << counter << '\n';

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
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}