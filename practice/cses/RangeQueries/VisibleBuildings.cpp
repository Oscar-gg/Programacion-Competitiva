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

void build(int index, int l, int r, vector<int> &h, vector<vector<int>> &seg)
{
    if (l <= r)
    {
        if (l == r)
        {
            seg[index].push_back(h[l]);
        }
        else
        {
            int mid = l + (r - l) / 2;
            build(index * 2, l, mid, h, seg);
            build(index * 2 + 1, mid + 1, r, h, seg);
            vector<int> next = seg[index * 2];
            for (int i = 0; i < seg[index * 2 + 1].size(); i++)
            {
                if (seg[index * 2 + 1][i] > next.back())
                    next.push_back(seg[index * 2 + 1][i]);
            }

            seg[index] = next;
        }
    }
}

void query(int index, int l, int r, int qL, int qR, vector<vector<int>> &seg, vector<int> &g)
{
    if (l == qL && r == qR)
    {
        g.push_back(index);
        return;
    }

    int mid = l + (r - l) / 2;

    if (qL <= mid)
    {
        query(index * 2, l, mid, qL, min(qR, mid), seg, g);
    }

    if (qR >= mid + 1)
    {
        query(index * 2 + 1, mid + 1, r, max(qL, mid + 1), qR, seg, g);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> h(n);
    vector<vector<int>> seg(4 * n);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    build(1, 0, n - 1, h, seg);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        vector<int> g;
        query(1, 0, n - 1, a, b, seg, g);

        int total = seg[g[0]].size();
        int max_ = seg[g[0]].back();
        for (int j = 1; j < g.size(); j++)
        {
            total += seg[g[j]].end() - upper_bound(seg[g[j]].begin(), seg[g[j]].end(), max_);
            max_ = max(max_, seg[g[j]].back());
        }
        cout << total << "\n";
    }
}

int main()
{
    _ solve();
    return 0;
}