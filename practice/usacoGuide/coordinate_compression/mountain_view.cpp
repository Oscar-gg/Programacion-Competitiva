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

void s()
{
    ll n;
    cin >> n;
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        m[a] = max(m[a], b);
    }

    vector<vector<ll>> px(m.size());

    ll it = 0;
    for (auto e : m)
    {
        px[it] = {0, e.first, e.second};
        it++;
    }

    ll l = 0;

    for (ll i = 1; i < px.size(); i++)
    {
        if (px[l][2] - abs(px[l][1] - px[i][1]) >= px[i][2])
        {
            px[i][0] = -1;
        }
        else
        {
            l = i;
        }
    }

    l = px.size() - 1;

    for (ll i = px.size() - 2; i >= 0; i--)
    {
        if (px[l][2] - abs(px[l][1] - px[i][1]) >= px[i][2])
        {
            px[i][0] = -1;
        }
        else
        {
            l = i;
        }
    }
    ll ans = 0;
    for (auto v : px)
        if (!v[0])
            ans++;
    cout << ans << "\n";
}

int main()
{
    _;

    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}