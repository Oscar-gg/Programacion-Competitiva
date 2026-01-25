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
typedef pair<int, pair<int, int>> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

pair<ll, pair<ll, ll>> format(pair<ll, pair<ll, ll>> p)
{
    return {p.second.first, {p.first, p.second.second}};
}

void s()
{
    ll n;
    cin >> n;
    vector<pair<ll, pair<ll, ll>>> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second.first = i;
        cin >> a[i].second.second;
    }
    sort(all(a));
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    ll p = 0;
    pq.push(format(a[p++]));
    ll t = 0;
    ll ans = 0;

    while (!pq.empty() || p < n)
    {
        if (pq.empty() && p < n)
        {
            pq.push(format(a[p++]));
        }
        auto f = pq.top();
        pq.pop();
        ans = max(ans, t - f.second.first);
        t = max(t, (ll)f.second.first) + f.second.second;
        while (p < n && a[p].first <= t)
        {
            pq.push(format(a[p++]));
        }
    }

    cout << ans << "\n";
}

int main()
{
    _;

    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}