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
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(n);

    for (auto &v : a)
        cin >> v;
    for (auto &v : b)
        cin >> v;

    int total = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                unordered_set<string> pos;

                for (int l = 0; l < n; l++)
                {
                    string add = "";
                    add += a[l][i];
                    add += a[l][j];
                    add += a[l][k];
                    pos.insert(add);
                }
                bool feasible = true;
                for (int l = 0; l < n; l++)
                {
                    string add = "";
                    add += b[l][i];
                    add += b[l][j];
                    add += b[l][k];
                    if (pos.count(add))
                    {
                        feasible = false;
                        break;
                    }
                }
                if (feasible)
                    total++;
            }
        }
    }

    cout << total << "\n";
}

int main()
{
    _

        int t;
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}