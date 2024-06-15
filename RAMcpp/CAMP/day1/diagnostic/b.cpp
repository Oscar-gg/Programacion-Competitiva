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

bool isPossible(long long int t, long long int s, ll k, ll &cost)
{
    // cout << "t: " << t << "\n";
    if (t > 2 * k-1)
        return false;

    ll fhL = min(t, k);
    // dbg(fhL);

    ll fh = (fhL * (1 + fhL)) / 2.0;
    // long double fh = fhL / 2.0 * (1 + fhL) / 2.0; //(fhL * (1 + fhL)) / 2;

    ll sh = 0;

    if (t > k)
    {
        sh = t - k;
        // dbg(sh);
        // dbg(k)
        // dbg(k-sh)
        // sh = (sh * (k + (k - sh - 1))) / 2;
        sh = (sh * (k - 1 + (k - sh))) / 2;
    }

    // cout << t << " " << fh << " " << sh << "\n";

    cost = fh + sh;
    if (s >= fh + sh)
        return true;

    return false;
}


void solve()
{
    long long int k, x, cost;
    cin >> k >> x;

    long long int l = 0, r = 1e18 + 4;

    if (k == 1)
    {
        cout << 1 << "\n";
        return;
    }

    while (l < r)
    {
        ll m = l + (r - l) / 2;
        // cout << m << "\n";

        if (isPossible(m, x, k, cost))
        {
            l = m;
        }
        else
        {
            r = m - 1;
        }
        if (r - l == 1)
        {
            if (isPossible(r, x, k, cost))
            {
                l = r;
            }
            else
            {
                r = l;
            }
        }
    }

    isPossible(r, x, k, cost);

    if (l + 1 < 2 * k && cost < x)
    {
        // cout << "aa";
        cout << l + 1 << "\n";
    }
    else
    {
        // cout << min(l, 2 * k + 1) << "\n";
        cout << l << "\n";
    }
}

int main()
{
    _ int t;
    cin >> t;
    while (t--)
        solve();

    // bool a  = isPossible(1608737402, 923456789987654321, 1000000000);
    // 1000000000 923456789987654321
    // if (a){
    //     cout << "a is true";
    // } else {
    //     cout << "a is false";
    // }
    return 0;
}