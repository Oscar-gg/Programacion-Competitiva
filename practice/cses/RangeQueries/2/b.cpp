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

void build(int l, int r, int index, vector<int> &a, vector<int> &segTree)
{
    if (l >= a.size() || l > r)
        return;

    if (l == r)
    {
        segTree[index] = a[l];
        // cout << "segTree[l]: (" << segTree[l] << ", l: " << l << ") ";
        return;
    }

    int mid = l + (r - l) / 2;
    build(l, mid, index * 2, a, segTree);
    build(mid + 1, r, index * 2 + 1, a, segTree);

    segTree[index] = min(segTree[index * 2], segTree[index * 2 + 1]);
}

int query(int l, int r, int qL, int qR, int index, vector<int> &segTree)
{

    if (l == qL && r == qR)
    {
        return segTree[index];
    }

    int ans = INT_MAX;

    int mid = l + (r - l) / 2;

    if (qL <= mid)
    {
        ans = query(l, mid, qL, min(qR, mid), index * 2, segTree);
    }

    if (qR >= mid + 1)
    {
        ans = min(ans, query(mid + 1, r, max(mid + 1, qL), qR, index * 2 + 1, segTree));
    }

    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> segTree(4 * n + 1, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    build(0, n - 1, 1, a, segTree);

    // for (auto v : a)
    // {
    //     cout << v << " ";
    // }
    // for (auto c : segTree)
    // {
    //     cout << c << " ";
    // }
    // cout << "\n";
    // cout << "passed build" << endl;

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << query(0, n - 1, l, r, 1, segTree) << "\n";
    }
}

int main()
{
    _

    solve();

    return 0;
}