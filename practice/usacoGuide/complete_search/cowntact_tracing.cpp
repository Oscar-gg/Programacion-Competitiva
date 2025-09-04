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

// editorial

bool possible(int i, int k, vector<pair<int, pair<int, int>>> &in, string &s)
{
    string inf(s.size(), '0');
    inf[i] = '1';
    vector<int> counts(s.size(), 0);

    for (int i = 0; i < in.size(); i++)
    {
        int v1 = in[i].second.first, v2 = in[i].second.second;
        if (inf[v1] == '1')
            counts[v1]++;
        if (inf[v2] == '1')
            counts[v2]++;
        if (inf[v1] == '1' && counts[v1] <= k)
            inf[v2] = '1';
        if (inf[v2] == '1' && counts[v2] <= k)
            inf[v1] = '1';
    }

    return inf == s;
}

void s()
{
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;

    vector<pair<int, pair<int, int>>> in(t);

    for (int i = 0; i < t; i++)
    {
        cin >> in[i].first >> in[i].second.first >> in[i].second.second;
        in[i].second.first--;
        in[i].second.second--;
    }
    sort(in.begin(), in.end());

    unordered_set<int> pat;
    int minK = INT_MAX, maxK = -1;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k <= t; k++)
        {
            if (possible(i, k, in, s))
            {
                pat.insert(i);
                minK = min(minK, k);
                maxK = max(maxK, k);
            }
        }
    }

    cout << pat.size() << " " << minK << " ";
    if (maxK == t)
    {
        cout << "Infinity\n";
    }
    else
    {
        cout << maxK << "\n";
    }
}

int main()
{
    _

        freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}