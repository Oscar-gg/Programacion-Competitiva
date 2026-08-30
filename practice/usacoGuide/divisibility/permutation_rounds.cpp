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

void dfs(int n, vector<int> &a, int &s)
{
    if (a[n] == -1)
        return;
    s++;
    int cn = a[n];
    a[n] = -1;
    dfs(cn, a, s);
}

void lcmC(ll a, vector<int> &b, vector<int> &p)
{
    vector<int> pf(b.size());
    int pt = 0;

    while (a > 1 && pt < p.size())
    {
        while (a % p[pt] == 0)
        {
            pf[pt]++;
            a /= p[pt];
        }
        pt++;
    }

    for (int i = 0; i < b.size(); i++)
    {
        b[i] = max(b[i], pf[i]);
    }
}

void s()
{
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    for (auto &v : a)
        v--;

    vector<ll> c;
    int m = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != -1)
        {
            int l = 0;
            dfs(i, a, l);
            c.push_back(l);
            m = max(m, l);
        }
    }

    vector<int> sieve(m + 1);
    vector<int> p;

    for (int i = 2; i < sieve.size(); i++)
    {
        if (!sieve[i])
        {
            p.push_back(i);
            for (int j = i; j < sieve.size(); j += i)
            {
                sieve[j] = true;
            }
        }
    }

    vector<int> ans(p.size());

    for (int i = 0; i < c.size(); i++)
    {
        lcmC(c[i], ans, p);
    }

    ll f = 1;

    for (int i = 0; i < ans.size(); i++)
    {
        while (ans[i])
        {
            f *= p[i];
            f %= MOD;
            ans[i]--;
        }
    }

    cout << f << "\n";
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