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

void dfs(int node, unordered_map<int, bool> &color, unordered_map<int, unordered_set<int>> &umap, bool &possible, bool current)
{
    if (!possible)
        return;

    for (auto n : umap[node])
    {
        if (!color.count(n))
        {
            color[n] = !current;
            dfs(n, color, umap, possible, !current);
        }
        else if (color[n] == current)
        {
            possible = false;
            return;
        }
    }
}

void s()
{

    int n, m;
    cin >> n >> m;

    unordered_map<int, unordered_set<int>> umap;
    unordered_map<int, bool> color;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        umap[a].insert(b);
        umap[b].insert(a);
    }
    bool possible = true;

    for (int i = 1; i <= n; i++)
    {
        if (!color.count(i) && possible)
            dfs(i, color, umap, possible, true);
    }

    if (possible)
    {
        for (int i = 1; i <= n; i++)
        {
            if (color[i])
            {
                cout << 1;
            }
            else
            {
                cout << 2;
            }
            cout << " ";
        }
        cout << "\n";
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