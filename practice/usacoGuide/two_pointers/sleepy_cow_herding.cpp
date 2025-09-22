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

int minM(vector<int> &a)
{

    int l = 0, n = a.size();

    if (a[n - 2] - a[0] == n - 2 && a[n - 1] - a[0] > n)
    {
        return 2;
    }

    if (a[n - 1] - a[1] == n - 2 && a[n - 1] - a[0] > n)
    {
        return 2;
    }

    int ans = INT_MAX;

    for (int r = 0; r < n; r++)
    {
        while (a[r] - a[l] >= n)
            l++;
        ans = min(ans, n - (r - l + 1));
    }

    return ans;
}

int maxM(vector<int> &a)
{
    int tot = 0;

    for (int i = 1; i < a.size() - 1; i++)
    {
        tot += a[i] - a[i - 1] - 1;
    }
    int tot2 = 0;

    for (int i = a.size() - 1; i >= 2; i--)
    {
        tot2 += a[i] - a[i - 1] - 1;
    }

    return max(tot, tot2);
}

void s()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v : a)
        cin >> v;

    sort(all(a));

    cout << minM(a) << "\n";
    cout << maxM(a) << "\n";
}

int main()
{
    _;

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}