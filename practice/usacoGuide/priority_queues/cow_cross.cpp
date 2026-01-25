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
    int c, n;
    cin >> c >> n;

    map<int, int> m;
    for (int i = 0; i < c; i++)
    {
        int v;
        cin >> v;
        m[v]++;
    }

    map<int, vector<int>> g;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        s.insert(a);
        g[a].push_back(b);
    }
    s.insert(INT_MAX);
    int ans = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    auto it = m.begin();
    auto it2 = s.begin();

    while (it != m.end())
    {

        while (it2 != s.end() && *it2 <= it->first)
        {
            for (auto v : g[*it2])
            {
                pq.push(v);
            }
            it2 = next(it2);
        }

        while (!pq.empty() && it->first > pq.top())
            pq.pop();

        while (!pq.empty() && it->first <= pq.top() && m[it->first] > 0)
        {
            m[it->first]--;
            ans++;
            pq.pop();
        }
        it++;
    }

    cout << ans << "\n";
}

int main()
{
    _;

    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}