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
#define nl << "\n"

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

void s()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> m(n);
    vector<int> cur(1 << n);

    for (int i = 0; i < (1 << n); i++)
    {
        cin >> cur[i];
    }
    m[0] = cur;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m[i - 1].size(); j += 2)
        {
            m[i].push_back(m[i - 1][j] ^ m[i - 1][j + 1]);
        }
    }
    while (q--)
    {
        vector<bool> w;

        int b, c;
        cin >> b >> c;
        b--;
        ll bellow = 0;

        for (int i = 0; i < n; i++)
        {
            int ind = b >> i;
            if (ind % 2 == 0)
            {
                if (c >= m[i][ind + 1])
                {
                    bellow += 1 << i;
                }
                c ^= m[i][ind + 1];
            }
            else
            {
                if (c > m[i][ind - 1])
                {
                    bellow += 1 << i;
                }
                c ^= m[i][ind - 1];
            }
        }

        cout << (1 << n) - 1 - bellow << "\n";
    }
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        s();
    return 0;
}