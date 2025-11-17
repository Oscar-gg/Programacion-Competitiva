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

void s()
{
    int k, m, n;
    cin >> k >> m >> n;
    vector<pair<int, int>> a(k);
    vector<int> f(m);
    for (auto &v : a)
        cin >> v.first >> v.second;
    for (auto &v : f)
        cin >> v;

    sort(all(f));
    sort(all(a));

    vector<ll> pos;

    int l = 0, r = 0;

    while (l < k)
    {
        if (r == m - 1)
        {
            ll t = 0;

            while (l < k)
            {
                t += a[l].second;
                l++;
            }
            pos.push_back(t);
        }
        else
        {
            int b1 = f[r], b2 = f[r + 1];
            if (a[l].first < b1)
            {
                ll t = 0;
                while (l < k && a[l].first < f[r])
                {
                    t += a[l].second;
                    l++;
                }
                pos.push_back(t);
            }
            else
            {
                while (r + 1 < m && a[l].first > f[r + 1])
                    r++;

                if (r == m - 1)
                    continue;

                double b1 = a[l].first - f[r], b2 = f[r + 1] - a[l].first;
                double newPos = a[l].first + min(b1 - 0.1, b2 - 0.1);
                ll t = 0;

                while (l < k && abs(newPos - a[l].first) < a[l].first - f[r] && abs(newPos - a[l].first) < f[r + 1] - a[l].first)
                {
                    t += a[l].second;
                    l++;
                }
                pos.push_back(t);
            }
        }
    }
    sort(all(pos));
    reverse(all(pos));
    ll ans = 0;

    for (int i = 0; i < pos.size() && i < n; i++)
    {
        ans += pos[i];
    }
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