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

// editorial
void s(vector<vector<int>> &comb)
{
    int n, k;
    cin >> n >> k;

    int d = 0;

    int cn = n;

    while (cn % 2 == 0)
    {
        cn /= 2;
        d++;
    }

    int ans = 0;

    for (int i = 0; i < d; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            if (i + j > k)
            {
                ans += comb[i][j - 1];
            }
        }
    }

    if (d + 1 > k)
        ans++;

    cout << ans nl;
}

int main()
{
    _;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);

    vector<vector<int>> comb(31, vector<int>(31));

    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if (i < j)
                continue;
            if (j == 0)
                comb[i][j] = 1;
            else
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    int t = 1;
    cin >> t;
    while (t--)
        s(comb);
    return 0;
}