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

void enclosing(pair<int, int> &p1, pair<int, int> &p2, vector<string> &m, char c)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            if (m[i][j] == c)
            {
                p1 = {min(p1.first, i), min(p1.second, j)};
                p2 = {max(p2.first, i), max(p2.second, j)};
            }
        }
    }
}

void s()
{
    int n;
    cin >> n;

    vector<string> m(n);
    unordered_set<char> p;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];

        for (auto c : m[i])
        {
            if (c != '0')
                p.insert(c);
        }
    }

    unordered_set<char> discard;

    for (auto c : p)
    {
        pair<int, int> p1 = {INT_MAX, INT_MAX}, p2 = {INT_MIN, INT_MIN};
        enclosing(p1, p2, m, c);
        for (int i = p1.first; i <= p2.first; i++)
        {
            for (int j = p1.second; j <= p2.second; j++)
            {
                if (m[i][j] != c)
                {
                    // dbg(m[i][j]);
                    // dbg(c);
                    discard.insert(m[i][j]);
                }
            }
        }
    }

    int st = 0;

    for (auto x : p)
    {
        if (!discard.count(x))
        {
            st++;
        }
    }

    cout << st << "\n";
}

int main()
{
    _;

    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}