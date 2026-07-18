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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    // 01...
    // 10...
    vector<int> d1(n), d2(n), p1(n), p2(n);

    for (int i = 0; i < n; i++)
    {
        int cb = s[i] - '0';

        int p = i & 1;
        int p2 = p ^ 1;

        d1[i] = cb ^ p;
        d2[i] = d1[i] ^ 1;
    }

    p1[0] = d1[0];
    p2[0] = d2[0];

    for (int i = 1; i < n; i++)
    {
        p1[i] = p1[i - 1];
        p2[i] = p2[i - 1];

        if (d1[i] && !d1[i - 1])
            p1[i]++;
        if (d2[i] && !d2[i - 1])
            p2[i]++;
    }

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        r--, l--;
        int a1 = p1[r];
        if (l - 1 >= 0)
        {
            a1 -= p1[l - 1];
            if (d1[l - 1] && d1[l])
                a1++;
        }
        int a2 = p2[r];
        if (l - 1 >= 0)
        {
            a2 -= p2[l - 1];
            if (d2[l - 1] && d2[l])
                a2++;
        }

        int ans = min(a1, a2);
        if (ans <= k)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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