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

int ith(string &s, int ind)
{

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            if (ind == 0)
                return i;
            ind--;
        }
    }

    return -1;
}

void fz(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
            s[i] = '0';
    }
}

void s()
{
    string s, s2;
    cin >> s >> s2;

    int k = 0, k2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
            k++;
    }

    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] == '*')
            k2++;
    }

    int t = k + k2;

    for (int i = 0; i < (1 << t); i++)
    {
        string cs = s;
        string cs2 = s2;

        for (int j = 0; j < t; j++)
        {
            if (i & (1 << j))
            {
                // dbg(j);
                if (j >= k)
                {
                    // dbg(ith(cs2, j - k));
                    // dbg(cs2);
                    // dbg(j - k);
                    cs2[ith(s2, j - k)] = '1';
                }
                else
                {
                    // dbg(ith(cs, j));
                    // dbg(cs);
                    // cout << cs[3] << "\n";
                    cs[ith(s, j)] = '1';
                }
            }
        }
        // dbg(i)
        // dbg("before")
        //         cout
        //     << cs << endl;
        // cout << cs2 << endl;
        // dbg(cs);
        // dbg(cs2);

        fz(cs);
        fz(cs2);

        ll div = 0;
        ll num = 0;

        for (int i = 0; i < cs2.size(); i++)
        {
            div *= 2;

            if (cs2[i] == '1')
            {
                div++;
            }
        }

        for (int i = 0; i < cs.size(); i++)
        {
            num *= 2;
            num %= div;
            if (cs[i] == '1')
            {
                num++;
                num %= div;
            }
        }
        if (num % div == 0)
        {
            cout << cs << "\n";
            return;
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