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
#define nl << "\n"

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

vector<int> sub(vector<int> &a, vector<int> &b)
{
    vector<int> res(a.size());
    for (int i = 0; i < 26; i++)
    {
        res[i] = a[i] - b[i];
    }
    return res;
}

// Editorial

void s()
{
    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<vector<int>> pref(s.size() + 1);
    pref[0] = vector<int>(26);

    for (int i = 1; i <= s.size(); i++)
    {
        pref[i] = pref[i - 1];
        pref[i][s[i - 1] - 'a']++;
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        if (b - a < 1 || s[a - 1] != s[b - 1])
        {
            cout << "Yes\n";
            continue;
        }

        vector<int> res = sub(pref[b], pref[a - 1]);
        int c = 0;
        for (auto r : res)
        {
            if (r > 0)
                c++;
        }

        if (c > 2)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}