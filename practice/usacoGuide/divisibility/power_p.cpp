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
template <typename T>
ostream &operator<<(ostream &out, vector<pair<T, T>> &a)
{
    for (auto &x : a)
        out << "(" << x.first << "," << x.second << ")" << ' ';
    return out;
};

void s()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;

    map<vector<pair<int, int>>, int> m;

    vector<int> primes;
    vector<bool> s(1e5 + 1);
    unordered_map<int, int> pi;

    for (int i = 2; i < s.size(); i++)
    {
        if (!s[i])
        {
            pi[i] = primes.size();
            primes.push_back(i);
            for (int j = i; j < s.size(); j += i)
            {
                s[j] = true;
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> f;

        int cn = a[i], p = 0;
        while (cn > 1 && p < primes.size())
        {
            while (cn % primes[p] == 0)
            {
                f[primes[p]]++;
                cn /= primes[p];
            }
            p++;
        }

        if (cn != 1)
            f[cn]++;

        vector<pair<int, int>> t, tar;

        for (auto &v : f)
        {
            if ((v.second % k) != 0)
            {
                t.push_back({v.first, v.second % k});
            }

            if (((k - (v.second % k)) % k) != 0)
            {
                tar.push_back({v.first, (k - (v.second % k)) % k});
            }
        }
        sort(all(t));
        sort(all(tar));
        ans += m[tar];
        m[t]++;
        // dbg(a[i]);
        // dbg(ans);
        // dbg(tar);
        // dbg(t);
        // cout nl;
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