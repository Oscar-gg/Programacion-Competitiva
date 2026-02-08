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

void dfs(int node, int s, vector<int> &ans, vector<vector<int>> &a, bool st)
{
    if (ans[node] != 0 && !st)
        return;

    ans[node] = s;

    for (auto n : a[node])
    {
        dfs(n, s + 1, ans, a, false);
    }
}

void findC(int node, vector<int> &ans, vector<int> &a, vector<vector<int>> &rev)
{
    int p1 = a[node], p2 = a[a[node]];
    while (p1 != p2)
    {
        p1 = a[p1];
        p2 = a[a[p2]];
    }
    p1 = node;
    while (p1 != p2)
    {
        p1 = a[p1];
        p2 = a[p2];
    }

    int s = 1;
    vector<int> upd{p2};
    p2 = a[p2];
    while (p1 != p2)
    {
        upd.push_back(p2);
        s++;
        p2 = a[p2];
    }

    for (auto v : upd)
    {
        ans[v] = s;
    }

    for (auto v : upd)
    {
        dfs(v, s, ans, rev, true);
    }
}

void s()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> rev(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        rev[a[i]].push_back(i);
    }

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!ans[i])
        {
            findC(i, ans, a, rev);
        }
    }

    for (auto v : ans)
        cout << v << " ";

    cout nl;
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