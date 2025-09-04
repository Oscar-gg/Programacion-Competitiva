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

void dfs(int node, int prev, unordered_set<int> &visited, unordered_set<int> &visitedCur, vector<int> &path, unordered_map<int, vector<int>> &umap, bool &cycle)
{
    if (cycle)
        return;

    for (auto x : umap[node])
    {
        if (x == prev)
            continue;

        if (visitedCur.count(x))
        {
            cycle = true;
            path.push_back(x);
            return;
        }

        if (!visited.count(x))
        {
            visited.insert(x);
            visitedCur.insert(x);
            path.push_back(x);
            dfs(x, node, visited, visitedCur, path, umap, cycle);
            if (cycle)
                return;
            path.pop_back();
            visitedCur.erase(visitedCur.find(x));
        }
    }
}

void s()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> umap;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        umap[a].push_back(b);
        umap[b].push_back(a);
    }

    vector<int> path;
    unordered_set<int> visited;
    bool cycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (!visited.count(i))
        {
            unordered_set<int> visitedCur;
            visited.insert(i);
            visitedCur.insert(i);
            path.push_back(i);
            dfs(i, -1, visited, visitedCur, path, umap, cycle);
        }

        if (cycle)
            break;
    }

    if (cycle)
    {
        int index = -1;

        for (int i = 0; i < path.size() - 1; i++)
        {
            if (path[i] == path.back())
            {
                index = i;
                break;
            }
        }

        cout << path.size() - index << "\n";

        for (int i = index; i < path.size(); i++)
            cout << path[i] << " ";

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