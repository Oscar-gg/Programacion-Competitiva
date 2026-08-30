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

int main()
{
    _;

    int m = 1e6 + 1;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    vector<ll> pref(m), e(m), p(m);

    for (int i = 0; i < m; i++)
    {
        e[i] = i;
    }

    for (int i = 2; i < m; i++)
    {
        if (e[i] == i)
        {
            for (int j = e[i]; j < m; j += i)
            {
                e[j] -= e[j] / i;
            }
        }
    }

    for (int i = 2; i < m; i++)
    {
        for (int j = i, k = 1; j < m; k++, j += i)
        {
            p[j] += k * e[i];
        }
    }

    for (int i = 1; i < m; i++)
    {
        pref[i] = pref[i - 1] + p[i];
    }

    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << pref[n] << "\n";
    }

    return 0;
}