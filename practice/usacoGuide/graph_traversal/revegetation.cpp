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

void dfs(int n, unordered_map<int, vector<pair<int, char>>> &g, vector<int> &c, unordered_set<int> &v, bool &pos)
{
    if (v.count(n) || !pos)
        return;

    v.insert(n);

    if (c[n] == -1)
        c[n] = 0;

    for (auto ne : g[n])
    {
        if (c[ne.first] == -1)
        {
            c[ne.first] = ne.second == 'S' ? c[n] : c[n] == 1 ? 0
                                                              : 1;
        }
        else if (ne.second == 'S')
        {
            if (c[n] != c[ne.first])
            {
                pos = false;
            }
        }
        else if (ne.second == 'D')
        {
            if (c[n] == c[ne.first])
            {
                pos = false;
            }
        }
        dfs(ne.first, g, c, v, pos);
    }
}

void s()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<pair<int, char>>> g;
    unordered_set<int> r;

    for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;

        int a, b;
        cin >> a >> b;
        a--;
        b--;

        r.insert(a);
        r.insert(b);

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vector<int> c(n, -1);
    unordered_set<int> v;

    bool pos = true;

    int mul = 0;
    for (int i = 0; i < n && pos; i++)
    {
        if (r.count(i) && !v.count(i))
        {
            mul++;
            dfs(i, g, c, v, pos);
        }
    }

    if (!pos)
    {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] == -1)
            mul++;
    }
    cout << "1" << string(mul, '0') << "\n";
}

int main()
{
    _;

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}