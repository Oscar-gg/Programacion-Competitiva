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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    map<pair<int, int>, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        m[a[i]].push_back(i);
    }

    sort(all(a));

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    vector<int> rans(n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int r = -1;
        while (!pq.empty() && a[i].first > pq.top().first)
        {
            r = pq.top().second;
            pq.pop();
            break;
        }
        if (r == -1)
            r = pq.size() + 1;

        pq.push({a[i].second, r});
        rans[m[a[i]].back()] = r;
        m[a[i]].pop_back();
        ans = max(ans, (int)pq.size());
    }

    cout << ans << "\n";
    for (auto v : rans)
    {
        cout << v << " ";
    }
    cout nl;
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