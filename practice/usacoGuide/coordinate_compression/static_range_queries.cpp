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

void s()
{
    ll n, q;
    cin >> n >> q;
    vector<pair<ll, ll>> seg;
    vector<pair<ll, ll>> events;

    for (ll i = 0; i < n; i++)
    {
        ll l, r, v;
        cin >> l >> r >> v;
        events.push_back({l, v});
        events.push_back({r, -v});
    }
    sort(all(events));

    ll curr = 0;
    seg.push_back({0, 0});

    for (ll i = 0; i < events.size(); i++)
    {
        curr += events[i].second;

        if (seg.back().first != events[i].first)
            seg.push_back({events[i].first, 0});

        seg.back().second = curr;
    }
    seg.push_back(seg.back());
    seg.back().first++;
    seg.back().second = 0;

    vector<ll> pref(seg.size());
    for (ll i = 0; i < pref.size() - 1; i++)
    {
        if (i > 0)
        {
            pref[i] = pref[i - 1];
        }
        pref[i] += seg[i].second * (seg[i + 1].first - seg[i].first);
    }
    pref[pref.size() - 1] = pref[pref.size() - 2];

    // for (auto v : seg)
    //     cout << "(" << v.first << ", " << v.second << ") ";

    // cout nl;

    // for (auto v : pref)
    //     cout << v << " ";

    // cout nl;

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        pair<ll, ll> pa1 = {l + 1, 0}, pa2 = {r, 0};
        ll p1 = lower_bound(seg.begin(), seg.end(), pa1) - seg.begin();
        ll p2 = lower_bound(seg.begin(), seg.end(), pa2) - seg.begin();

        p1--;
        p2--;

        ll ans = 0;
        if (p1 == p2)
        {
            ans = (r - l) * seg[p1].second;
        }
        else
        {
            ans = (seg[p1 + 1].first - l) * seg[p1].second;
            // dbg(ans);

            ans += (r - seg[p2].first) * seg[p2].second;
            // dbg((r - seg[p2].first) * seg[p2].second);
            // dbg((r - seg[p2].first));
            // dbg(ans);

            p1++;
            p2--;

            if (p2 >= p1)
            {
                if (p1 - 1 >= 0)
                    ans -= pref[p1 - 1];
                ans += pref[p2];
            }
        }

        cout << ans << "\n";
    }
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