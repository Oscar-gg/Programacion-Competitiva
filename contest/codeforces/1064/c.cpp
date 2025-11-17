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

void make_set(int v, vector<int> &parent, vector<int> &size, vector<pair<int, int>> &range)
{
    parent[v] = v;
    size[v] = 1;
    range[v] = {v, v};
}

int find_set(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size, vector<pair<int, int>> &range)
{
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        range[a] = {min(range[a].first, range[b].first), max(range[a].second, range[b].second)};
    }
}

void s()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v : a)
        cin >> v;

    vector<int> parent(n), size(n);
    vector<pair<int, int>> range(n);
    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++)
    {
        make_set(i, parent, size, range);
    }

    priority_queue<vi, vector<vi>, greater<vi>> pq;
    ll cost = 0;
    for (int i = 1; i < n; i++)
    {
        umap[i] = a[i];
        pq.push({max(a[i], a[i - 1]), i, i - 1});
    }
    umap[0] = a[0];
    pq.push({max(a[0], a[n - 1]), 0, n - 1});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int p1 = find_set(top[1], parent), p2 = find_set(top[2], parent);
        // dbg(max(umap[p1], umap[p2]));
        // dbg(p1);
        // dbg(p2);
        if (p1 == p2)
            continue;

        if (max(umap[p1], umap[p2]) != top[0])
            continue;

        // cout << "(" << range[p1].first << " " << range[p1].second << ")" << ", (" << range[p2].first << " " << range[p2].second << ")\n";

        // dbg("cont");

        cost += top[0];
        union_sets(p1, p2, parent, size, range);
        int newP = find_set(p1, parent);
        umap[newP] = max(umap[p1], umap[p2]);
        if (range[newP].first - 1 < 0)
        {
            pq.push({max(umap[newP], umap[find_set(n - 1, parent)]), newP, find_set(n - 1, parent)});
        }
        else
        {
            pq.push({max(umap[newP], umap[find_set(range[newP].first - 1, parent)]), newP, find_set(range[newP].first - 1, parent)});
        }

        if (range[newP].second + 1 == n)
        {
            pq.push({max(umap[newP], umap[find_set(0, parent)]), newP, find_set(0, parent)});
        }
        else
        {
            pq.push({max(umap[newP], umap[find_set(range[newP].second + 1, parent)]), newP, find_set(range[newP].second + 1, parent)});
        }
    }
    cout << cost << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        s();
    return 0;
}