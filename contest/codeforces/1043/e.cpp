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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

ll cost(int x, int y, int z, vector<ll> &prefA, vector<ll> &prefB)
{
    ll res = 0;

    if (x > 0 && prefA.size() > 0)
    {
        res += prefA.back();
        if ((int)prefA.size() - x - 1 >= 0)
        {
            res -= prefA[prefA.size() - x - 1];
        }
    }

    ll takesB = min({z - x, y, (int)prefB.size()});

    if (takesB > 0)
    {
        res += prefB.back();
        if ((int)prefB.size() - takesB - 1 >= 0)
            res -= prefB[prefB.size() - takesB - 1];
    }

    // cout << "cost: " << x << " " << y << " " << z << " " << res << "\n";
    return res;
}

void s()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> b(m);
    for (auto &x : b)
        cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> prefA = a, prefB = b;

    for (int i = 1; i < prefA.size(); i++)
    {
        prefA[i] += prefA[i - 1];
    }

    for (int i = 1; i < prefB.size(); i++)
    {
        prefB[i] += prefB[i - 1];
    }

    // cout << "arrA: ";
    // for (auto c : prefA)
    //     cout
    //         << c << " ";
    // cout << "\n";
    // cout << "arrB: ";
    // for (auto c : prefB)
    //     cout
    //         << c << " ";
    // cout << "\n";

    for (int i = 0; i < q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        int l = 0;
        int r = min(x, z);

        while (r - l > 3)
        {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;

            // cout << "rl: " << r << " " << l << "\n";

            // cout << "m1: " << m1 << "\n";
            // cout << "m2: " << m2 << "\n";

            ll cm1 = cost(m1, y, z, prefA, prefB), cm2 = cost(m2, y, z, prefA, prefB);

            if (cm1 == cm2)
            {
                l = m1, r = m2;
            }
            else if (cm1 > cm2)
            {
                r = m2;
            }
            else
            {
                l = m1;
            }
        }

        ll ans = 0;

        for (int j = l; j <= r; j++)
        {
            ans = max(ans, cost(j, y, z, prefA, prefB));
        }

        cout << ans << "\n";
    }
}

int main()
{
    _ int t;
    cin >> t;

    while (t--)
        s();

    return 0;
}
