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

void s()
{
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (auto &v : a)
        cin >> v;
    unordered_set<int> ac(all(a));
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!ac.count(i))
            b.push_back(i);
    }

    sort(all(b));

    vector<int> f, f2(b.begin() + n / 2, b.end()), s, s2(b.begin(), b.begin() + n / 2);

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            f.push_back(a[i]);
        }
        else
        {

            s.push_back(a[i]);
        }
    }
    sort(all(f));
    sort(all(s));

    // dbg(f.size())
    //     dbg(f2.size())
    //         dbg(s.size())
    //             dbg(s2.size())
    int ans = 0;
    int l = 0, r = 0;

    while (l < f.size() && r < f2.size())
    {
        if (f2[r] > f[l])
        {
            ans++;
            r++;
            l++;
        }
        else
        {
            r++;
        }
    }
    l = 0, r = 0;

    while (l < s.size() && r < s2.size())
    {
        if (s2[r] < s[l])
        {
            ans++;
            r++;
            l++;
        }
        else
        {
            l++;
        }
    }

    cout << ans << "\n";
}

int main()
{
    _;

    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}