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

int getI(int n)
{
    return n / 100;
}

int getS(int n)
{
    return (n / 100) * 100;
}

void update(int index, int upIndex, int l, int r, vector<int> &seg)
{
    if (l <= r)
    {
        if (l == r)
        {
            seg[index]++;
        }
        else
        {
            int m = l + (r - l) / 2;
            if (upIndex <= m)
            {
                update(index * 2, upIndex, l, m, seg);
            }
            else
            {
                update(index * 2 + 1, upIndex, m + 1, r, seg);
            }
            seg[index] = seg[index * 2] + seg[index * 2 + 1];
        }
    }
}

int query(int index, int l, int r, int ql, int qr, vector<int> &seg)
{
    if (ql <= qr)
    {
        if (ql == l && qr == r)
            return seg[index];

        int m = l + (r - l) / 2;

        return query(index * 2, l, m, ql, min(qr, m), seg) + query(index * 2 + 1, m + 1, r, max(ql, m + 1), qr, seg);
    }
    return 0;
}

int queryW(int val, vector<int> &seg, map<int, int> &freq)
{

    int c = query(1, 0, 1e7 + 1, getI(val), getI(1e9 + 1), seg);
    for (auto it = freq.lower_bound(getS(val)); it != freq.end() && it->first <= val; it++)
    {
        if (it->first <= val)
            c -= it->second;
    }

    return c;
}

void s()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> ac(n);
    vector<int> bgL(n);
    vector<int> seg(4 * (1e7 + 1));
    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
        update(1, getI(a[i]), 0, 1e7 + 1, seg);
        bgL[i] = queryW(a[i], seg, freq);
    }

    for (int i = 0; i < n; i++)
    {
        ac[i - min(bgL[i], k)].push_back(a[i]);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        for (auto v : ac[i])
            pq.push(v);

        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}