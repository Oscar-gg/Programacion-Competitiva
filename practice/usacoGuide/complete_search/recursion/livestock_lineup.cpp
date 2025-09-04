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
    vector<string> c = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    unordered_map<string, vector<string>> cond;
    sort(all(c));

    for (int i = 0; i < n; i++)
    {
        // Buttercup must be milked beside Bella
        string n1, f, f2, f3, f4, n2;
        cin >> n1 >> f >> f2 >> f3 >> f4 >> n2;
        cond[n2].push_back(n1);
        cond[n1].push_back(n2);
    }

    do
    {
        bool pos = true;
        for (int i = 0; i < c.size(); i++)
        {
            bool next = true;
            for (auto n : cond[c[i]])
            {
                bool f = false;
                if (i > 0 && c[i - 1] == n)
                {
                    f = true;
                }
                if (i < c.size() - 1 && c[i + 1] == n)
                {
                    f = true;
                }
                if (!f)
                {
                    next = false;
                }
            }
            if (!next)
            {
                pos = false;
                break;
            }
        }
        if (pos)
            break;

    } while (next_permutation(all(c)));

    for (auto co : c)
    {
        cout << co << "\n";
    }
}

int main()
{
    _;

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}