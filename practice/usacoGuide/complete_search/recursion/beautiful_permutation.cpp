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

bool valid(vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (abs(a[i] - a[i + 1]) < 2)
            return false;
    }
    return true;
}

void s()
{
    int n;
    cin >> n;

    if (n <= 4)
    {

        if (n == 1)
        {
            cout << 1 << '\n';
        }
        else if (n == 2 || n == 3)
        {
            cout << "NO SOLUTION\n";
        }
        else
        {
            cout << "2 4 1 3\n";
        }
        return;
    }

    vector<int> start = {1, 3, 5, 2, 4};
    vector<int> a;
    unordered_set<int> selected;

    for (int i = 0; i < n - 5; i++)
    {
        if (i < 5)
        {
            a.push_back(start[i]);
            selected.insert(start[i]);
        }
        else
        {
            int v = a[i - 5] + 5;
            selected.insert(v);
            a.push_back(v);
        }
    }

    vector<int> permut;
    for (int i = 1; i <= n; i++)
    {
        if (!selected.count(i))
            permut.push_back(i);
    }

    do
    {
        if (valid(permut))
        {
            if (!a.empty())
            {
                if (abs(a.back() - permut.front()) > 1)
                    break;
            }
            else
            {
                break;
            }
        }
    } while (next_permutation(all(permut)));

    for (auto v : permut)
        a.push_back(v);

    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << "\n";
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