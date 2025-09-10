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

int nextP(int p, int a1, int a2, int b1, int b2)
{
    if (p >= a1 && p <= a2)
    {
        p = a2 + a1 - p;
    }

    if (p >= b1 && p <= b2)
    {
        p = b2 + b1 - p;
    }
    return p;
}

void s()
{
    int n, k;
    cin >> n >> k;
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    a1--;
    a2--;
    b1--;
    b2--;

    vector<vector<int>> a(n);

    for (int i = 0; i < n; i++)
    {
        unordered_set<int> p;
        int cur = i;
        p.insert(cur);
        a[i].push_back(cur);

        while (!p.count(nextP(cur, a1, a2, b1, b2)))
        {
            cur = nextP(cur, a1, a2, b1, b2);
            p.insert(cur);
            a[i].push_back(cur);
        }
    }

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int s = a[i].size();
        int final_pos = a[i][k % s];
        ans[final_pos] = i + 1;
    }

    for (auto v : ans)
    {
        cout << v << "\n";
    }
}

int main()
{
    _;

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}