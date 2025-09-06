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

ll sum(int n, int a1, int an)
{
    ll s = (a1 + an) * n;
    s = s / 2;
    return s;
}

int m(int k, int x)
{
    int p = 0;
    int s = 0;
    int t = 0;

    while (p < k)
    {
        if (s < x)
        {
            s++;
        }
        else
        {
            if (p + s + 1 + sum(s - x + 1, x, s) < k)
            {
                s++;
            }
            else if (p + sum(s - x + 1, x, s) > k)
            {
                s--;
            }
        }

        p += s;
        // dbg(s);
        // dbg(p);
        // dbg(k);

        t++;
    }
    return t;
}

void s()
{
    int k, n;
    cin >> k >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (auto v : a)
    {
        cout << m(k, v) << "\n";
    }
}

int main()
{
    _;

    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}