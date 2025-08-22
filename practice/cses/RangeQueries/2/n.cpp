#include <algorithm>
// #include <bitset>
// #include <cmath>
// #include <cstdio>
// #include <cstring>
// #include <deque>
// #include <fstream>
// #include <functional>
// #include <iomanip>
#include <iostream>
// #include <limits.h>
// #include <map>
// #include <math.h>
// #include <numeric>
// #include <queue>
// #include <set>
// #include <sstream>
// #include <stack>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string>
// #include <utility>
#include <vector>
// #include <unordered_set>
// #include <unordered_map>
// #include <chrono>

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);

using namespace std;

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
            seg[index].resize(seg[index * 2].size() + seg[index * 2 + 1].size());
            merge(seg[index * 2].begin(), seg[index * 2].end(),
                  seg[index * 2 + 1].begin(), seg[index * 2 + 1].end(),
                  seg[index].begin());
        }
    }
}

int query(int index, int l, int r, int qL, int qR, int c, int d, vector<vector<int>> &seg)
{
    if (l == qL && r == qR)
    {
        return upper_bound(seg[index].begin(), seg[index].end(), d) - lower_bound(seg[index].begin(), seg[index].end(), c);
    }

    int mid = l + (r - l) / 2;

    int ans = 0;

    if (qL <= mid)
    {
        ans = query(index * 2, l, mid, qL, min(qR, mid), c, d, seg);
    }

    if (qR >= mid + 1)
    {
        ans += query(index * 2 + 1, mid + 1, r, max(qL, mid + 1), qR, c, d, seg);
    }
    return ans;
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;

        vector<int> g;
        cout << query(1, 0, n - 1, a, b, c, d, seg) << '\n';
    }

    // cout << "TotalQ: " << totalQ << "\n";
    // cout << "logN: " << logN << "\n";
}

int main()
{
    // auto start = chrono::high_resolution_clock::now();

    _ solve();
    // auto end = chrono::high_resolution_clock::now();
    // double executionTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // executionTime *= 1e-6;
    // cout << "Execution Time: " << fixed << executionTime << setprecision(6);
    // cout << " ms\n";
    return 0;
}