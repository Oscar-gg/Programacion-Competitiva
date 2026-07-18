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

void dfs(pair<int, int> node, unordered_map<int, vector<pair<int, int>>> &g, vector<int> &pos, vector<int> &num, unordered_set<int> &v)
{

    if (v.count(node.first))
        return;
    pos.push_back(node.first);
    num.push_back(node.second);

    v.insert(node.first);

    for (auto n : g[node.first])
    {
        dfs(n, g, pos, num, v);
    }
}

void s()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    cin >> a;

    for (auto &v : a)
        v--;

    unordered_map<int, vector<pair<int, int>>> g;

    for (int i = 0; i < n; i++)
    {
        if (i + x < n)
        {
            g[i].push_back({i + x, a[i + x]});
            g[i + x].push_back({i, a[i]});
        }

        if (x != y && i + y < n)
        {
            g[i].push_back({i + y, a[i + y]});
            g[i + y].push_back({i, a[i]});
        }
    }
    unordered_set<int> v;
    for (int i = 0; i < n; i++)
    {
        if (!v.count(i))
        {
            vector<int> pos, num;
            dfs({i, a[i]}, g, pos, num, v);

            sort(all(pos));
            sort(all(num));
            for (int j = 0; j < pos.size(); j++)
            {
                if (pos[j] != num[j])
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
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