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

int distP(pair<int, int> p1, pair<int, int> p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void dP(pair<int, int> p1)
{
    cout << "(" << p1.first << ", " << p1.second << ")";
}

void s()
{
    int n;
    cin >> n;

    vector<pair<int, int>> no, ea;
    map<pair<int, int>, int> origin;
    vector<int> ans(n, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        char c;
        int x, y;
        cin >> c >> x >> y;
        origin[{x, y}] = i;
        if (c == 'E')
        {
            ea.push_back({x, y});
        }
        else
        {
            no.push_back({x, y});
        }
    }

    sort(all(no));

    for (int i = 0; i < no.size(); i++)
    {
        int maxDist = INT_MAX;

        for (int j = 0; j < ea.size(); j++)
        {
            if (no[i].first < ea[j].first || no[i].second > ea[j].second)
                continue;
            pair<int, int> intersection = {no[i].first, ea[j].second};

            if (distP(intersection, ea[j]) < distP(intersection, no[i]) && ans[origin[ea[j]]] >= distP(intersection, ea[j]))
            {
                maxDist = min(maxDist, distP(intersection, no[i]));
            }
        }
        ans[origin[no[i]]] = maxDist;

        for (int j = 0; j < ea.size(); j++)
        {
            if (no[i].first < ea[j].first || no[i].second > ea[j].second)
                continue;
            pair<int, int> intersection = {no[i].first, ea[j].second};

            if (maxDist >= distP(intersection, no[i]) && distP(intersection, ea[j]) > distP(intersection, no[i]))
            {
                ans[origin[ea[j]]] = min(ans[origin[ea[j]]], distP(intersection, ea[j]));
            }
        }

        // for (auto a : ans)
        //     cout << a << " ";
        // cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == INT_MAX)
            cout << "Infinity\n";
        else
            cout << ans[i] << "\n";
    }
}

int main()
{
    _

        int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}