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
    vector<vector<pair<char, int>>> changes(100);

    for (int i = 0; i < n; i++)
    {
        int d;
        string s;
        char c;
        int dx;
        cin >> d >> s >> c >> dx;
        d--;

        if (c == '-')
            dx *= -1;
        changes[d].push_back({s[0], dx});
    }

    int m = 7, e = 7, b = 7;
    int ans = 0;
    string st = "meb";

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < changes[i].size(); j++)
        {
            if (changes[i][j].first == 'M')
            {
                m += changes[i][j].second;
            }
            else if (changes[i][j].first == 'E')
            {
                e += changes[i][j].second;
            }
            else
            {
                b += changes[i][j].second;
            }
        }
        int maxQ = max({m, e, b});
        string nst = "";
        if (m == maxQ)
            nst += 'm';
        if (e == maxQ)
            nst += 'e';
        if (b == maxQ)
            nst += 'b';
        sort(nst.begin(), nst.end());
        sort(st.begin(), st.end());

        if (nst != st)
            ans++;
        st = nst;
    }

    cout << ans << "\n";
}

int main()
{
    _ int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}