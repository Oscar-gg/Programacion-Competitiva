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

bool pos(ll m, vector<pair<ll, ll>> &a, int n)
{
    ll lp = LLONG_MIN;

    ll cur = 0;

    for (int i = 0; i < a.size(); i++)
    {
        while (lp <= a[i].second)
        {
            cur++;
            lp = max(lp + m, a[i].first + m);
        }
    }

    return cur >= n;
}

void s()
{

    int n, d;
    cin >> n >> d;

    vector<pair<ll, ll>> a(d);
    for (auto &p : a)
    {
        cin >> p.first >> p.second;
    }
    sort(all(a));

    ll l = 1, r = 1e18 + 1;

    while (l < r)
    {
        ll m = l + (r - l + 1) / 2;

        if (pos(m, a, n))
        {
            l = m;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << l nl;
}

int main()
{
    _;

    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}