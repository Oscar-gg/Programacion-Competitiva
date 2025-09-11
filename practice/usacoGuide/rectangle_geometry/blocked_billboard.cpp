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
#define nl << "\n";

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

int intersection(vector<int> b1, vector<int> b2)
{
    int ovx = max(min(b1[2], b2[2]) - max(b1[0], b2[0]), 0);
    int ovy = max(min(b1[3], b2[3]) - max(b1[1], b2[1]), 0);
    return ovx * ovy;
}

void s()
{
    vector<vector<int>> p;

    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        p.push_back({x1, y1, x2, y2});

        if (i < 2)
        {
            ans += abs(x1 - x2) * abs(y1 - y2);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        ans -= intersection(p[i], p[2]);
    }
    cout << ans << "\n";
}

int main()
{
    _;

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}