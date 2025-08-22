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


ll numbersIn(ll end, bool sub){
    ll ans = sqrtl(end);

    while (ans * ans <= end){
        ans++;
    }

    ans-= 2;

    ll add = 0;

    ll temp = (ans+1)  * (ans+1);

    if (temp <= end) {add++; temp += ans + 1;} 
    if (temp <= end) {add++; temp += ans + 1;}
    if (temp <= end) {add++;}

    ans *= 3;

    if (sub && end % (ll) sqrtl(end) == 0) add--;

    return ans + add;
}

void solve()
{
    ll s, end;
    cin >> s;
    cin >> end;

    ll ans = numbersIn(end, false) - numbersIn(s, true);

    cout << ans << '\n';
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

/* See pattern:
int count = 0;

    ll s = 1, end = 100000000000000000;

    for(ll i = s; i <= end; i++){
        ll r = sqrt(i);
        if (i % r == 0){
            cout << "i: " << i << ", r: " << r << '\n';
            count++;
        } else{
            cout << "r no: " << r << '\n';
        }
    }

    cout << "\nCount: " << count;




*/

/* Too slow
void solve()
{
    ll s, end;
    cin >> s;
    cin >> end;
    ll fr = 0;
    ll count = 0;

    forsn(i, s, end)
    {
        ll r = sqrt(i);
        if (i % r == 0)
        {
            fr = r;
            s = i;
            break;
        }
    }

    if (fr == 0)
    {
        cout << 0 << '\n';
        return;
    }

    ll p = -1;

    if (fr * fr == s){
        p = 1;
    } else if (fr * (fr +1) == s){
        p = 2;
    } else {
        p = 3;
    }
    

    ll i = s;

    while (i <= end)
    {
        count++;
        if (p == 3){
            i += 1;
            fr++;
            p = 1;
        } else {
            i += fr;
            p++;
        }
    }

    cout << count << '\n';
    cout << fr << '\n';
}


*/