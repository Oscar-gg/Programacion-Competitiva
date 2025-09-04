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

void place(int index, vector<vector<int>> &b, int &total)
{
    if (index == b.size())
    {
        total++;
        return;
    }

    for (int i = 0; i < b[index].size(); i++)
    {

        if (b[index][i] == 0)
        {
            b[index][i] = 8;
            for (int r = index + 1; r < 8; r++)
            {
                b[r][i]++;
            }
            int c1 = i, c2 = i;
            for (int r = index + 1; r < 8; r++)
            {
                c1--;
                c2++;
                if (c1 >= 0)
                {
                    b[r][c1]++;
                }
                if (c2 < 8)
                {
                    b[r][c2]++;
                }
            }

            place(index + 1, b, total);

            for (int r = index + 1; r < 8; r++)
            {
                b[r][i]--;
            }
            c1 = i, c2 = i;
            for (int r = index + 1; r < 8; r++)
            {
                c1--;
                c2++;
                if (c1 >= 0)
                {
                    b[r][c1]--;
                }
                if (c2 < 8)
                {
                    b[r][c2]--;
                }
            }
            b[index][i] = 0;
        }
    }
}

void s()
{
    vector<vector<int>> b(8, vector<int>(8));

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
                b[i][j] = 1;
        }
    }

    int total = 0;
    place(0, b, total);
    cout << total << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}