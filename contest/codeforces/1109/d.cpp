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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    cin >> a;

    vector<ll> b(m);
    cin >> b;
    for (auto &v : b)
        v--;

    sort(all(b));
    ll cb = m - 1, lb = -1;
    ll pos = 0, neg = 0;

    for (ll i = n - 1; i >= 0; i--)
    {
        if (cb >= 0 && i == b[cb])
        {
            if (lb != -1)
            {
                if (neg > pos)
                {
                    for (ll j = b[cb] + 1; j <= lb; j++)
                    {
                        a[j] *= -1;
                    }
                }
            }
            lb = b[cb];
            cb--;
            pos = 0, neg = 0;
        }
        if (a[i] > 0)
        {
            pos += a[i];
        }
        else
        {
            neg += abs(a[i]);
        }
    }

    ll ans = 0;
    for (auto v : a)
        ans += v;

    ll ans2 = 0;

    for (ll i = 0; i <= b[0]; i++)
    {
        a[i] *= -1;
    }

    for (auto v : a)
        ans2 += v;

    cout << max(ans, ans2) << "\n";
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