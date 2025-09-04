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
    unordered_map<int, vector<pair<int, int>>> hc;

    vector<int> x(n), y(n);
    int minY = INT_MAX, maxY = INT_MIN;
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        int xi, yi;
        cin >> xi >> yi;
        x[i] = xi;
        y[i] = yi;
        minY = min(minY, y[i]);
        maxY = max(maxY, y[i]);
        hc[x[i]].push_back({xi, yi});
    }

    y.push_back({minY - 2});
    y.push_back({maxY + 2});

    sort(x.begin(), x.end());

    int min_ = n;
    for (int i = 0; i < y.size(); i++)
    {
        int middleX = y[i] + 1;

        int a = 0, b = 0, c = 0, d = 0;

        for (int j = 0; j < n; j++)
        {
            if (y[j] > middleX)
                b++;
            else
                a++;
        }

        min_ = min(min_, max({a, b, c, d}));

        // int counts = 0;
        set<pair<int, int>> s;
        for (int j = 0; j < n; j++)
        {
            for (pair<int, int> p : hc[x[j]])
            {
                if (s.count(p))
                {
                    break;
                }
                s.insert(p);
                // counts++;
                if (p.second > middleX)
                {
                    b--;
                    d++;
                }
                else
                {
                    a--;
                    c++;
                }
            }

            min_ = min(min_, max({a, b, c, d}));
        }
    }

    cout << min_ << "\n";
}

int main()
{
    _

        int t;
    // cin >> t;
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    t = 1;
    while (t--)
        s();
    return 0;
}