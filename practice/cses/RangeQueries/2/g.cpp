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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> f(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
                f[i][j] = 1;
        }
    }

    dp[0][0] = f[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] += dp[0][i - 1] + f[0][i];
        dp[i][0] += dp[i - 1][0] + f[i][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + f[i][j];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x, y, x2, y2;
        cin >> y >> x >> y2 >> x2;
        y--;
        x--;
        y2--;
        x2--;

        if (y > y2)
            swap(y, y2);
        if (x > x2)
            swap(x, x2);

        int total = dp[y2][x2];
        if (x > 0)
        {
            total -= dp[y2][x - 1];
        }
        if (y > 0)
        {
            total -= dp[y - 1][x2];
        }
        if (y > 0 && x > 0)
        {
            total += dp[y - 1][x - 1];
        }
        cout << total << "\n";
    }
}

int main()
{
    _ solve();
    return 0;
}