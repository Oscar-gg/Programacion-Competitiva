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

double getCD(int m, const vector<pair<int, double>> &dep)
{
    int c = 0;
    for (int i = 0; i < dep.size(); i++)
    {
        if (c <= dep[i].first)
        {
            c = dep[i].first;
        }
        else
        {
            return dep[c].second;
        }
    }

    return dep[0].second;
}

void solve(double m, double p, double l, double r)
{
    vector<pair<int, double>> dep;

    for (int i = 0; i < r; i++)
    {
        double month, perc;
        cin >> month >> perc;
        pair<int, double> pid{month, perc};
        dep.push_back(pid);
    }

    int ans = 0;
    double owe = l;
    double carw = p + l;

    double payement = l / m;

    carw *= getCD(ans, dep);

    while (owe < carw)
    {
        ans++;
        cout << "ans: " << ans;
        carw *= getCD(ans, dep);
        if (ans > m)
            break;
        owe -= payement;
    }

    if (ans == 1)
    {
        cout << "1 month\n";
    }
    else
    {
        cout << ans + " months\n";
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
    while (true)
    {
        double m, p, l, r;
        cin >> m >> p >> l >> r;
        if (m < 0)
            break;
        solve(m, p, l, r);
    }
#ifdef OSCAR_GG
    auto end = chrono::high_resolution_clock::now();
    double executionTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    executionTime *= 1e-6;
    cout << "Execution Time: " << fixed << executionTime << setprecision(6);
    cout << " ms\n";
#endif
    return 0;
}