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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

bool pos(vector<int> &a, int m, int k)
{
    int used = 0;
    int current = INT_MIN;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > current + m)
        {
            used++;
            current = a[i] + m;
        }
    }

    return used <= k;
}

void s()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &v : a)
        cin >> v;

    sort(all(a));

    int l = 0, r = 1e4 * 5 + 1;

    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (pos(a, m, k))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << l nl;
}

int main()
{
    _;

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}