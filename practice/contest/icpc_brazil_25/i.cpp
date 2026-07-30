#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define RFOR(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define FORC(cont, it) for (typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for (typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define all(x) x.begin(), x.end()
#define nl << "\n"
#define MAXN 10
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};

void r(pair<ll, ll> &p)
{
    cin >> p.first >> p.second;
}

ll e(pair<ll, ll> &p, pair<ll, ll> &p2)
{

    if (p.first != p2.first)
    {
        return abs(p.first - p2.first);
    }
    else
    {
        return abs(p.second - p2.second);
    }
}

void s()
{
    ll n;
    cin >> n;
    vector<ll> d(n - 1);

    pair<ll, ll> p, p2;
    r(p);

    for (ll i = 1; i < n; i++)
    {
        r(p2);
        d[i - 1] = e(p, p2);
        p = p2;
    }

    ll even = 0, odd = 0;

    ll min_ = 1, max_ = d[0] - 1;

    for (ll i = 1; i < n; i++)
    {
        if (i & 1)
        {
            odd += d[i - 1];
            ll next = odd - even;
            max_ = min(max_, next - 1);
        }
        else
        {
            even += d[i - 1];
            ll next = even - odd;
            min_ = max(min_, -(next - 1));
        }
        // dbg(i);
        // dbg(min_);
        // dbg(max_);
    }

    if (max_ < 1 || min_ > max_)
    {
        cout << "-1\n";
        return;
    }

    ll prev = max_;

    for (int i = 0; i < n; i++)
    {
        if (prev < 1)
        {
            cout << "-1\n";
            return;
        }

        if (i == n - 1)
        {
            if (prev >= d[i - 1])
            {
                cout << "-1\n";
                return;
            }
        }
        else
        {
            ll next = d[i] - prev;

            if (next < 1)
            {
                cout << "-1\n";
                return;
            }
            prev = next;
        }
    }

    cout << max_ << "\n";
}

bool valid(ll m, vector<ll> &d)
{
    for (int i = 0; i <= d.size(); i++)
    {
        if (i == d.size())
        {
            if (m >= d[i - 1])
            {
                return false;
            }
        }
        else
        {
            ll next = d[i] - m;

            if (next < 1)
            {
                return false;
            }
            m = next;
        }
    }
    return true;
}

void s2()
{
    ll n;
    cin >> n;
    vector<ll> d(n - 1);

    pair<ll, ll> p, p2;
    r(p);

    for (ll i = 1; i < n; i++)
    {
        r(p2);
        d[i - 1] = e(p, p2);
        p = p2;
    }

    ll min_ = 1, max_ = d[0] - 1;

    ll ans = -1;

    for (ll j = max_; j >= 1; j--)
    {
        if (valid(j, d))
        {
            ans = j;
            break;
        }
    }

    cout << ans << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}