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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    c -= a, d -= b;

    if (a > b)
        swap(a, b);

    if (c > d)
        swap(c, d);

    bool done = false;

    while (a > 0 || b > 0)
    {
        if (a >= b)
        {
            break;
            return;
        }
        else
        {
            if (done)
            {
                cout << "NO\n";
                return;
            }
            b -= 2;
            if (a > 0)
            {
                a--;
            }
            else
            {
                done = true;
            }
        }
    }
    done = false;
    while (c > 0 || d > 0)
    {
        if (c >= d)
        {
            cout << "YES\n";
            return;
        }
        else
        {
            if (done)
            {
                cout << "NO\n";
                return;
            }
            d -= 2;
            if (c > 0)
            {
                c--;
            }
            else
            {
                done = true;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    _

        int t;
    cin >> t;
    // t = 1;
    while (t--)
        s();
    return 0;
}