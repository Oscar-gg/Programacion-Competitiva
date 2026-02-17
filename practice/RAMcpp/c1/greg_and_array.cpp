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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    cin >> a;
    vector<vector<ll>> ev, ev2;
    vector<ll> d(m);

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[i] = c;
        ev.push_back({a, i, 1});
        ev.push_back({b + 1, i, -1});
    }

    for (ll i = 0; i < k; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        ev2.push_back({a, 1});
        ev2.push_back({b + 1, -1});
    }

    sort(all(ev2));
    sort(all(ev));

    vector<ll> freq(m);

    ll cf = 0, p = 0;

    for (ll i = 0; i < m; i++)
    {
        while (p < ev2.size() && i >= ev2[p][0])
        {
            cf += ev2[p][1];
            p++;
        }
        freq[i] = cf;
    }

    ll cd = 0;
    p = 0;

    for (ll i = 0; i < a.size(); i++)
    {
        while (p < ev.size() && i >= ev[p][0])
        {
            if (ev[p][1] < d.size())
            {
                cd += d[ev[p][1]] * freq[ev[p][1]] * ev[p][2];
            }
            p++;
        }

        a[i] += cd;
    }

    for (auto v : a)
    {
        cout << v << " ";
    }
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