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

// After reading editorial
void s2()
{
    ll k, x;
    cin >> k >> x;
    ll s = 1ll << k;

    vector<int> operations;

    ll y = s * 2 - x;

    while (x != y)
    {
        if (x > y)
        {
            operations.push_back(2);
            x -= y;
            y *= 2;
        }
        else
        {
            y -= x;
            x *= 2;
            operations.push_back(1);
        }
    }

    cout << operations.size() << "\n";

    while (!operations.empty())
    {
        cout << operations.back() << " ";
        operations.pop_back();
    }

    cout nl;
}

int main()
{
    _;

    int t = 1;
    cin >> t;
    while (t--)
        s2();
    return 0;
}