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
    vector<ll> ans(n);
    vector<pair<ll, ll>> a;
    set<ll> coord;
    for (ll i = 0; i < n; i++)
    {
        ll p1, p2;
        cin >> p1 >> p2;
        a.push_back({p1, true});
        a.push_back({p2, false});
        coord.insert(p1);
        coord.insert(p2);
    }

    sort(all(a));
    vector<ll> coords(coord.begin(), coord.end());

    ll cur = 0;
    ll pt = 0;

    for (ll i = 0; i < coords.size(); i++)
    {
        ll incoming = 0, outgoing = 0;
        while (pt < a.size() && a[pt].first == coords[i])
        {
            if (a[pt].second)
                outgoing++;
            else
                incoming++;

            pt++;
        }

        ll atPoint = cur + outgoing;
        if (atPoint > 0)
            ans[atPoint - 1]++;

        cur += outgoing - incoming;

        if (cur > 0 && i != (coords.size() - 1))
            ans[cur - 1] += coords[i + 1] - coords[i] - 1;
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