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
    int n, u;
    cin >> n >> u;
    vector<string> m(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }

    vector<vector<int>> dotCounts(n / 2, vector<int>(n / 2));

    int op = 0;

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int q1 = m[i][j] == '.' ? 1 : 0;
            int q2 = m[i][n - 1 - j] == '.' ? 1 : 0;
            int q3 = m[n - 1 - i][j] == '.' ? 1 : 0;
            int q4 = m[n - 1 - i][n - 1 - j] == '.' ? 1 : 0;

            dotCounts[i][j] = q1 + q2 + q3 + q4;
            op += min(dotCounts[i][j], 4 - dotCounts[i][j]);
        }
    }

    cout << op << "\n";

    for (int i = 0; i < u; i++)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        bool dot = m[r][c] == '.';
        m[r][c] = dot ? '#' : '.';

        if (r + 1 > n / 2)
        {
            r = n - 1 - r;
        }
        if (c + 1 > n / 2)
        {
            c = n - 1 - c;
        }

        op -= min(dotCounts[r][c], 4 - dotCounts[r][c]);
        if (dot)
        {
            dotCounts[r][c]--;
        }
        else
        {
            dotCounts[r][c]++;
        }
        op += min(dotCounts[r][c], 4 - dotCounts[r][c]);
        cout << op << '\n';
    }
}

int main()
{
    _

        int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}