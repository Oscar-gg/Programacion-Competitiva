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

struct Pick
{
    int con;
    int t1;
    int t2;
    int comW;
    Pick()
    {
        con = 0, t1 = 0, t2 = 0, comW = 0;
    }
};

string getLast(string key, unordered_map<string, vector<string>> &umap)
{
    string ans = umap[key].back();
    umap[key].pop_back();
    return ans;
}

void s()
{
    int n, c, p;
    cin >> n >> c >> p;
    unordered_map<string, vector<string>> umap;
    unordered_map<string, int> types;

    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        umap[s2].push_back(s1);
        types[s2]++;
    }
    int max_ = 0;
    Pick pAns;

    for (int type_1 = 0; type_1 <= types["intransitive-verb"]; type_1++)
    {
        int noun_cnt = types["noun"], conj_cnt = types["conjunction"];
        int period = p;
        int wc = 0;

        wc += type_1 * 2;
        noun_cnt -= type_1;

        if (noun_cnt < 0)
            continue;

        int type_2 = min({noun_cnt / 2,
                          types["transitive-verb"],
                          min(conj_cnt, period) * 2 + max(0, period - conj_cnt)});
        wc += type_2 * 3;
        noun_cnt -= type_2 * 2;

        int total = type_2 + type_1;
        int connections = total - 1;
        int comb = min((connections + 1) / 2, conj_cnt);
        wc += comb;
        period -= total - comb;
        if (period < 0)
            continue;

        int comW = 0;

        if (type_2 > 0)
        {
            comW = min({noun_cnt, c});
        }

        wc += comW;

        if (wc > max_)
        {
            max_ = wc;
            Pick pi;
            pi.con = comb;
            pi.comW = comW;
            pi.t1 = type_1;
            pi.t2 = type_2;
            pAns = pi;
        }
    }

    cout << max_ << "\n";

    string ans = "";

    // dbg(pAns.t1);
    // dbg(pAns.t2);
    // dbg(pAns.comW);
    // dbg(pAns.con);

    bool prevConjunction = false;

    while (pAns.t1-- > 0)
    {
        // dbg(ans);
        if (ans.size() > 0)
        {
            ans += " ";
        }
        ans += getLast("noun", umap) + " ";
        ans += getLast("intransitive-verb", umap);
        if (pAns.con > 0 && !prevConjunction)
        {
            prevConjunction = true;
            pAns.con--;
            ans += " " + getLast("conjunction", umap);
        }
        else
        {
            prevConjunction = false;
            ans += ".";
        }
    }
    while (pAns.t2-- > 0)
    {
        // dbg(ans);
        if (ans.size() > 0)
        {
            ans += " ";
        }
        ans += getLast("noun", umap) + " ";
        ans += getLast("transitive-verb", umap) + " ";
        ans += getLast("noun", umap);

        while (pAns.comW-- > 0)
        {
            ans += ", " + getLast("noun", umap);
        }

        if (pAns.con > 0 && !prevConjunction)
        {
            pAns.con--;
            ans += " " + getLast("conjunction", umap);
        }
        else
        {
            prevConjunction = false;
            ans += ".";
        }
    }
    cout << ans << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        s();
    }
    return 0;
}