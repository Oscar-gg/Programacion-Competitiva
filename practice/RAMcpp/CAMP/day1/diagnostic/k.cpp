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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

int main()
{
    _

        int n,
        m;
    cin >> n >> m;

    map<int, int> omap;
    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;
        omap[next]++;
    }

    for (int i = 0; i < m; i++)
    {
        int next;
        cin >> next;
        auto p = omap.lower_bound(next);
        if (p->first == next)
        {
            // cout << "if ";
            cout << next << "\n";
            omap[next]--;
            if (omap[next] == 0){
                omap.erase(omap.find(next));
            }
                
        }
        else
        {
            // cout << "el ";
            if (p == omap.begin())
            {
                cout << -1 << endl;
            }
            else
            {
                p--;
                cout << p->first << "\n";
                omap[p->first]--;
                if (omap[p->first] == 0)
                    omap.erase(p->first);
            }
        }
    }

    return 0;
}