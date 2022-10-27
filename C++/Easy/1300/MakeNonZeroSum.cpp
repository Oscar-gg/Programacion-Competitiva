// Code by @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1753/A1

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

    v32 a(n);
    v32 c;

    cin >> a[0];

    int sum = a[0];
    
    for(int i = 1 ; i< n; i++)
    {
        cin >> a[i];
        sum += (i & 1) ? a[i] * -1 : a[i];
    }

    for(int i = 1 ; i< n; i+= 2)
    {
        if (a[i - 1] != a[i])
        {
            c.push_back(i + 1);
            if (i + 2 < n)
                c.push_back(i + 2);
        }
    }

    if (n & 1)
    {
        cout << -1 << '\n';
        return;
    }

    if (sum == 0)
    {
        cout << 1 << '\n';
        cout << 1 << " " << n << '\n'; 
        return;
    }

    cout << c.size() + 1 << '\n';
    cout << 1 << " " << c[0] - 1 << '\n';

    forn(i, (c.size() - 1))
    {
        cout << c[i] << " " << c[i + 1] - 1 << '\n';
    }

    cout << c[c.size()-1 ] << " " << n << '\n';

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

/* Works for some test cases.
void solve()
{
    int n;
    cin >> n;

    v32 a(n);

    int pos = 0, neg = 0;

    int sum = 0;

    forn(i, n)
    {
        cin >> a[i];
        sum += (i & 1) ? a[i] * -1 : a[i];
    }

    if (n & 1)
    {
        cout << -1 << '\n';
        return;
    }

    if (sum == 0)
    {
        cout << 1 << '\n';
        cout << 1 << " " << n << '\n';
        return;
    }

    cout << abs(sum) << '\n';

    v32 indices;

    int index = n - 1;

    while (sum != 0 && index >= 0)
    {

        if (index % 2 == 0)
        {
            index--;
            continue;
        }

        if (sum < 0)
        {
            if (a[index] == 1)
            {
                indices.push_back(index);
                sum += 2;
            }
        }
        else if (sum > 0)
        {
            if (a[index] == -1)
            {
                indices.push_back(index);
                sum -= 2;
            }
        }
        index--;
    }

    reverse(indices.begin(), indices.end());

    cout << "1 " << indices[0] << '\n';
    for (int i = 0; i < indices.size() - 1; i++)
    {
        cout << indices[i] + 1 << " " << indices[i] + 1 << '\n';
        if (indices[i + 1] - indices[i] > 1)
          cout << indices[i] + 2 << " " << indices[i+1] << '\n';
    }

    cout << indices[indices.size() - 1] + 1 << " " << n << '\n';
}


*/