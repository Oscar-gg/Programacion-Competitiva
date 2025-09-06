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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> o(m);
    vector<int> a(n, -1);

    unordered_map<int, int> umap;
    bool one = false;
    for (int i = 0; i < m; i++)
    {
        cin >> o[i];
        if (o[i] == 1)
            one = true;
    }

    for (int i = 0; i < k; i++)
    {
        int c, d;
        cin >> c >> d;
        d--;
        a[d] = c;
        umap[c] = d;
    }

    if (umap.count(1))
    {
        cout << umap[1] + 1 << "\n";
        return;
    }

    if (one)
    {
        int sI = 0;
        for (int i = 0; i < m; i++)
        {
            if (umap.count(o[i]))
            {
                sI = umap[o[i]];
                continue;
            }
            for (int j = sI; j < n; j++)
            {
                if (a[j] == -1)
                {
                    if (o[i] == 1)
                    {
                        cout << j + 1 << "\n";
                        return;
                    }
                    a[j] = o[i];
                    umap[o[i]] = j;
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            if (umap.count(o[i]))
                continue;
            // dbg(i);
            int last_pos = n - 1;
            int tar = m;

            for (int j = i + 1; j < m; j++)
            {
                if (umap.count(o[j]))
                {
                    last_pos = umap[o[j]] - 1;
                    tar = j;
                    break;
                }
            }
            int needed = tar - i - 1;

            for (int j = last_pos; j >= 0; j--)
            {
                if (a[j] == -1)
                {
                    if (needed == 0)
                    {
                        a[j] = o[i];
                        break;
                    }
                    needed--;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1)
            {
                cout << i + 1 << "\n";
                return;
            }
        }
    }
}

int main()
{
    _;

    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int t = 1;
    while (t--)
        s();
    return 0;
}