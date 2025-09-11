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
#define nl << "\n";

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

struct Rect
{
    ll a, b, c, d;

    void read()
    {
        cin >> a >> b >> c >> d;
    }

    Rect(ll a, ll b, ll c, ll d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    Rect()
    {
        this->a = 0;
        this->b = 0;
        this->c = 0;
        this->d = 0;
    }

    ll area()
    {
        return (c - a) * (d - b);
    }

    Rect intersect(Rect &r)
    {

        ll na = max(a, r.a);
        ll nb = max(b, r.b);
        ll nc = min(c, r.c);
        ll nd = min(d, r.d);

        if (na >= nc || nb >= nd)
            return Rect();

        Rect nR(na, nb, nc, nd);

        return nR;
    }
    void print()
    {
        cout << a << " " << b << " " << c << " " << d << "\n";
    }
};

void s()
{
    Rect a, b, c;
    a.read();
    b.read();
    c.read();

    ll visibleArea = a.area();
    visibleArea -= b.intersect(a).area();
    visibleArea -= c.intersect(a).area();

    Rect d = b.intersect(a).intersect(c);

    // c.intersect(a).print();
    // dbg(c.intersect(a).area());

    // b.intersect(a).print();
    // b.intersect(a).intersect(c).print();

    // dbg(b.intersect(a).area());
    // dbg(c.intersect(a).area());

    // dbg(d.area());

    if (d.area() > 0)
    {
        visibleArea += d.area();
    }

    if (visibleArea > 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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