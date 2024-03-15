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
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

int knapsack(int index, int cur, vector<int> &vals, vector<vector<int>> &dp)
{
    if (index < 0)
        return 0;

    if (dp[index][cur] != -1)
        return dp[index][cur];

    if (vals[index] > cur)
    {
        dp[index][cur] = knapsack(index - 1, cur, vals, dp);
        return dp[index][cur];
    }
    else
    {
        dp[index][cur] = max(knapsack(index - 1, cur, vals, dp), knapsack(index - 1, cur - vals[index], vals, dp) + vals[index]);
        return dp[index][cur];
    }
}

void solve()
{
    int m;
    cin >> m;
    vector<int> a(m);

    int max_ = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        max_ += a[i];
    }

    int t = max_ / 2;

    vector<vector<int>> dp(m, vector<int>(t+1, -1));

    int used = knapsack(m - 1, t, a, dp);
    for (auto x : dp)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    dbg(used);

    cout << (max_ - used) - used << "\n";
}

int main()
{
    _

        int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();

    return 0;
}