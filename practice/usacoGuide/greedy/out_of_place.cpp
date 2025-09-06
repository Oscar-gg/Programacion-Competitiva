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
    vector<int> a(n), cp;
    for (auto &v : a)
        cin >> v;

    cp = a;
    int swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            int swIndex = i + 1;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == a[i + 1])
                {
                    swIndex = j;
                }
                else
                {
                    break;
                }
            }
            swap(a[i], a[swIndex]);
            swaps++;
            i = swIndex - 1;
        }
    }

    if (is_sorted(all(a)))
    {
        cout << swaps << "\n";
        return;
    }
    swaps = 0;
    a = cp;

    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] < a[i - 1])
        {
            int swIndex = i - 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[j] == a[i - 1])
                {
                    swIndex = j;
                }
                else
                {
                    break;
                }
            }
            swap(a[i], a[swIndex]);
            swaps++;
            i = swIndex + 1;
        }
    }
    // dbg("a");

    cout << swaps << "\n";
}

int main()
{
    _;

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}