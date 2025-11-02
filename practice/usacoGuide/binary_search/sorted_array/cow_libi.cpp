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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

bool comp(const std::pair<int, std::pair<int, int>> &p, const int t)
{
    return p.first < t;
}

int low_b(vector<pair<int, pair<int, int>>> &a, int v)
{
    int l = 0, r = a.size() - 1;
    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (a[m].first < v)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    if (a[l].first > v)
    {
        return l + 1;
    }
    return l;
}

ll dist(pair<int, int> p1, pair<int, int> p2)
{
    ll d1 = p1.first - p2.first, d2 = p1.second - p2.second;
    return d1 * d1 + d2 * d2;
}

void s()
{
    ll g, n;
    cin >> g >> n;

    vector<pair<ll, pair<ll, ll>>> a(g);

    for (ll i = 0; i < g; i++)
    {
        ll x, y, t;
        cin >> x >> y >> t;
        a[i] = {t, {x, y}};
    }

    sort(all(a));
    ll pos = 0;
    while (n--)
    {
        ll x, y, t;
        cin >> x >> y >> t;

        ll ind = lower_bound(all(a), t, comp) - a.begin();

        ll arrives = 0;
        ll expects = 0;

        if (ind > 0)
            expects++;

        if (ind < g)
            expects++;

        if (ind > 0 && dist(a[ind - 1].second, {x, y}) <= (t - a[ind - 1].first) * (t - a[ind - 1].first))
        {
            arrives++;
        }

        if (ind < g && dist(a[ind].second, {x, y}) <= (t - a[ind].first) * (t - a[ind].first))
        {
            arrives++;
        }

        if (arrives < expects)
            pos++;
    }

    cout << pos << "\n";
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