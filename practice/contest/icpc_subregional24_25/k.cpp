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

void getSum(int target, vector<int> &a, vector<bool> &s1)
{

    vector<vector<vector<int>>> dp(a.size(), vector<vector<int>>(target + 1));

    dp[0][0] = {-1};

    if (a[0] <= target)
    {
        dp[0][a[0]] = {0};
    }

    for (int i = 1; i < a.size(); i++)
    {
        dp[i] = dp[i - 1];
        for (int j = 0; j <= target; j++)
        {
            if (j - a[i] >= 0 && dp[i - 1][j - a[i]].size() > 0)
            {
                dp[i][j] = dp[i - 1][j - a[i]];
                dp[i][j].push_back(i);
            }
        }
    }

    vector<bool> used(a.size());
    if (!dp.back().empty())
    {
        for (auto ind : dp.back().back())
        {
            if (ind == -1)
                continue;
            used[ind] = true;
        }
    }
    s1 = used;
}

void s()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for (auto &v : a)
    {
        cin >> v;
        s += v;
    }

    if (s % 2 == 1)
    {
        cout << "-1\n";
        return;
    }
    vector<bool> used(n);
    getSum(s / 2, a, used);

    vector<int> s1, s2;

    for (int i = 0; i < n; i++)
    {
        if (used[i])
        {
            s1.push_back(a[i]);
        }
        else
        {
            s2.push_back(a[i]);
        }
    }

    // dbg("s1");
    // for (auto v : s1)
    // {
    //     cout << v << " ";
    // }
    // cout nl;
    // dbg("s2");
    // for (auto v : s2)
    // {
    //     cout << v << " ";
    // }
    // cout nl;

    if (s1.size() == 0 || s2.size() == 0)
    {
        cout << "-1\n";
        return;
    }

    vector<int> ans;
    int p1 = 0;
    int p2 = 0;
    int sum = 0;

    while (p1 < s1.size() || p2 < s2.size())
    {
        if (p1 < s1.size() && p2 < s2.size())
        {
            if (sum < 0)
            {
                ans.push_back(s2[p2]);
                sum += s2[p2];
                p2++;
            }
            else
            {
                ans.push_back(s1[p1]);
                sum -= s1[p1];
                p1++;
            }
        }
        else if (p1 < s1.size())
        {
            ans.push_back(s1[p1]);
            p1++;
        }
        else
        {
            ans.push_back(s2[p2]);
            p2++;
        }
    }

    for (auto v : ans)
    {
        cout << v << " ";
    }
    cout nl;
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