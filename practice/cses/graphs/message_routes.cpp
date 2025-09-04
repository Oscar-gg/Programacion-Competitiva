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

    vector<vector<int>> umap(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        umap[a].push_back(b);
        umap[b].push_back(a);
    }
    vector<int> prev(n + 1, 0);

    queue<int> q;
    q.push(1);
    prev[1] = 1;
    bool pos = false;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        if (f == n)
        {
            pos = true;
            break;
        }

        for (auto n : umap[f])
        {
            if (!prev[n])
            {
                prev[n] = f;
                q.push(n);
            }
        }
    }

    if (pos)
    {
        vector<int> path{n};

        while (path.back() != 1)
        {
            path.push_back(prev[path.back()]);
        }

        cout << path.size() nl;

        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }

        cout nl;
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}

int main()
{
    _

        int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}