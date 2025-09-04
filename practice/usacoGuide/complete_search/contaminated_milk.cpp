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
    int n, m, d, s;
    cin >> n >> m >> d >> s;

    vector<vector<pair<int, int>>> pers(n);
    for (int i = 0; i < d; i++)
    {
        int p, m, t;
        cin >> p >> m >> t;
        p--;
        pers[p].push_back({m, t});
    }
    vector<int> sT(n, INT_MAX);

    for (int i = 0; i < s; i++)
    {
        int p, t;
        cin >> p >> t;
        p--;
        sT[p] = t;
    }

    for (int i = 0; i < n; i++)
    {
        int it = pers[i].size();
        int p = 0;
        while (it--)
        {
            if (pers[i][p].second >= sT[i])
            {
                swap(pers[i][p], pers[i].back());
                pers[i].pop_back();
            }
            else
            {
                p++;
            }
        }
    }

    vector<int> bad;

    for (int i = 1; i <= m; i++)
    {
        bool pos = true;
        for (int j = 0; j < n && pos; j++)
        {
            if (sT[j] != INT_MAX)
            {
                bool found = false;
                for (auto d : pers[j])
                {
                    if (d.first == i)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                    pos = false;
            }
        }
        if (pos)
        {
            bad.push_back(i);
        }
    }

    unordered_set<int> c;
    for (auto b : bad)
    {
        for (int i = 0; i < n; i++)
        {
            if (c.count(i))
                continue;
            for (int j = 0; j < pers[i].size(); j++)
            {
                if (pers[i][j].first == b)
                {
                    c.insert(i);
                    break;
                }
            }
        }
    }

    cout << c.size() << "\n";
}

int main()
{
    _

        int t;
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}