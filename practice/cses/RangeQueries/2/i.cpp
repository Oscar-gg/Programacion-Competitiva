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

int query(int index, int l, int r, int amount, vector<int> &seg)
{
    if (l == r)
        return l;

    int mid = l + (r - l) / 2;

    if (seg[index * 2] >= amount)
    {
        return query(index * 2, l, mid, amount, seg);
    }

    return query(index * 2 + 1, mid + 1, r, amount - seg[index * 2], seg);
}

void update(int index, int l, int r, int pos, vector<int> &seg)
{

    if (pos == l && pos == r)
    {
        seg[index] = 0;
        return;
    }

    int mid = l + (r - l) / 2;

    if (pos <= mid)
    {
        update(index * 2, l, mid, pos, seg);
    }
    else
    {
        update(index * 2 + 1, mid + 1, r, pos, seg);
    }
    seg[index] = seg[index * 2] + seg[index * 2 + 1];
}

void build(int index, int l, int r, vector<int> &a, vector<int> &seg)
{
    if (l <= r)
    {
        if (l == r)
        {
            seg[index] = 1;
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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), seg(4 * n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1, a, seg);

    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;
        int index = query(1, 0, n - 1, next, seg);

        cout << a[index] << " ";
        update(1, 0, n - 1, index, seg);
    }

    cout << "\n";
}

int main()
{
    _ solve();
    return 0;
}