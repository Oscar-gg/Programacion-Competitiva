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
typedef vector<ll> vi;
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

void s()
{
    ll n, m, k;
    cin >> n >> m >> k;

    unordered_map<ll, vector<vector<ll>>> umap;

    for (int i = 0; i < m; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        umap[a].push_back({b, c, d});
        umap[b].push_back({a, c, d});
    }

    priority_queue<vi, vector<vi>, greater<vi>> q;
    q.push({0, 1, 0, -1});

    vector<vector<ll>> v(n + 1, vector<ll>(11, LLONG_MAX));
    // vector<ll> val(n + 1, INT_MAX);

    while (!q.empty())
    {
        auto ne = q.top();
        q.pop();

        if (ne[0] >= v[ne[1]][ne[2]])
        {
            continue;
        }

        v[ne[1]][ne[2]] = ne[0];

        for (int i = max(ne[2], 1ll); i < v[ne[1]].size(); i++)
        {
            v[ne[1]][i] = min(v[ne[1]][i], v[ne[1]][i - 1]);
        }

        // val[ne[1]] = min(val[ne[1]], ne[2]);

        if (ne[1] == n)
        {
            cout << ne[0] << "\n";
            return;
        }

        for (auto n : umap[ne[1]])
        {
            if (n[3] == ne[1])
                continue;

            int K = ne[2] + 1;

            if (ne[0] + n[1] < v[n[0]][ne[2]])
            {
                q.push({ne[0] + n[1], n[0], ne[2], ne[1]});
            }

            if (K <= k && n[2] != -1 && ne[0] + n[1] < v[n[0]][K])
            {
                q.push({ne[0] + n[2], n[0], K, ne[1]});
            }
        }
    }

    dbg("a");
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