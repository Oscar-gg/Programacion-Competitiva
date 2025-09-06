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

bool done(vector<string> &m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            if (m[i][j] == '1')
                return false;
        }
    }
    return true;
}

void s()
{
    int n;
    cin >> n;
    vector<string> m(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    int f = 0;
    while (!done(m))
    {
        f++;
        pair<int, int> p = {0, 0};
        bool found = false;
        for (int i = n - 1; i >= 0 && !found; i--)
        {
            for (int j = n - 1; j >= 0 && !found; j--)
            {
                if (m[i][j] == '1')
                {
                    p = {i, j};
                    found = true;
                }
            }
        }

        for (int i = 0; i <= p.first; i++)
        {
            for (int j = 0; j <= p.second; j++)
            {
                if (m[i][j] == '0')
                    m[i][j] = '1';
                else
                    m[i][j] = '0';
            }
        }
    }

    cout << f << "\n";
}

int main()
{
    _;

    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}