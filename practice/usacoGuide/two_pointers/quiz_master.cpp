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

void factors(int lim, vector<vector<int>> &res)
{
    res = vector<vector<int>>(lim + 1);
    for (int i = 1; i <= lim; i++)
    {
        for (int j = i; j <= lim; j += i)
        {
            res[j].push_back(i);
        }
    }
}

void s(vector<vector<int>> &factors)
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for (auto &v : a)
        cin >> v;

    sort(all(a));

    vector<int> cf(m + 1);

    int l = 0, r = 0, curr = 0, ans = INT_MAX;

    while (r < n)
    {

        for (auto f : factors[a[r]])
        {
            if (f > m)
                break;
            if (cf[f] == 0)
            {
                curr++;
            }
            cf[f]++;
        }

        while (curr == m)
        {
            ans = min(ans, a[r] - a[l]);
            for (auto f : factors[a[l]])
            {
                if (f > m)
                    break;
                if (cf[f] == 1)
                {
                    curr--;
                }
                cf[f]--;
            }
            l++;
        }
        r++;
    }

    if (ans == INT_MAX)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
    }
}

int main()
{
    _;

    vector<vector<int>> f;
    factors(1e5, f);

    int t = 1;
    cin >> t;

    while (t--)
        s(f);

    return 0;
}