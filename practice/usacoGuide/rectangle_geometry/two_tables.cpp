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

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(10);
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

    int a, b, c, d;

    Rect()
    {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }

    void read()
    {
        cin >> a >> b >> c >> d;
    }
    Rect(int a, int b, int c, int d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    int w()
    {
        return c - a;
    }
    int h()
    {
        return d - b;
    }
};

void s()
{
    int w, h;
    cin >> w >> h;
    Rect r;
    r.read();
    int w2, h2;
    cin >> w2 >> h2;

    int ans = INT_MAX;

    if (r.h() + h2 <= h)
    {
        if (r.b < h2)
        {
            ans = min(ans, h2 - r.b);
        }
        else
        {
            ans = 0;
        }

        if (r.d > h - h2)
        {
            ans = min(ans, r.d - (h - h2));
        }
        else
        {
            ans = 0;
        }
    }
    if (r.w() + w2 <= w)
    {
        if (r.a < w2)
        {
            ans = min(ans, w2 - r.a);
        }
        else
        {
            ans = 0;
        }

        if (r.c > w - w2)
        {
            ans = min(ans, r.c - (w - w2));
        }
        else
        {
            ans = 0;
        }
    }

    if (ans == INT_MAX)
    {
        cout << "-1\n";
        return;
    }

    cout << std::fixed << std::setprecision(9) << (double)ans << "\n";
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