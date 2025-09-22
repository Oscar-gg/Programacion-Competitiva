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

// with editorial

ll comb(ll n)
{
    return (n * (n + 1)) / 2;
}

void s()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &v : a)
        cin >> v;
    for (auto &v : b)
        cin >> v;

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            ans += comb(i) + comb(n - 1 - i) + min(i, n - i - 1) + 1;
        }
    }

    for (int rep = 0; rep < 2; rep++)
    {
        if (rep > 0)
        {
            reverse(all(a));
            reverse(all(b));
        }

        unordered_map<ll, vector<ll>> ind;
        unordered_map<ll, ll> mul;
        unordered_map<ll, ll> sum;

        ll p = n - 1;

        while (p >= 0)
        {
            while (!ind[a[p]].empty() && ind[a[p]].back() > p)
            {
                mul[a[p]]++;
                sum[a[p]] -= ind[a[p]].back();
                ind[a[p]].pop_back();
            }
            ans += (mul[a[p]] * (p + 1)) + sum[a[p]];

            ind[b[p]].push_back(n - p);
            sum[b[p]] += n - p;

            p--;
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