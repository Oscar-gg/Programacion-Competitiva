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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

void s()
{
    int n, k, m;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(n);
    for (auto &v : a)
        cin >> v.first >> v.second;

    sort(a.rbegin(), a.rend());

    priority_queue<ii> pq;
    pq.push({LLONG_MAX, m});
    ll ans = 0;
    int p = 0;

    while (p < n)
    {
        ii cur = a[p];
        p++;
        ll insert = 0;
        // dbg(cur.first);

        while (cur.second > 0 && !pq.empty() && pq.top().first >= cur.first + k)
        {
            auto t = pq.top();
            // cout << t.first << " " << t.second << "\n";
            pq.pop();
            if (t.second >= cur.second)
            {
                insert += cur.second;

                if (t.second != cur.second)
                {
                    pq.push({t.first, t.second - cur.second});
                }
                cur.second = 0;
            }
            else
            {
                insert += t.second;
                cur.second -= t.second;
            }
            // dbg(insert);
        }
        ans += insert;
        if (insert > 0)
        {
            pq.push({cur.first, insert});
        }
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