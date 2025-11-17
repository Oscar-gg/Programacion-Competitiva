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
#define nl << "\n"

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

void s()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &v : a)
    {
        cin >> v;
    }
    int ans = 0;
    sort(all(a));

    for (int i = 1000; i > 0; i--)
    {
        vector<int> v, vc = a;
        int vC = 0;
        for (int j = n - 1; j >= 0 && vC <= k; j--)
        {
            while (vc[j] >= i && vC <= k)
            {
                v.push_back(i);
                vC++;
                vc[j] -= i;
            }
            v.push_back(vc[j]);
        }

        if (vC == k)
        {
            ans = max(ans, k / 2 * i);
        }
        else
        {
            sort(all(v));
            int st = v.size() - k;
            int t = 0;
            for (int j = st; j < st + k / 2; j++)
            {
                if (j >= 0)
                    t += v[j];
            }
            ans = max(t, ans);
        }
    }

    cout << ans << "\n";
}

int main()
{
    _;

    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}