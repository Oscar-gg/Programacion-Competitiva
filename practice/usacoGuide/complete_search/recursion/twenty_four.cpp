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

// Editorial

int operation(int op, int num1, int num2)
{

    switch (op)
    {

    case 0:
        return num1 + num2;
    case 1:
        return num1 - num2;
    case 2:
        return num1 * num2;
    case 3:
        if (num2 == 0 || num1 % num2 != 0)
            return INT_MAX;
        return num1 / num2;
    }
    return INT_MAX;
}

void s()
{
    vector<int> a(4);
    for (auto &v : a)
        cin >> v;

    sort(a.begin(), a.end());

    int max_ = 0;

    do
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {

                    // (())))
                    int res = operation(i, a[0], a[1]);
                    if (res != INT_MAX)
                    {
                        res = operation(j, res, a[2]);
                        if (res != INT_MAX)
                        {
                            res = operation(k, res, a[3]);
                            if (res <= 24)
                            {
                                max_ = max(max_, res);
                            }
                        }
                    }
                    // (()())
                    int res1 = operation(i, a[0], a[1]);
                    if (res1 != INT_MAX)
                    {
                        int res2 = operation(j, a[2], a[3]);
                        if (res2 != INT_MAX)
                        {
                            res = operation(k, res1, res2);
                            if (res <= 24)
                            {
                                max_ = max(max_, res);
                            }
                        }
                    }
                }
            }
        }

    } while (next_permutation(all(a)));

    cout << max_ << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t;
    cin >> t;
    // t = 1;
    while (t--)
        s();
    return 0;
}