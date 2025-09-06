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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v : a)
        cin >> v;

    if (a[0] == -1)
        a[0] = 0;

    if (a[0] != 0)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] != -1)
        {
            int its = a[i] - 1;
            int p = i - 1;
            bool pos = true;

            while (its >= 0)
            {
                if (p < 0 || (a[p] != -1 && a[p] != its))
                {
                    pos = false;
                    break;
                }
                else
                {
                    a[p] = its;
                    its--;
                    p--;
                }
            }

            if (!pos)
            {
                cout << "-1\n";
                return;
            }
        }
    }
    int min_ = 0;
    int max_ = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            max_++;
            min_++;
        }
        else if (a[i] == -1)
        {
            max_++;
        }
    }

    cout << min_ << " "
         << max_ << "\n";
}

int main()
{
    _;

    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}