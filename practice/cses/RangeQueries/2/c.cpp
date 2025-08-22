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

void build(int index, int l, int r, vector<long long int> &a, vector<long long int> &seg)
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
            build(index * 2, l, mid, a, seg);
            build(index * 2 + 1, mid + 1, r, a, seg);
            seg[index] = seg[index * 2] + seg[index * 2 + 1];
        }
    }
}

void update(int index, int pos, int val, int l, int r, vector<long long int> &seg)
{
    if (pos == l && pos == r)
    {
        seg[index] = val;
        return;
    }

    int mid = l + (r - l) / 2;
    if (pos <= mid)
    {
        update(index * 2, pos, val, l, mid, seg);
    }
    else
    {
        update(index * 2 + 1, pos, val, mid + 1, r, seg);
    }
    seg[index] = seg[index * 2] + seg[index * 2 + 1];
}

long long int query(int index, int l, int r, int qL, int qR, vector<long long int> &seg)
{
    if (l > r)
        return 0;

    if (qL == l && qR == r)
        return seg[index];

    int mid = l + (r - l) / 2;

    long long int ans = 0;

    if (qL <= mid)
    {
        ans = query(index * 2, l, mid, qL, min(qR, mid), seg);
    }

    if (qR >= mid + 1)
    {
        ans += query(index * 2 + 1, mid + 1, r, max(qL, mid + 1), qR, seg);
    }
    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<long long int> a(n), seg(4 * n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1, a, seg);

    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        if (a == 1)
        {
            update(1, b, c, 0, n - 1, seg);
        }
        else
        {
            c--;
            cout << query(1, 0, n - 1, b, c, seg) << "\n";
        }
    }
}

int main()
{
    _ solve();
    return 0;
}