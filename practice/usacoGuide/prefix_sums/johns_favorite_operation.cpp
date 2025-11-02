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

ll cost(ll num, ll tar)
{
    ll mod = (num % tar + tar) % tar;

    if (mod > tar - mod)
    {
        return (tar - mod) * -1;
    }
    return mod;
}

ll boredom(ll x, vector<ll> &a, ll m)
{
    ll ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        // dbg(a[i] - x);
        // dbg(x);
        // dbg(cost(a[i] - x, m));
        ans += abs(cost(a[i] - x, m));
    }
    return ans;
}

void s()
{
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);

    for (auto &v : a)
        cin >> v;

    vector<ll> costs(n);

    for (ll i = 0; i < n; i++)
    {
        costs[i] = cost(a[i], m);
    }

    sort(all(costs));

    // for (auto c : costs)
    // {
    //     cout << c << " ";
    // }

    // cout << "\n";

    int mid = costs.size() / 2;
    ll ans = boredom(costs[mid], a, m);
    if (mid + 1 < costs.size())
    {
        ans = min(ans, boredom(costs[mid + 1], a, m));
    }

    if (mid - 1 >= 0)
    {
        ans = min(ans, boredom(costs[mid - 1], a, m));
    }

    cout << ans << "\n";
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