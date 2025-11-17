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

int take(int n, vector<int> &a, vector<int> &b)
{
    int ans = 0;
    int l = max((int)b.size() - n, 0);

    for (int i = 0; i < a.size() && l < b.size(); i++)
    {
        if (a[i] <= b[l])
        {
            ans += b[l] - a[i];
            l++;
        }
    }
    return ans;
}

int onlyA(vector<int> &a, vector<int> &b)
{
    int t = 0;

    for (int i = 0; i < a.size(); i++)
    {
        t = max(t, take(i + 1, a, b));
    }
    return t;
}

int allO(vector<int> a, vector<int> a2, vector<int> b)
{
    int l = 0, r = 0;
    while (l < a2.size() && r < b.size())
    {
        if (b[r] > a2[l])
        {
            b[r] = 0;
            l++;
        }
        r++;
    }

    if (l != a2.size())
        return 0;

    sort(all(b));

    l = 0, r = 0;

    int ans = 0;

    while (l < a.size() && r < b.size())
    {
        if (b[r] >= a[l])
        {
            ans += b[r] - a[l];
            l++;
            b[r] = 0;
        }
        r++;
    }

    if (l != a.size())
        return 0;

    for (auto v : b)
        ans += v;

    return ans;
}

void s()
{
    int n, m;
    cin >> n >> m;
    vector<int> a, a2, b;

    for (int i = 0; i < n; i++)
    {
        string s;
        int v;
        cin >> s >> v;
        if (s == "ATK")
            a.push_back(v);
        else
            a2.push_back(v);
    }
    for (int i = 0; i < m; i++)
    {
        int v;
        cin >> v;
        b.push_back(v);
    }
    sort(all(a));
    sort(all(a2));
    sort(all(b));

    int ans = onlyA(a, b);

    ans = max(ans, allO(a, a2, b));

    cout << ans << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}