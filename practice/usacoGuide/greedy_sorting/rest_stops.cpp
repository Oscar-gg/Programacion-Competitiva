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
    ll l, n, f, b;
    cin >> l >> n >> f >> b;
    vector<int> a(l), m;
    vector<ll> maxT(l);

    for (int i = 0; i < n; i++)
    {
        int as, de;
        cin >> as >> de;
        as--;
        a[as] = de;
    }
    m = a;

    for (int i = l - 2; i >= 0; i--)
    {
        m[i] = max(m[i], m[i + 1]);
    }

    for (int i = 0; i < l; i++)
    {
        maxT[i] = f * (i + 1) - b;
    }

    int runned = 0;
    ll time = 0, ans = 0, arriveTime = 0;

    while (runned < l)
    {
        while (runned < l && a[runned] != m[runned])
        {
            runned++;
            arriveTime += b;
        }

        ans += (maxT[runned] - arriveTime) * m[runned];
        arriveTime = maxT[runned] + b;
        runned++;
    }

    cout << ans << "\n";
}

int main()
{
    _;

    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}