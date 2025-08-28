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
    vector<pair<string, string>> w(n);

    for (int i = 0; i < n; i++)
    {
        cin >> w[i].first >> w[i].second;
    }

    vector<int> counts(26);

    for (int i = 0; i < w.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int c1 = 0;
            for (int k = 0; k < w[i].first.size(); k++)
            {
                if (w[i].first[k] == 'a' + j)
                    c1++;
            }
            int c2 = 0;
            for (int k = 0; k < w[i].second.size(); k++)
            {
                if (w[i].second[k] == 'a' + j)
                    c2++;
            }
            counts[j] += max(c1, c2);
        }
    }

    for (int i = 0; i < 26; i++)
    {
        cout << counts[i] << "\n";
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