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

int msb(ll v)
{
    for (ll i = 32; i >= 0; i--)
    {
        if (v & (1ll << i))
            return i;
    }
    return -1;
}

void s()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);

    for (auto &v : a)
    {
        cin >> v;
    }

    sort(all(a));
    reverse(all(a));

    vector<int> used;
    for (int i = 0; i < 31 && i < a.size(); i++)
    {
        used.push_back(a[i]);
    }

    while (q--)
    {
        ll c;
        cin >> c;
        ll cost = 0;

        priority_queue<int> pq(all(used));

        while (c > 0 && !pq.empty())
        {

            auto t = pq.top();
            // dbg(t);
            pq.pop();

            if (t == 0)
                break;

            if (t >= c)
            {
                c = 0;
                break;
            }

            if (msb(c) == msb(t))
            {
                pq.push(t - (1ll << msb(c)));
                c -= 1ll << msb(c);
            }
            else
            {
                cost += (1ll << msb(c)) - t;
                c -= 1ll << msb(c);
            }
        }

        cout << c + cost << "\n";
    }
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