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

    int start = -1;
    int maxL = -1;

    vector<vector<int>> lengths(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << "? " << i << " " << n << " ";
        for (int j = 1; j <= n; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
        cout.flush();
        int l;
        cin >> l;
        lengths[l].push_back(i);

        if (l == -1)
        {
            std::exit(EXIT_FAILURE);
        }

        if (l > maxL)
        {
            maxL = l;
            start = i;
        }
    }
    vector<int> path(maxL);
    unordered_set<int> ignore(lengths[maxL].begin(), lengths[maxL].end());
    ignore.erase(start);

    path[0] = start;
    for (int i = maxL - 1; i >= 1; i--)
    {
        ignore.insert(lengths[i].begin(), lengths[i].end());

        for (int j = 0; j < lengths[i].size(); j++)
        {
            cout << "? " << start << " " << n - (int)ignore.size() + 1 << " ";
            for (int k = 1; k <= n; k++)
            {
                if (k == lengths[i][j] || !ignore.count(k))
                {
                    cout << k << " ";
                }
            }
            cout << "\n";
            cout.flush();
            int l;
            cin >> l;
            if (l == -1)
            {
                std::exit(EXIT_FAILURE);
            }

            if (l == maxL)
            {
                path[maxL - i] = lengths[i][j];
                break;
            }
        }
        ignore.erase(path[maxL - i]);
    }

    cout << "! " << maxL << " ";

    for (auto p : path)
    {
        cout << p << " ";
    }

    cout << "\n";
    cout.flush();
}

int main()
{
    // _

    int t;
    cin >> t;
    // t = 1;
    while (t--)
        s();
    return 0;
}