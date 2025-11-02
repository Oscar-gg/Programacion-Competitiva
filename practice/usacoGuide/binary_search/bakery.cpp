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

// Solved with editorial
bool pos(int m, vector<pair<ll, pair<ll, ll>>> &a, ll tc, ll tm)
{
    // x -> (1, tc)
    ll lx = max(1ll, tc - m), hx = min(tc + tm - m - 1, tc);

    for (ll i = 0; i < a.size(); i++)
    {
        // x + y = tc + tm -m
        // e.first * x + e.second * y <= c
        // x <= (c - e.second * (tc + tm - m)) / (e.first-e.second)
        // if ()
        ll in = tc + tm - m;

        if (a[i].second.first < a[i].second.second)
        {
            lx = max(lx, (-a[i].first + a[i].second.second * in + (a[i].second.second - a[i].second.first - 1)) / (a[i].second.second - a[i].second.first));
        }
        else if (a[i].second.first > a[i].second.second)
        {
            hx = min(hx, (a[i].first - a[i].second.second * in) / (a[i].second.first - a[i].second.second));
        }
        else
        {
            if (a[i].second.first * in > a[i].first)
                return false;
        }
    }

    return lx <= hx;
}

void s()
{
    ll n, tc, tm;
    cin >> n >> tc >> tm;

    vector<pair<ll, pair<ll, ll>>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second.first >> a[i].second.second >> a[i].first;
    }

    int l = 0, r = tc + tm - 2;

    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (pos(m, a, tc, tm))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << l << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        s();
    return 0;
}