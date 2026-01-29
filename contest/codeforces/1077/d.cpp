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

pair<int, int> h(ll x, ll y)
{
    ll minD = INT_MAX;
    pair<int, int> p = {0, 0};

    for (int i = 0; i < (x + 1) * 2; i++)
    {
        for (int j = 0; j < (y + 1) * 2; j++)
        {
            if (!(i & j))
            {
                if (minD > abs(x - i) + abs(y - j))
                {
                    minD = abs(x - i) + abs(y - j);
                    p.first = i;
                    p.second = j;
                }
            }
        }
    }

    return p;
}

ll tDiff(ll tar, ll &p, ll blocked)
{
    ll at = 0;
    ll highest = 0;

    // set all av ones
    for (ll i = 0; i < 32; i++)
    {
        ll ith = 1ll << i;

        if (ith & tar)
            highest = i;

        if (blocked & ith)
        {
            continue;
        }
        if (ith & tar)
            at |= ith;
    }

    ll at2 = 0;

    // try with higher bit
    for (ll i = highest; i < 32; i++)
    {
        ll ith = 1ll << i;
        if (blocked & ith)
            continue;

        at2 = ith;
        break;
    }

    // try with all lower bits
    ll at3 = at;

    for (ll i = 0; i < 32; i++)
    {
        ll ith = 1ll << i;

        if (blocked & ith || ith & at3)
        {
            continue;
        }
        else
        {
            ll tat3 = at3 | ith;
            if (abs(tat3 - tar) > abs(at3 - tar))
                break;

            at3 |= ith;
        }
    }

    if (abs(at3 - tar) < abs(at - tar) && abs(at3 - tar) < abs(at2 - tar))
    {
        p = at3;
        return abs(at3 - tar);
    }

    if (abs(at - tar) < abs(at2 - tar))
    {
        p = at;
        return abs(at - tar);
    }
    p = at2;

    return abs(at2 - tar);
}

void s()
{
    ll x, y;
    cin >> x >> y;

    ll minD = x + y;
    ll minP = 0, minQ = 0;
    ll tP = 0, tQ = 0;
    for (ll i = 0; i < 32; i++)
    {
        if (x & (1ll << i))
        {
            tP |= (1ll << i);
            ll ttQ = 0;
            ll tdiff = tDiff(y, ttQ, tP);
            if (abs(tP - x) + abs(y - ttQ) < minD)
            {
                minD = abs(tP - x) + abs(y - ttQ);
                minP = tP;
                minQ = ttQ;
            }
        }
        if (y & (1ll << i))
        {
            tQ |= (1ll << i);

            ll ttP = 0;
            ll tdiff = tDiff(x, ttP, tQ);

            if (abs(ttP - x) + abs(y - tQ) < minD)
            {
                minD = abs(ttP - x) + abs(y - tQ);
                minP = ttP;
                minQ = tQ;
            }
        }
    }
    if ((minP & minQ) != 0)
    {
        throw invalid_argument("logic error");
    }

    // dbg(minD);
    cout << minP << " " << minQ << "\n";

    pair<int, int> bf = h(x, y);
    cout << bf.first << " " << bf.second << "\n";

    if (minD != abs(bf.first - x) + abs(bf.second - y))
    {
        cout << "(" << minD << " " << abs(bf.first - x) + abs(bf.second - y) << ")" << endl;
    }
}

ll closest(ll block, ll tar, ll &q)
{
    ll cur = 0;
    ll best = 0;

    ll hg = 0;

    bool high = false;

    for (int i = 30; i >= 0; i--)
    {
        int ith = 1 << i;
        if (ith & tar)
            hg = ith;

        if (ith & block)
        {
            continue;
        }

        ll pos = cur | ith;

        if (abs(pos - tar) < abs(best - tar))
        {
            best = pos;
        }

        if (pos <= tar)
        {
            cur = pos;
        }
    }

    int ith = hg + 1;

    if (((1 << ith) & block) == 0)
    {
        if (abs((1 << ith) - tar) < abs(best - tar))
        {
            best = 1 << ith;
        }
    }
    q = best;

    return block + best;
}

void s2()
{
    int x, y;
    cin >> x >> y;

    ll minD = x + y;
    ll p = 0, q = 0;

    closest(x, y, q);
    closest(y, x, p);

    ll n1, n2;
    if (abs(y - q) < abs(x - p))
    {
        n1 = x, n2 = q;
    }
    else
    {
        n1 = p, n2 = y;
    }

    cout << n1 << " " << n2 << "\n";

    // pair<int, int> bf = h(x, y);
    // minD = abs(x - n1) + abs(y - n2);

    // if ((n1 & n2) != 0)
    // {
    //     cout << n1 << " " << n2 << "\n";
    //     cout << "MALFORMED\n";
    // }

    // if (minD != abs(bf.first - x) + abs(bf.second - y))
    // {
    //     dbg(x);
    //     dbg(y);
    //     cout << n1 << " " << n2 << "\n";
    //     cout << bf.first << " " << bf.second << "\n";
    //     cout << "(" << minD << " " << abs(bf.first - x) + abs(bf.second - y) << ")" << endl;
    // }
    // dbg(p);
    // dbg(q);
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    // srand(time(NULL));
    int t = 1;
    cin >> t;
    while (t--)
        s2();

    // cout << 1000 << "\n";
    // for (int i = 0; i < 1000; i++)
    // {
    //     cout << (rand() % 256) << " " << (rand() % 256) << "\n";
    // }

    return 0;
}