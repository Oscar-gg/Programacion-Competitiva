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

ll money(ll l, vector<pair<ll, ll>> &p, vector<ll> &li)
{
    int ind = lower_bound(li.begin(), li.end(), l) - li.begin();

    if (ind == li.size())
    {
        return p.back().first;
    }

    if (ind > 0)
        l -= li[ind - 1];

    ll mon = 0;
    if (ind > 0)
    {
        mon = p[ind - 1].first;
    }
    mon += p[ind].second * l;
    return mon;
}

void s()
{
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> a(n);
    cin >> a;
    vector<pair<ll, ll>> s(m);

    for (auto &v : s)
        cin >> v.second >> v.first;

    vector<int> f(r);
    cin >> f;
    sort(all(a));
    sort(all(s));
    reverse(all(s));
    sort(all(f));
    reverse(all(f));

    vector<pair<ll, ll>> p(s.size());
    vector<ll> l(s.size());

    for (int i = 0; i < s.size(); i++)
    {
        p[i].first += s[i].first * s[i].second;
        p[i].second = s[i].first;
        l[i] += s[i].second;
        if (i > 0)
        {
            p[i].first += p[i - 1].first;
            l[i] += l[i - 1];
        }
    }
    // cout << a nl;
    // cout << f nl;
    // cout << l nl;

    // for (auto v : p)
    // {
    //     cout << "(" << v.first << " " << v.second << ") ";
    // }

    ll av = 0;
    for (auto v : a)
        av += v;

    ll total = money(av, p, l);

    ll lsold = av;
    int pF = 0;

    for (int i = 0; i < n; i++)
    {
        // dbg(a[i]);
        ll cowM = money(lsold, p, l) - money(lsold - a[i], p, l);
        // dbg(money(lsold, p, l));
        // dbg(money(lsold - a[i], p, l));

        if (pF < f.size() && cowM < f[pF])
        {
            total += f[pF++];
            total -= cowM;
            lsold -= a[i];
        }
        // dbg(total);
    }

    cout << total nl;
}

int main()
{
    _;

    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}