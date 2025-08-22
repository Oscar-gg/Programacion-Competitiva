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

struct Node
{
    long long int sum;
    long long int maxP;
    long long int maxS;
    Node()
    {
        sum = 0;
        maxP = 0;
        maxS = 0;
    }
};

#define MAXN 10
#define MOD 1000000007

Node combine(Node l, Node r)
{
    Node n = Node();

    n.sum = l.sum + r.sum;
    n.maxP = max({l.maxP, l.sum + r.maxP});
    n.maxS = max({r.maxS, r.sum + l.maxS});

    return n;
}

void build(int index, int l, int r, vector<int> &a, vector<Node> &seg)
{
    if (l <= r)
    {
        if (l == r)
        {
            seg[index].sum = a[l];
            seg[index].maxP = max(0, a[l]);
            seg[index].maxS = max(0, a[l]);
        }
        else
        {
            int mid = l + (r - l) / 2;

            build(index * 2, l, mid, a, seg);
            build(index * 2 + 1, mid + 1, r, a, seg);
            seg[index] = combine(seg[index * 2], seg[index * 2 + 1]);
        }
    }
}

void update(int index, int l, int r, int pos, int val, vector<Node> &seg)
{

    if (l == r)
    {
        seg[index].sum = val;
        seg[index].maxP = max(0, val);
        seg[index].maxS = max(0, val);
        return;
    }

    int mid = l + (r - l) / 2;

    if (pos <= mid)
    {
        update(index * 2, l, mid, pos, val, seg);
    }
    else
    {
        update(index * 2 + 1, mid + 1, r, pos, val, seg);
    }
    seg[index] = combine(seg[index * 2], seg[index * 2 + 1]);
}

Node query(int index, int l, int r, int qL, int qR, vector<Node> &seg)
{
    if (l == qL && r == qR)
    {
        return seg[index];
    }

    int mid = l + (r - l) / 2;
    Node n, n2;

    if (qL <= mid)
    {
        n = query(index * 2, l, mid, qL, min(qR, mid), seg);
    }

    if (qR >= mid + 1)
    {
        n2 = query(index * 2 + 1, mid + 1, r, max(mid + 1, qL), qR, seg);
    }

    return combine(n, n2);
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<Node> seg(4 * n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    build(1, 0, n - 1, a, seg);

    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int k, u;
            cin >> k >> u;
            k--;
            update(1, 0, n - 1, k, u, seg);
        }
        else
        {
            int b, c;
            cin >> b >> c;
            b--;
            c--;
            cout << query(1, 0, n - 1, b, c, seg).maxP << "\n";
        }
    }
}

int main()
{
    _ solve();
    return 0;
}
