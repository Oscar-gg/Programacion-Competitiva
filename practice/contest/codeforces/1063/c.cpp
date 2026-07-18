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

// Copied approach
void s()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vector<int> pmin(n, INT_MAX), pmax(n, INT_MIN), smin(n, INT_MAX), smax(n, INT_MIN);

    pmin[0] = a[0][0];
    pmax[0] = a[0][0];
    for (int i = 1; i < n; i++)
    {
        pmin[i] = min(pmin[i - 1], a[0][i]);
        pmax[i] = max(pmax[i - 1], a[0][i]);
    }
    smin[n - 1] = a[1][n - 1];
    smax[n - 1] = a[1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        smin[i] = min(smin[i + 1], a[1][i]);
        smax[i] = max(smax[i + 1], a[1][i]);
    }
    vector<int> pos(2 * n, 2 * n);
    // Check path at each column
    for (int i = 0; i < n; i++)
    {
        // minimum and maximum needed to pass the path
        int min_ = min(pmin[i], smin[i]);
        int max_ = max(pmax[i], smax[i]);
        // Record the minimum to store the 'best' path
        pos[min_] = min(pos[min_], max_);
    }

    // If you can pass with [l, r], [l-1, r] is also possible
    for (int i = 2 * n - 2; i >= 0; i--)
    {
        pos[i] = min(pos[i], pos[i + 1]);
    }

    ll ans = 0;
    for (int i = 0; i < pos.size(); i++)
    {
        ans += 2 * n - pos[i];
    }
    cout << ans << "\n";
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