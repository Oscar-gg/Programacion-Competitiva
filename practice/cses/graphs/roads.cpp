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

int get_parent(int n, vector<int> &p)
{
    if (p[n] == n)
        return n;

    return p[n] = get_parent(p[n], p);
}

void join(int n, int n2, vector<int> &p, vector<int> &s)
{
    n = get_parent(n, p);
    n2 = get_parent(n2, p);

    if (s[n2] > s[n])
        swap(n2, n);

    s[n] += s[n2];
    p[n2] = n;
}

void s()
{
    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1, -1), size(n + 1, 1);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        join(a, b, parent, size);
    }

    // for (auto c : parent)
    // {
    //     cout << c << ' ';
    // }
    // cout nl;

    vector<pair<int, int>> p;
    for (int i = 2; i <= n; i++)
    {
        if (get_parent(i, parent) != get_parent(1, parent))
        {
            p.push_back({1, i});
            join(i, 1, parent, size);
        }
    }

    cout << p.size() nl;

    for (auto r : p)
        cout << r.first << " " << r.second << "\n";
}

int main()
{
    _

        int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}