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
    int n, g;
    cin >> n >> g;

    map<int, vector<pair<int, int>>> m;

    for (int i = 0; i < n; i++)
    {
        int d, c, change;
        char sign;
        cin >> d >> c >> sign >> change;

        m[d].push_back({c, sign == '-' ? change * -1 : change});
    }

    int ans = 0;

    unordered_map<int, int> umap;
    unordered_map<int, unordered_set<int>> freq;
    priority_queue<pair<int, int>> pq;
    int top = g;
    unordered_set<int> pT = {};

    for (auto it = m.begin(); it != m.end(); it++)
    {
        for (auto d : m[it->first])
        {
            if (umap.count(d.first))
            {
                freq[umap[d.first]].erase(d.first);
                umap[d.first] += d.second;
            }
            else
            {
                umap[d.first] = g + d.second;
            }
            freq[umap[d.first]].insert(d.first);

            pq.push({umap[d.first], d.first});
        }

        while (umap[pq.top().second] != pq.top().first)
            pq.pop();

        if (freq[pq.top().first] != pT)
        {
            ans++;
            pT = freq[pq.top().first];
        }
    }

    cout << ans << "\n";
}

int main()
{
    _;

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}