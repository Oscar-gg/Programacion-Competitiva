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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

bool pos(vector<ll> &a, ll m, ll b, ll c)
{
    ll ind = 0;
    ll cur = 1;
    ll used = 1;

    for (ll i = 1; i < a.size(); i++)
    {
        if (cur == c || a[i] - a[ind] > m)
        {
            ind = i;
            cur = 1;
            used++;
        }
        else
        {
            cur++;
        }
    }

    return used <= b;
}

void s()
{
    ll n, m, c;
    cin >> n >> m >> c;
    vector<ll> a(n);

    for (auto &v : a)
        cin >> v;

    sort(all(a));

    ll l = 0, r = 1e9 + 1;

    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (pos(a, mid, m, c))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << "\n";
}

int main()
{
    _;

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}