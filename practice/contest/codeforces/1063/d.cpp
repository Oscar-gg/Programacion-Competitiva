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
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(q);
    vector<int> maxE(q, INT_MIN);
    map<pair<int, int>, int> omap;

    for (int i = 0; i < q; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    maxE[0] = a[0].second;

    sort(all(a));
    int l = 0, r = q - 1;
    int mex = n;
    while (l <= r)
    {
        for (int i = l; i <= r; i++)
        {
            maxE[i] = 0;
        }
        maxE[l] = a[l].second;
        for (int i = l + 1; i <= r; i++)
        {
            maxE[i] = max(maxE[i - 1], a[i].second);
        }
        int m = l + (r - l) / 2;
        int v1, v2;
        pair<int, int> p1 = {a[l].first, maxE[m]};

        if (omap.count(p1))
        {
            v1 = omap[p1];
        }
        else
        {
            cout << "? " << p1.first << " " << p1.second << "\n";
            cout.flush();
            cin >> v1;
            omap[p1] = v1;
        }

        pair<int, int> p2 = {a[min(m + 1, r)].first, maxE[r]};

        if (omap.count(p2))
        {
            v2 = omap[p2];
        }
        else
        {
            cout << "? " << p2.first << " " << p2.second << "\n";
            cout.flush();
            cin >> v2;
            omap[p2] = v2;
        }

        if (v1 >= v2)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
        mex = min(mex, max(v1, v2));

        if (l == r)
            break;
    }

    cout << "! " << mex << "\n";
    cout.flush();
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