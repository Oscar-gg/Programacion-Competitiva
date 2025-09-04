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
#define nl << "\n";

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

void s()
{
    int lim = 10;
    vector<int> a(lim), b(lim);

    for (auto &v : a)
        cin >> v;
    for (auto &v : b)
        cin >> v;

    unordered_set<int> pos;

    for (int i = 0; i < (1 << lim); i++)
    {
        int c = 0;
        int q = 0;
        for (int j = 0; j < lim; j++)
        {
            if (i & (1 << j))
            {
                c++;
                q += a[j];
            }
        }

        if (c == lim)
        {
            pos.insert(q);
        }
        else if (c == lim - 1)
        {
            for (int j = 0; j < lim; j++)
            {
                pos.insert(q + b[j]);
            }
        }
        else if (c == lim - 2)
        {
            for (int j = 0; j < lim; j++)
            {
                for (int k = j + 1; k < lim; k++)
                {
                    pos.insert(q + b[j] + b[k]);
                }
            }
        }
    }

    cout << pos.size() << "\n";
}

int main()
{
    _;

    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}