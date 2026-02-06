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

void dfs(int node, unordered_map<int, unordered_set<int>> &g, set<int> &v, unordered_set<int> &cv, int n)
{
    v.erase(node);
    cv.insert(node);

    int st = 0;

    while (st <= n)
    {
        auto it = v.upper_bound(st);
        if (it == v.end())
            break;
        int num = *it;
        if (!g[node].count(num))
        {
            dfs(num, g, v, cv, n);
        }
        st = num;
    }
}

void s()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, unordered_set<int>> g;

    set<int> v;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }

    for (int i = 1; i <= n; i++)
    {
        v.insert(i);
    }

    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {

        if (v.count(i))
        {
            unordered_set<int> cv;
            dfs(i, g, v, cv, n);
            ans.push_back(cv.size());
        }
    }

    sort(all(ans));
    cout << ans.size() nl;
    cout << ans nl;
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