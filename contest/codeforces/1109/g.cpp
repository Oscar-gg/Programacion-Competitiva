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
#define MAXN 10
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};

template <class T>
struct SegTree
{
    T U = 0;
    T F(T a, T b) { return max(a, b); }
    int N;
    vector<T> t;
    SegTree() {}
    SegTree(int N) : N(N), t(4 * N, U) {}
    void upd(int I, T V) { upd(I, V, 1, 1, N); }
    void upd(int I, T V, int i, int l, int r)
    {
        if (l == r)
        {
            t[i] = V;
            return;
        }
        int m = (l + r) / 2;
        if (I <= m)
            upd(I, V, i * 2, l, m);
        else
            upd(I, V, i * 2 + 1, m + 1, r);
        t[i] = F(t[i * 2], t[i * 2 + 1]);
    }
    T qry(int L, int R) { return qry(L, R, 1, 1, N); }
    T qry(int L, int R, int i, int l, int r)
    {
        if (L <= l && r <= R)
            return t[i];
        if (R < l || L > r)
            return U;
        int m = (l + r) / 2;
        return F(qry(L, R, i * 2, l, m), qry(L, R, i * 2 + 1, m + 1, r));
    }
};
const int maxn = 2e5 + 5;

void s()
{
    int n;
    cin >> n;
    SegTree<int> tree(n);
    vector<int> dp(n);
    vector<int> a(n);
    cin >> a;
    vector<vector<pair<int, int>>> add(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        for (auto p : add[i])
        {
            tree.upd(p.first, p.second);
        }

        if (i - a[i] - 1 < 0)
        {
            dp[i] = a[i];
        }
        else
        {
            dp[i] = a[i] + tree.qry(1, 1 + max(0, i - a[i] - 1));
        }

        if (i + a[i] + 1 < n)
        {
            add[i + a[i] + 1].push_back({i + 1, dp[i]});
        }
        ans = max(ans, dp[i]);
    }

    // cout << dp << "\n";

    cout << ans << "\n";
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