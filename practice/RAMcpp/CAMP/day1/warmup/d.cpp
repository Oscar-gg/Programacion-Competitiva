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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

int main()
{
    _

        int a,
        b, c, d;
    cin >> a >> b >> c >> d;
    bool x = true;


    if (c <= a){
        cout << a << "\n";
        return 0;
    }

    while (c >= a)
    {

        if (a >= c)
        {
            cout << a << endl;
            return 0;
        }

        a += b;
        if (a >= c)
        {
            cout << c << endl;
            return 0;
        }

        c -= d;

        if (c <= a)
        {
            cout << a << endl;
            return 0;
        }

        // if (x)
        //     a += b;
        // else
        //     c -= d;

        // x = !x;

        // cout << a << " " << c << endl;
    }

    return 0;
}