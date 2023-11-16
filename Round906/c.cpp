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
    int n;
    cin >> n;

    string s;
    cin >> s;
    int c0 = 0, c1 = 0;

    deque<char> in;

    if (s.size() & 1)
    {
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        in.push_back(s[i]);
        int num = s[i] - '0';
        if (num == 0)
            c0++;
        if (num == 1)
            c1++;
    }

    if (c0 != c1)
    {
        cout << "-1\n";
        return;
    }

    // index, -1 == is from the back
    vector<pair<int, int>> pushes;

    int indexF = 0;
    int indexB = 0;
    int totalS = s.size();

    while (!in.empty())
    {
        if (in.front() != in.back())
        {
            in.pop_front();
            in.pop_back();
            indexF++;
            indexB++;
        }
        else
        {
            // Add 01 at frontIndex, remoce the last element
            if (in.back() == '1')
            {
                pushes.push_back({indexF, 1});
                indexF++;
                in.push_front('1');
                in.pop_back();
            }
            else
            {
                // Add 01 at indexB, cancel the 
                pushes.push_back({totalS - indexB, 1});
                indexB++;
                in.push_back('0');
                in.pop_front();
            }
            totalS += 2;
        }
    }
    cout << pushes.size() << "\n";
    for (auto x : pushes)
    {
        cout << x.first << " ";
    }
    cout << "\n";
}

int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now();
#endif
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
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
