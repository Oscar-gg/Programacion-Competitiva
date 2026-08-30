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

void s(vector<int> &p)
{
    unordered_set<int> primes;
    int n, cn;
    cin >> n;
    cn = n;

    for (int i = 0; i < p.size() && n >= p[i]; i++)
    {
        while (n % p[i] == 0)
        {
            primes.insert(p[i]);
            n /= p[i];
        }
    }

    if (n != 1)
    {
        primes.insert(n);
    }
    vector<int> primes2(all(primes));

    int l = primes2.size();
    int ans = 0;

    for (int i = 0; i < (1 << l); i++)
    {
        ll cur = 1, bc = 0;

        for (int j = 0; j < l; j++)
        {
            if (i & (1 << j))
            {
                bc++;
                cur *= primes2[j];
            }
        }

        if (bc & 1)
        {
            ans -= cn / cur;
        }
        else
        {
            ans += cn / cur;
        }
    }

    cout << ans << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    vector<int> primes;
    vector<int> used(sqrt(1e6) + 1);

    for (int i = 2; i < used.size(); i++)
    {
        if (!used[i])
        {
            primes.push_back(i);

            for (int j = i; j < used.size(); j += i)
            {
                used[j] = true;
            }
        }
    }

    int t = 1;
    cin >> t;

    while (t--)
        s(primes);
    return 0;
}