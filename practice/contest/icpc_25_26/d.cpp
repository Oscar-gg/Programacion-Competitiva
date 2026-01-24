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
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

ll d(pair<ll, ll> a, pair<ll, ll> b)
{
    ll x = a.first - b.first;
    ll y = a.second - b.second;
    return (x) * (x) + (y) * (y);
}

vector<pair<ll, ll>> order(vector<pair<ll, ll>> &in)
{
    if (in.size() <= 2)
    {
        sort(all(in));
        return in;
    }
    pair<ll, ll> a, b, c;
    a = in[0], b = in[1], c = in[2];

    ll d1 = d(a, b);
    ll d2 = d(a, c);
    ll d3 = d(c, b);

    vector<pair<ll, ll>> ret{};

    if (d1 > d2 && d1 > d3)
    {
        ret = {a, c, b};
    }
    else if (d2 > d1 && d2 > d3)
    {
        ret = {c, b, a};
    }
    else
    {
        ret = {b, a, c};
    }

    if (ret[0].first > ret[2].first || (ret[0].first == ret[2].first && ret[0].second > ret[2].second))
    {
        swap(ret[0], ret[2]);
    }

    return ret;
}

vector<pair<ll, ll>> merge(vector<pair<ll, ll>> v1, vector<pair<ll, ll>> v2)
{
    vector<pair<ll, ll>> ret;

    if (v1.size() == 0)
        return v2;

    if (v2.size() == 0)
        return v1;

    if (v1.size() + v2.size() <= 3)
    {
        for (auto v : v2)
            v1.push_back(v);

        return order(v1);
    }

    if (v1.size() < v2.size())
        swap(v1, v2);

    vector<pair<ll, ll>> init = {v1[0], v1[1], v2[0]};

    init = order(init);
    ret.push_back(init[0]);

    ll l = 0, r = 0;

    if (init[0] == v2[0])
        r++;
    else
    {
        l++;

        if (init[0] == v1[1])
            swap(v1[0], v1[1]);
    }

    while (l < v1.size() && r < v2.size())
    {
        pair<ll, ll> a, b, c;

        a = ret.back();
        b = v1[l];
        c = v2[r];

        vector<pair<ll, ll>> in{a, b, c};

        vector<pair<ll, ll>> ordered = order(in);

        // if (d(ret.back(), ordered[0]) > d(ret.back(), ordered[2]))
        // {
        //     swap(ordered[0], ordered[2]);
        // }
        ret.push_back(ordered[1]);
        if (ordered[1] == v1[l])
        {
            l++;
        }
        else
        {
            r++;
        }
    }

    while (l < v1.size())
    {
        ret.push_back(v1[l++]);
    }
    while (r < v2.size())
    {
        ret.push_back(v2[r++]);
    }
    return ret;
}

vector<pair<ll, ll>> mergeH(vector<pair<ll, ll>> in)
{
    if (in.size() <= 3)
    {
        return order(in);
    }

    vector<pair<ll, ll>> a, b;

    for (ll i = 0; i < in.size(); i++)
    {
        if (i < in.size() / 2)
            a.push_back(in[i]);
        else
            b.push_back(in[i]);
    }
    return merge(mergeH(a), mergeH(b));
}

void s()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    a = mergeH(a);
    double ans = 0;

    for (ll i = 0; i < a.size() - 1; i++)
    {
        // dbg(sqrt(d(a[i], a[i + 1])))
        ans += sqrt(d(a[i], a[i + 1]));
    }
    // for (auto v : a)
    // {
    //     cout << v.first << " " << v.second << "\n";
    // }

    cout << ans << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}