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

void sides(vector<string> &p1, int &ilsh, int &irsh, int &jbsh, int &jtsh)
{
    int n = p1.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p1[i][j] == '#')
            {
                ilsh = min(ilsh, i);
                irsh = max(irsh, i);
                jbsh = min(jbsh, j);
                jtsh = max(jtsh, j);
            }
        }
    }
    irsh = n - 1 - irsh;
    ilsh *= -1;

    jbsh *= -1;
    jtsh = n - 1 - jtsh;
}

bool valid(int i, int n)
{
    return i >= 0 && i < n;
}

bool sEqu(vector<string> &o, vector<string> &p1, vector<string> &p2, int ii, int ij, int ik, int il)
{
    int n = o.size();
    vector<vector<char>> mix(n, vector<char>(n, '.'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ni = i - ii, nj = j - ij;

            if (valid(ni, n) && valid(nj, n))
            {
                if (mix[i][j] == '#' && p1[ni][nj] == '#')
                    return false;
                else if (p1[ni][nj] == '#')
                {
                    mix[i][j] = '#';
                }
            }

            int ni2 = i - ik, nj2 = j - il;
            if (valid(ni2, n) && valid(nj2, n))
            {
                if (mix[i][j] == '#' && p2[ni2][nj2] == '#')
                    return false;
                else if (p2[ni2][nj2] == '#')
                    mix[i][j] = '#';
            }
        }
    }
    // dbg("p1");
    // for (auto x : p1)
    //     cout << x << "\n";
    // cout nl;
    // dbg("p2");
    // for (auto x : p2)
    //     cout << x << "\n";
    // cout nl;
    // dbg(ii);
    // dbg(ik);
    // dbg(ik);
    // dbg(il);
    // dbg("mix");
    // for (auto x : mix)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y;
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < n; i++)
    {
        string r(mix[i].begin(), mix[i].end());
        if (o[i] != r)
            return false;
    }

    return true;
}

bool merge(vector<string> &o, vector<string> &p1, vector<string> &p2)
{
    int n = p1.size();
    int ilsh = INT_MAX, irsh = INT_MIN;
    int jbsh = INT_MAX, jtsh = INT_MIN;

    int ilsh2 = INT_MAX, irsh2 = INT_MIN;
    int jbsh2 = INT_MAX, jtsh2 = INT_MIN;

    sides(p1, ilsh, irsh, jbsh, jtsh);
    sides(p2, ilsh2, irsh2, jbsh2, jtsh2);

    for (int i = ilsh; i <= irsh; i++)
    {
        for (int j = jbsh; j <= jtsh; j++)
        {
            for (int k = ilsh2; k <= irsh2; k++)
            {
                for (int l = jbsh2; l <= jtsh2; l++)
                {
                    if (sEqu(o, p1, p2, i, j, k, l))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

void s()
{
    int n, k;
    cin >> n >> k;
    vector<string> o(n);
    for (int i = 0; i < n; i++)
        cin >> o[i];
    vector<vector<string>> p(k);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string s;
            cin >> s;
            p[i].push_back(s);
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            // dbg(i);
            // dbg(j);
            if (merge(o, p[i], p[j]))
            {
                cout << i + 1 << " " << j + 1 << "\n";
                return;
            }
        }
    }
}

int main()
{
    _;

    // freopen("bcs.in", "r", stdin);
    // freopen("bcs.out", "w", stdout);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}