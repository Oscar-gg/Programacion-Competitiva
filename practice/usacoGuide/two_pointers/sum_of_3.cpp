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
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        a[i] = {v, i + 1};
    }
    pair<int, pair<int, int>> ans = {-1, {-1, -1}};

    sort(all(a));

    for (int i = 0; i < n - 2; i++)
    {
        if (ans.first != -1)
            break;
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            if (a[i].first + a[j].first + a[k].first > x)
            {
                k--;
            }
            else if (a[i].first + a[j].first + a[k].first < x)
            {
                j++;
            }
            else
            {
                ans = {a[i].second, {a[j].second, a[k].second}};
                break;
            }
        }
    }

    if (ans.first == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << ans.first << " " << ans.second.first << " " << ans.second.second << "\n";
    }
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}