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
    int n, m;
    cin >> n >> m;
    vector<int> t(100);
    vector<pair<int, int>> airD(m), airR(m);
    for (int i = 0; i < n; i++)
    {
        int s, ti, c;
        cin >> s >> ti >> c;
        s--;
        ti--;
        for (int j = s; j <= ti; j++)
        {
            t[j] = max(t[j], c);
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> airR[i].first >> airR[i].second;
        airR[i].first--;
        airR[i].second--;
        cin >> airD[i].first >> airD[i].second;
    }

    int ans = INT_MAX;

    for (int i = 0; i < (1 << m); i++)
    {
        int cost = 0;
        vector<int> buy(100);

        for (int j = 0; j < m; j++)
        {
            if (i & (1 << j))
            {
                cost += airD[j].second;
                for (int k = airR[j].first; k <= airR[j].second; k++)
                {
                    buy[k] += airD[j].first;
                }
            }
        }

        bool pos = true;
        for (int j = 0; j < buy.size(); j++)
        {
            if (buy[j] < t[j])
            {
                pos = false;
                break;
            }
        }

        if (pos)
        {
            ans = min(ans, cost);
        }
    }

    cout << ans << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}