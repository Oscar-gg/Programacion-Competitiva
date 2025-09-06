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

void s()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    vector<int> f;
    for (int i = 0; i < n; i += 2)
    {
        if (s[i] == 'G' && s[i + 1] == 'H')
        {
            if (f.empty() || f.back() != 1)
            {
                f.push_back(1);
            }
        }
        else if (s[i] == 'H' && s[i + 1] == 'G')
        {
            if (f.empty() || f.back() != 2)
            {
                f.push_back(2);
            }
        }
    }

    bool tog = false;
    int sw = 0;

    while (!f.empty())
    {
        if (tog && f.back() == 2)
        {
            tog = !tog;
            sw++;
        }
        else if (!tog && f.back() == 1)
        {
            sw++;
            tog = !tog;
        }
        f.pop_back();
    }

    cout << sw << "\n";
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