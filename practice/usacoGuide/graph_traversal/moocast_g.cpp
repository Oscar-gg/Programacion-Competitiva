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

ll d(pair<int, int> p1, pair<int, int> p2)
{
    ll x = abs(p1.first - p2.first), y = abs(p1.second - p2.second);
    return x * x + y * y;
}

void dfs(int node, vector<pair<int, int>> &a, unordered_set<int> &v, ll money)
{

    if (v.count(node))
        return;

    v.insert(node);

    for (int i = 0; i < a.size(); i++)
    {
        if (!v.count(i) && d(a[node], a[i]) <= money)
        {
            dfs(i, a, v, money);
        }
    }
}

bool pos(ll money, vector<pair<int, int>> &a)
{
    unordered_set<int> v;

    dfs(0, a, v, money);

    return v.size() == a.size();
}

void s()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (auto &v : a)
        cin >> v.first >> v.second;

    ll l = 0, r = pow(25000, 2) * 2;

    while (l < r)
    {
        ll m = l + (r - l) / 2;

        if (pos(m, a))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << l << "\n";
}

int main()
{
    _;

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}