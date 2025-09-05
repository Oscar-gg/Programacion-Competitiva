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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &v : a)
        cin >> v;
    vector<ll> b(n);
    for (auto &v : b)
        cin >> v;

    ll cD = n - 2, prev = n;
    for (int i = 0; i < n / 2; i++)
    {
        a[i] *= prev;
        a[n - i - 1] *= prev;
        prev = prev + cD;
        cD = cD - 2;
    }

    if (n % 2 == 1)
    {
        a[n / 2] *= prev;
    }

    // for (auto v : a)
    // {
    //     cout << v << " ";
    // }
    // cout nl;

    sort(all(a));
    sort(b.rbegin(), b.rend());

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += a[i] * b[i];
    }

    cout << ans << "\n";

    // for (int i = 1; i < 10; i++)
    // {
    //     vector<int> c(i);

    //     for (int j = 0; j < i; j++)
    //     {
    //         for (int k = j; k < i; k++)
    //         {
    //             for (int l = j; l <= k; l++)
    //             {
    //                 c[l]++;
    //             }
    //         }
    //     }
    //     for (auto v : c)
    //     {
    //         cout << v << " ";
    //     }
    //     cout << "\n";
    // }
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