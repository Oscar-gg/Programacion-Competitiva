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

void solve()
{
    int n, k;
    cin >> n >> k;

    ll cost = 0;
    ll it = 0;

    vector<int> pick;

    for (ll p = 1; n > 0; p *= 3)
    {
        pick.push_back(0);
        while (n % 3)
        {
            n--;
            // cout << p << " " << 3 * p + it * p / 3 << "\n";
            cost += 3 * p + it * p / 3;
            pick.back()++;
        }
        n /= 3;
        it++;
    }
    int deals = 0;
    for (auto x : pick)
    {
        deals += x;
    }

    if (deals > k)
    {
        cout << "-1\n";
        return;
    }

    for (int i = pick.size() - 2; i >= 0; i--)
    {
        if (pick[i + 1])
        {
            int pos = min((k - deals) / 2, pick[i + 1]);

            deals += 2 * pos;
            pick[i + 1] -= pos;
            pick[i] += 3 * pos;
        }
    }

    cost = 0;
    ll p = 1;
    for (int i = 0; i < pick.size(); i++)
    {
        cost += (p * 3 + i * p / 3) * pick[i];
        p *= 3;
    }

    cout << cost << "\n";
}

int main()
{
    _

        int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}