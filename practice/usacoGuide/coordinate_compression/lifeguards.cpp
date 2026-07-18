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
#define MAXN 10
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};

void s()
{
    int n;
    cin >> n;
    vector<vector<int>> a;
    vector<pair<int, int>> t(n);
    vector<pair<int, int>> d(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i - 1].first >> t[i - 1].second;
        d[i - 1] = {0, i - 1};
        a.push_back({t[i - 1].first, i});
        a.push_back({t[i - 1].second, -i});
    }

    sort(all(a));

    set<int> cur;

    int prev = 0;
    int total = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (cur.size() == 1)
        {
            d[(*cur.begin()) - 1].first += a[i][0] - prev;
        }

        if (cur.size() > 0)
        {
            total += a[i][0] - prev;
        }

        if (a[i][1] > 0)
        {
            cur.insert(a[i][1]);
        }
        else
        {
            cur.erase(abs(a[i][1]));
        }
        prev = a[i][0];
    }

    // for (auto v : d)
    //     cout << "(" << v.first << ", " << v.second << ") ";

    // cout nl;

    sort(all(d));

    cout << total - d[0].first << "\n";
}

int main()
{
    _;

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}