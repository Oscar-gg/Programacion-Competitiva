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

void dfs(unordered_set<string> &used, vector<bool> &v, vector<char> &cur, string &o)
{
    if (cur.size() == o.size())
    {
        string ne(cur.begin(), cur.end());
        used.insert(ne);
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (!v[i])
        {
            cur.push_back(o[i]);
            v[i] = true;
            dfs(used, v, cur, o);
            v[i] = false;
            cur.pop_back();
        }
    }
}

void s()
{
    string s;
    cin >> s;
    unordered_set<string> used;
    vector<bool> v(s.size());
    vector<char> cur;
    dfs(used, v, cur, s);
    vector<string> ans(used.begin(), used.end());
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";

    for (auto x : ans)
    {
        cout << x << "\n";
    }
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}