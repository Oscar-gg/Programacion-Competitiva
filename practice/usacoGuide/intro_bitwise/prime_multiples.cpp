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
typedef __int128_t lll;
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

istream &operator>>(istream &is, lll &v)
{
    string s;
    is >> s;
    v = 0;
    bool neg = !s.empty() && s[0] == '-';
    for (char c : s)
        if (isdigit((unsigned char)c))
            v = v * 10 + (c - '0');
    if (neg)
        v = -v;
    return is;
}

ostream &operator<<(ostream &os, lll v)
{ // by value — no separate `num`
    if (v == 0)
        return os << '0';
    if (v < 0)
    {
        os << '-';
        v = -v;
    }
    string s;
    while (v > 0)
    {
        s += char('0' + int(v % 10));
        v /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}

void s()
{
    lll n, k;
    cin >> k >> n;
    vector<lll> a(n);
    // cin >> a;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lll ans = 0;

    for (int i = 1; i < (1 << n); i++)
    {
        lll cur = 1;
        int bc = 0;
        for (int j = 0; j < n; j++)
        {
            if (cur <= k && (i & (1 << j)))
            {
                bc++;
                cur *= a[j];
            }
        }
        if (cur > k)
            continue;

        int sign = bc % 2 == 1;

        if (!sign)
            sign = -1;

        ans += (k / cur) * sign;
    }
    cout << ans << "\n";
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