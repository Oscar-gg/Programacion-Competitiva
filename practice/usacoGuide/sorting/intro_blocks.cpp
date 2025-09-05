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

// Read editorial

void s()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, int> m;
    map<int, pair<int, int>> mp;

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        a[i] = v;

        if (mp.count(v))
        {
            mp[v] = {mp[v].first, i};
        }
        else
        {
            mp[v] = {i, i};
        }
        m[v]++;
    }

    vector<vector<int>> ranges;

    for (auto v : mp)
    {
        ranges.push_back({v.second.first, v.second.second, m[v.first]});
    }

    sort(all(ranges));

    int st = ranges[0][0];
    int end = ranges[0][1];
    int cost = 0;
    int maxCommon = ranges[0][2];

    for (int i = 0; i < ranges.size(); i++)
    {
        if (ranges[i][0] > end)
        {
            cost += end - st + 1 - maxCommon;
            st = ranges[i][0];
            maxCommon = 0;
        }

        maxCommon = max(maxCommon, ranges[i][2]);
        end = max(end, ranges[i][1]);
    }

    cost += end - st + 1 - maxCommon;
    cout << cost << "\n";
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