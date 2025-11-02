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

void s()
{
    int n;
    cin >> n;
    vector<vector<int>> ps(n + 1);
    ps[0] = {0, 0, 0};

    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        ps[i] = ps[i - 1];

        if (c == 'H')
        {
            ps[i][0]++;
        }
        else if (c == 'P')
        {
            ps[i][1]++;
        }
        else
        {
            ps[i][2]++;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int maxL = 0, maxR = 0;

        for (int j = 0; j < 3; j++)
        {
            maxL = max(maxL, ps[i][j]);
            maxR = max(maxR, ps[n][j] - ps[i][j]);
        }
        ans = max(ans, maxL + maxR);
    }

    cout << ans << "\n";
}

int main()
{
    _;

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}