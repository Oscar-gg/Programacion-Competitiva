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

vector<int> pnum(int n)
{
    vector<int> ret(32);
    for (int i = 0; i < 32; i++)
    {
        if ((1 << i) & n)
            ret[i]++;
    }
    return ret;
}
vector<int> f()
{
    int a, b, c, d, e, f;
    cout << "or 1 2\n";
    cout.flush();
    cin >> a;
    cout << "or 1 3\n";
    cout.flush();
    cin >> b;
    cout << "or 2 3\n";
    cout.flush();
    cin >> c;
    cout << "and 1 2\n";
    cout.flush();
    cin >> d;
    cout << "and 1 3\n";
    cout.flush();
    cin >> e;
    cout << "and 2 3\n";
    cout.flush();
    cin >> f;

    int x1 = (~d) & a, x2 = (~e) & b, x3 = (~f) & c;

    int s1 = 2 * d + x1, s2 = 2 * e + x2, s3 = 2 * f + x3;

    int r2 = (s1 + s2 - s3) / 2;

    int r1 = s1 - r2, r3 = s2 - r2;
    // dbg(r1);
    // dbg(r2);
    // dbg(r3);

    return {r2, r1, r3};
}

void s()
{
    int n, k;
    cin >> n >> k;

    vector<int> a = f();
    for (int i = 0; i < n - 3; i++)
    {
        cout << "or 1 " << i + 4 << "\n";
        cout.flush();
        int v;
        cin >> v;
        cout << "and 1 " << i + 4 << "\n";
        cout.flush();
        int b, nn;
        cin >> b;
        nn = b;

        v ^= a[0];
        nn |= v;

        a.push_back(nn);
    }

    sort(all(a));

    // for (auto v : a)
    // {
    //     cout << v << " ";
    // }
    // cout nl;

    cout << "finish " << a[k - 1] << "\n";
    cout.flush();
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