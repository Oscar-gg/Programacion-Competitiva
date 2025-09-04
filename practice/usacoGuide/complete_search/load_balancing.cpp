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

int count(int x, int y, vector<pair<int, int>> &cow)
{

    bool debug = false;

    if (x == 6 && y == 19)
    {
        debug = true;
    }

    int a = 0, b = 0, c = 0, d = 0;

    unordered_map<string, vector<pair<int, int>>> cows;

    for (int i = 0; i < cow.size(); i++)
    {
        if (cow[i].first > x)
        {
            if (cow[i].second > y)
            {
                cows["1"].push_back(cow[i]);

                a++;
            }
            else
            {
                cows["2"].push_back(cow[i]);
                b++;
            }
        }
        else
        {
            if (cow[i].second > y)
            {
                cows["3"].push_back(cow[i]);
                c++;
            }
            else
            {
                cows["4"].push_back(cow[i]);
                d++;
            }
        }
    }

    if (debug)
    {
        for (auto x : cows)
        {
            cout << x.first << ": ";
            for (auto y : x.second)
            {
                cout << "(" << y.first << ", " << y.second << ") ";
            }
            cout << "\n";
        }
    }

    return max({a, b, c, d});
}

void s()
{
    int n, b;
    cin >> n;
    cin >> b;
    vector<pair<int, int>> c(n);
    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> c[i].first >> c[i].second;
        x[i] = c[i].first;
        y[i] = c[i].second;
    }
    int min_ = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int a = count(x[i] + 1, y[j] + 1, c);

            if (a < min_)
            {
                min_ = a;
                dbg(x[i]);
                dbg(y[j]);
            }
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