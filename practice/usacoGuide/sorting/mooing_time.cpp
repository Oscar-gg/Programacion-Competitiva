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
    int n, f;
    cin >> n >> f;

    string s;
    cin >> s;

    map<string, int> c0, c02, c03;
    set<string> c1, c12, c13;

    for (int i = 0; i < n - 2; i++)
    {
        if (s[i + 1] == s[i + 2])
        {
            if (s[i + 1] != s[i])
                c0[s.substr(i, 3)]++;

            string temp = s.substr(i, 3);

            for (int j = 0; j < 26; j++)
            {
                char c = 'a' + j;
                temp[0] = c;
                if ((i > 0 && temp == s.substr(i - 1, 3)) || c == s[i] || c == s[i + 1] || (i > 1 && temp == s.substr(i - 2, 3)))
                {
                    continue;
                }
                c1.insert(temp);
            }
        }

        if (s[i] != s[i + 2] && s[i + 2] != s[i + 1])
        {
            string t = s.substr(i, 3);
            t[1] = s[i + 2];
            if ((i > 0 && s.substr(i - 1, 3) != t) && (i + 1 < n && s.substr(i + 1, 3) != t))
                c12.insert(t);
        }
        if (s[i] != s[i + 1] && s[i + 1] != s[i + 2])
        {
            string t = s.substr(i, 3);
            t[2] = s[i + 1];
            if ((i > 0 && s.substr(i - 1, 3) != t) && (i + 1 < n && s.substr(i + 1, 3) != t))
                c13.insert(t);
        }
    }

    c02 = c0;
    c03 = c0;

    for (auto v : c1)
    {
        c0[v]++;
    }

    for (auto v : c12)
    {
        c02[v]++;
    }
    for (auto v : c13)
    {
        c03[v]++;
    }
    set<string> sans;
    for (auto x : c0)
    {
        if (x.second >= f)
        {
            sans.insert(x.first);
        }
    }

    for (auto x : c02)
    {
        // cout << x.first << " " << x.second << "\n";

        if (x.second >= f)
        {
            sans.insert(x.first);
        }
    }

    for (auto x : c03)
    {
        // cout << x.first << " " << x.second << "\n";

        if (x.second >= f)
        {
            sans.insert(x.first);
        }
    }
    vector<string> ans(sans.begin(), sans.end());

    cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
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