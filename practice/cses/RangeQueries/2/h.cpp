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

void construct(int index, int l, int r, vector<int> &a, vector<int> &seg)
{
    if (l <= r)
    {
        if (l == r)
        {
            seg[index] = a[l];
        }
        else
        {
            int mid = l + (r - l) / 2;
            construct(index * 2, l, mid, a, seg);
            construct(index * 2 + 1, mid + 1, r, a, seg);
            seg[index] = max(seg[index * 2], seg[index * 2 + 1]);
        }
    }
}

void update(int index, int pos, int value, int l, int r, vector<int> &seg)
{
    if (l <= r)
    {
        if (l == r && pos == l)
        {
            seg[index] = value;
            return;
        }

        int mid = l + (r - l) / 2;
        if (pos <= mid)
            update(index * 2, pos, value, l, mid, seg);
        else
            update(index * 2 + 1, pos, value, mid + 1, r, seg);

        seg[index] = max(seg[index * 2], seg[index * 2 + 1]);
    }
}

int query(int index, int val, int l, int r, vector<int> &seg)
{
    if (val > seg[index])
        return -1;

    if (l == r && seg[index] >= val)
    {
        return l;
    }

    int mid = l + (r - l) / 2;

    int left = query(index * 2, val, l, min(mid, r), seg);

    if (left == -1)
        return query(index * 2 + 1, val, max(l, mid + 1), r, seg);

    return left;
    // if (seg[index * 2] >= val)
    // {
    //     return
    // }
    // else
    // {
    //     return
    // }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), seg(4 * n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    construct(1, 0, n - 1, a, seg);

    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        int index = query(1, p, 0, n - 1, seg);
        if (index == -1)
        {
            cout << "0 ";
            continue;
        }

        a[index] = a[index] - p;
        update(1, index, a[index], 0, n - 1, seg);

        index++;

        cout << index << " ";
    }
    cout << "\n";
}

int main()
{
    _

    solve();

    return 0;
}