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

void s()
{
    int k, n;
    cin >> k >> n;
    vector<vector<int>> p(n);

    for (int j = 0; j < k; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int next;
            cin >> next;
            next--;
            p[next].push_back(i);
        }
    }

    // for (auto x : p)
    // {
    //     for (auto y : x)
    //         cout << y << ' ';
    //     cout << "\n";
    // }
    // cout nl;
    int consistent = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool lo = true, hi = true;
            for (int l = 0; l < k; l++)
            {
                if (p[i][l] > p[j][l])
                    lo = false;

                if (p[i][l] < p[j][l])
                    hi = false;
            }
            if (lo || hi)
            {
                consistent++;
                // cout << "i " << i << ", j " << j << '\n';
            }
        }
    }

    cout << consistent << "\n";
}

int main()
{
    _
        freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}