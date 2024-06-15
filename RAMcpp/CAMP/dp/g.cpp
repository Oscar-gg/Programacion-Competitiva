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

// TLE
// int computePages(int n, int x, vector<vector<int>> &dp, vector<int> &pages, vector<int> &price){
//     if (n < 0)
//         return 0;

//     if (dp[n][x] != -1)
//         return dp[n][x];

//     if (price[n] <= x){
//         return dp[n][x] = max(computePages(n-1, x, dp, pages, price), computePages(n-1, x - price[n], dp, pages, price) + pages[n]);
//     } else {
//         return dp[n][x] = computePages(n-1, x, dp, pages, price);
//     }

// }

int main()
{
    _

        int n,
        x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);

    for (auto &x : price)
    {
        cin >> x;
    }

    for (auto &x : pages)
    {
        cin >> x;
    }

    vector<vector<int>> dp(n+1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (j + price[i-1] <= x)
            {
                dp[i][j + price[i-1]] = max(dp[i][j + price[i-1]], dp[i - 1][j] + pages[i-1]);
            }
        }
    }

    // int index = n-1;
    cout << dp[n][x] << "\n";

    // cout << computePages(index, x, dp, pages, price) << "\n";

    // for(auto x : dp){
    //     for (auto y : x)
    //         cout << y << " ";

    //     cout << "\n";
    // }

    return 0;
}