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

// editorial approach
void editorial()
{
    string s, t;
    cin >> s >> t;
    string censored = "";
    for (int i = 0; i < s.size(); i++)
    {
        censored += s[i];

        if (censored.size() >= t.size())
        {
            bool contains = true;
            int offset = censored.size() - (int)t.size();
            for (int k = 0; k < t.size(); k++)
            {
                if (censored[offset + k] != t[k])
                {
                    contains = false;
                    break;
                }
            }
            if (contains)
            {
                censored = censored.substr(0, censored.size() - (int)t.size());
            }
        }
    }

    cout << censored << "\n";
}

// Output exceeded?
void s()
{
    string s, t;
    cin >> s >> t;

    vector<int> l(s.size());
    vector<pair<char, int>> w;
    int p = 0;
    int tp = 0;
    while (p < s.size())
    {
        if (t[tp] == s[p])
        {
            tp++;
            w.push_back({s[p], tp});

            if (tp == t.size())
            {
                while (tp--)
                    w.pop_back();

                if (!w.empty())
                {
                    tp = w.back().second;
                }
            }
        }
        else
        {
            tp = 0;
            if (t[tp] == s[p])
            {
                tp++;
                w.push_back({s[p], tp});

                if (tp == t.size())
                {
                    while (tp--)
                        w.pop_back();

                    if (!w.empty())
                    {
                        tp = w.back().second;
                    }
                }
            }
            else
            {
                w.push_back({s[p], tp});
            }
        }
        p++;
    }

    for (auto it : w)
    {
        cout << it.first;
    }
    cout << "\n";
}

int main()
{
    _

        int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    // editorial();
    return 0;
}