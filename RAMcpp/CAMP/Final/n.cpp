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

void solve()
{
    int n, m;
    cin >> n >> m;

    set<int> all;

    for (int i = 1; i <= n; i++)
    {
        all.insert(i);
    }

    vector<unordered_set<int>> disp(n);

    vector<int> ans;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        disp[a-1].insert(b);
    }

    // Test preprocessing
    // cout << "-1\n";
    // return;
    for (int i = 0; i < n; i++)
    {
        auto f = all.begin();
        bool found = false;
        while (f != all.end())
        {
            if (!disp[i].count(*f))
            {
                ans.push_back(*f);
                all.erase(*f);
                found = true;
                break;
            }
            f++;
        }
        if (!found)
        {
            cout << "-1\n";
            return;
        }
    }

    for (auto x : ans)
    {
        cout << x << " ";
    }

    cout << "\n";
}

int main()
{
    _

        int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}