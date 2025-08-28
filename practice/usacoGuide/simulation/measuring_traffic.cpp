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

    vector<string> s(n);
    vector<int> l(n), h(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        cin >> l[i] >> h[i];
    }

    int lb = 0, ub = 1001;
    bool nf = true;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == "off")
        {
            lb += l[i];
            ub += h[i];
        }
        else if (s[i] == "on")
        {
            lb -= h[i];
            lb = max(lb, 0);
            ub -= l[i];
        }
        else
        {

            lb = max(lb, l[i]);
            ub = min(ub, h[i]);
        }
    }

    cout << lb << " " << ub << "\n";

    lb = 0, ub = 1001;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == "off")
        {
            lb -= h[i];
            lb = max(lb, 0);
            ub -= l[i];
        }
        else if (s[i] == "on")
        {
            lb += l[i];
            ub += h[i];
        }
        else
        {
            lb = max(lb, l[i]);
            ub = min(ub, h[i]);
        }
    }

    cout << lb << " " << ub << "\n";
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