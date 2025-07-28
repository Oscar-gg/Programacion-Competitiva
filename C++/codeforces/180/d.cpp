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

void solve()
{
    int n;
    cin >> n;
    vector<unordered_set<int>> g(n + 1);

    unordered_map<int, int> deg;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].insert(b);
        g[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
    unordered_map<int, bool> isOut;
    int root = -1, outR = -1;
    for (auto x : deg)
    {
        if (x.second == 2)
        {
            root = x.first;
            isOut[root] = true;
            vector<int> vals(g[root].begin(), g[root].end());

            isOut[vals[0]] = true;
            isOut[vals[1]] = false;
            outR = vals[1];
            break;
        }
    }

    if (root == -1)
    {
        cout << "NO\n";
        return;
    }

    queue<int> q;
    unordered_set<int> v;

    q.push(root);

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        if (v.count(f))
            continue;
        v.insert(f);

        for (auto n : g[f])
        {
            if (!isOut.count(n))
                isOut[n] = !isOut[f];
            q.push(n);
        }
    }

    cout << "YES\n";

    for (int i = 0; i < g.size(); i++)
    {
        if (!isOut[i])
            continue;
        if (i == root)
        {
            cout << root << " " << outR << "\n";
            continue;
        }
        for (auto n : g[i])
        {
            cout << i << " " << n << "\n";
        }
    }
}

int main()
{
    _

        int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}