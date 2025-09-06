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

pair<int, int> range(int index, vector<int> &a)
{
    pair<int, int> r = {index, index};

    if (a.size() == 1)
        return r;

    vector<bool> v(a.size());

    while (true)
    {
        int diffL = INT_MAX;

        r = {min(r.first, index), max(r.second, index)};

        if (v[index])
            break;

        v[index] = true;

        if (index > 0)
        {
            diffL = a[index] - a[index - 1];
        }
        int diffR = INT_MAX;

        if (index < a.size() - 1)
        {
            diffR = a[index + 1] - a[index];
        }

        if (diffL <= diffR)
        {
            index--;
        }
        else
        {
            index++;
        }
    }

    return r;
}

void s()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v : a)
        cin >> v;

    sort(all(a));

    int c = 1;

    set<pair<int, int>> ranges;

    for (int i = 0; i < n; i++)
    {
        ranges.insert(range(i, a));
    }

    set<pair<int, int>> discard;

    for (auto r : ranges)
    {
        for (auto ri : ranges)
        {
            if (r == ri)
                continue;
            if (r.first <= ri.first && ri.second <= r.second)
            {
                discard.insert(ri);
            }
        }
    }

    cout << ranges.size() - discard.size() << "\n";
}

int main()
{
    _;

    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}