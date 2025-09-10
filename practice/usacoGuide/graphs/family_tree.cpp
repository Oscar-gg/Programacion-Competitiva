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

void dfs(string &current, int level, string &a, string &b, unordered_map<string, vector<string>> &desc, int &la, int &lb)
{

    if (current == a)
    {
        la = level;
    }
    else if (current == b)
    {
        lb = level;
    }

    if (desc[current].size() == 0)
        return;

    for (auto cow : desc[current])
    {
        dfs(cow, level + 1, a, b, desc, la, lb);
    }
}

void s()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    unordered_map<string, vector<string>> desc;
    unordered_map<string, string> parent;
    unordered_set<string> c;
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        c.insert(x);
        c.insert(y);
        desc[x].push_back(y);
        parent[y] = x;
    }

    unordered_set<string> visited;
    vector<string> uniqueCows(c.begin(), c.end());

    bool unrelated = false;
    int la = -1, lb = -1;

    for (int i = 0; i < uniqueCows.size(); i++)
    {
        string root = uniqueCows[i];
        while (parent.count(root))
        {
            root = parent[root];
        }
        if (visited.count(root))
            continue;

        visited.insert(root);

        dfs(root, 0, a, b, desc, la, lb);

        if (la == -1 && lb == -1)
            continue;

        if (la != -1 && lb == -1 || la == -1 && lb != -1)
        {
            unrelated = true;
            break;
        }
        else if (la < lb)
        {
            // a -> youngest
            swap(a, b);
            swap(la, lb);
            break;
        }
    }

    if (unrelated)
    {
        cout << "NOT RELATED\n";
        return;
    }

    bool close = false;
    bool mother = false;

    string explore = a;

    while (parent.count(explore) && !close)
    {
        explore = parent[explore];
        if (explore == b)
        {
            mother = true;
            break;
        }
        for (auto cow : desc[explore])
        {
            if (cow == b)
            {
                close = true;
                break;
            }
        }
    }

    if (mother)
    {
        lb++;
        string role = "mother";
        if (la > lb++)
            role = "grand-" + role;

        while (lb++ < la)
        {
            role = "great-" + role;
        }
        cout << b << " is the " << role << " of " << a << "\n";
    }
    else if (!close)
    {
        cout << "COUSINS\n";
    }
    else
    {
        string role = "";
        if (la == lb)
        {
            cout << "SIBLINGS\n";
            return;
        }
        else
        {
            while (++lb < la)
            {
                role += "great-";
            }
            role += "aunt";
        }

        cout << b << " is the " << role << " of " << a << "\n";
    }
}

int main()
{
    _;

    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}