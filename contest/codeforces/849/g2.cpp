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
typedef tuple<int, int, int> t32;
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
#define dbg(v)																 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ln "\n"
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

void cwstart(int &n, int &c, v32 &a)
{
    vector<bool> visited(n, false);
    priority_queue<t32, vector<t32>, greater<t32>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({a[i] + i + 1, i, 1});
    }

    t32 f = pq.top();
    pq.pop();
    visited[get<1>(f)] = true;

    ll sum = 0;
    int ans = 0;

    if (get<0>(f) > c)
    {
        cout << "0\n";
        return;
    }
    ans++;
    sum += get<0>(f);
    int count = 1;
    for (int i = n - 1; i > n / 2; i--)
    {
        pq.push({a[i] + count, i, 2});
        count++;
    }

    while (ans < n)
    {
        dbg(ans);

        t32 p = pq.top();
        pq.pop();
        if (!visited[get<1>(p)])
        {
            sum += get<0>(p);
            visited[get<1>(p)] = true;
        }
        else
        {
            continue;
        }

        if (sum > c)
            break;
        ans++;
    }

    cout << ans << '\n';
}

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    vector<bool> visited(n, false);

    priority_queue<t32, vector<t32>, greater<t32>> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n / 2 + 1; i++)
    {
        pq.push({a[i] + i + 1, i, 1});
        pq.push({a[n - 1 - i] + i + 1, n - 1 - i, 2});
    }

    ll sum = 0;
    int ans = 0;
    bool firsth = false;

    while (ans < n)
    {

        t32 p = pq.top();
        pq.pop();
        
        if (!visited[get<1>(p)])
        {
            sum += get<0>(p);
            visited[get<1>(p)] = true;
        }
        else
        {
            continue;
        }

        if (sum > c)
            break;

        if (get<2>(p) == 1)
        {
            firsth = true;
        }
        ans++;
    }
    if (firsth)
        cout << ans << '\n';
    else
    {
        cwstart(n, c, a);
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