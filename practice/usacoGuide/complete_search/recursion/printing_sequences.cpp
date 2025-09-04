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

// 6/13 cases

int patt_end(int index, int ca, int cb, int cc, int va, int vb, int vc, vector<int> &a)
{
    int lastV = index;
    int it = index;

    while (it < a.size())
    {
        vector<pair<int, int>> pat{{ca, va}, {cb, vb}, {cc, vc}};

        bool complete = true;

        for (auto p : pat)
        {
            if (!complete)
                break;
            for (int ig = 0; ig < p.first; ig++)
            {
                if (a[it] != p.second)
                {
                    complete = false;
                    break;
                }
                else
                {
                    it++;
                }
            }
        }
        if (complete)
        {
            lastV = it;
        }
        else
        {
            break;
        }
    }

    return lastV;
}

int last_index(int index, vector<int> &a)
{
    for (int i = index + 1; i < a.size(); i++)
    {
        if (a[i] != a[index])
            return i - 1;
    }
    return index;
}

bool path_end(int index, int changes, vector<int> &a);

bool patt_find(int index, int changes, vector<int> &a)
{

    int prev = a[index];
    int vA = a[index], vB = -1, vC = -1;
    int cA = 0, cB = 0, cC = 0;
    int pathC = 1;

    if (changes < 2)
        return false;

    for (int i = index; i < a.size(); i++)
    {
        if (a[i] != prev)
        {
            pathC++;

            int li = last_index(i, a);

            if (pathC == 2)
            {
                cA = (i - 1) - index + 1;
                vB = a[i];
                cB = li - i + 1;
                int pe = patt_end(index, cA, cB, 0, a[index], a[i], 0, a);

                if (pe == a.size() || path_end(pe, changes - 2, a))
                {
                    return true;
                }

                if (changes == 2)
                    return false;
            }
            else if (pathC == 3)
            {
                vC = a[i];
                cC = li - i + 1;
                int pe = patt_end(index, cA, cB, cC, a[index], vB, vC, a);

                return pe == a.size();
            }
        }
        if (pathC == 4)
            break;
        prev = a[i];
    }
    return false;
}

bool path_end(int index, int changes, vector<int> &a)
{
    if (changes == 0)
        return false;
    for (int i = index; i < a.size(); i++)
    {
        if (a[i] != a[index])
        {
            return path_end(i, changes - 1, a) || patt_find(i, changes - 1, a);
        }
    }
    return true;
}

void s()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &v : a)
        cin >> v;

    bool pos = path_end(0, k, a) || patt_find(0, k, a);

    if (pos)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t;
    cin >> t;
    // t s= 1;
    while (t--)
        s();
    return 0;
}