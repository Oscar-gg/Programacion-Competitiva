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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &v : a)
        cin >> v;
    for (auto &v : b)
        cin >> v;
    string s;
    cin >> s;

    sort(all(a));
    sort(all(b));
    // for (auto v : a)
    //     cout << v << " ";

    // cout nl;
    vector<int> l(n, INT_MAX);
    vector<int> r(n, INT_MAX);

    int p = 0;
    for (int i = 0; i < n; i++)
    {

        while (p + 1 < m && b[p + 1] <= a[i])
            p++;

        // dbg(b[p]);
        // dbg(a[i]);

        if (b[p] <= a[i])
        {
            l[i] = a[i] - b[p];
        }
    }
    p = m - 1;
    for (int i = n - 1; i >= 0; i--)
    {

        while (p - 1 >= 0 && b[p - 1] >= a[i])
            p--;

        if (b[p] >= a[i])
        {
            r[i] = b[p] - a[i];
        }
    }

    unordered_map<int, vector<int>> pL, pR;

    for (int i = 0; i < n; i++)
    {
        pL[l[i]].push_back(a[i]);
        pR[r[i]].push_back(a[i]);
    }

    set<int> d;
    int delta = 0, minP = 0, maxP = 0;

    // dbg("s");
    // for (auto v : l)
    //     cout << v << " ";
    // cout nl;
    // for (auto v : r)
    //     cout << v << " ";
    // cout nl;
    // dbg("e");

    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'L')
        {
            delta--;
        }
        else
        {
            delta++;
        }

        if (delta > maxP)
        {
            for (auto v : pR[delta])
            {
                // dbg(delta);
                // dbg(v);
                d.insert(v);
            }
            maxP = delta;
        }
        else if (delta < minP)
        {
            for (auto v : pL[abs(delta)])
            {
                // dbg(delta);
                // dbg(v);
                d.insert(v);
            }
            minP = delta;
        }
        cout << n - d.size() << " ";
    }
    cout nl;
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        s();
    return 0;
}