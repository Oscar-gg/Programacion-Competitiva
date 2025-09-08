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

// after reading editorial and a solution

void update(vector<int> &a, int n)
{
    vector<int> freq(n + 1);
    for (int i = 0; i < a.size(); i++)
    {
        freq[a[i]]++;
    }

    int mex = -1;

    for (int i = 0; i <= n; i++)
    {
        if (freq[i] == 0)
        {
            mex = i;
            break;
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (freq[a[i]] == 1 && a[i] < mex)
        {
            // ignore (best option is self)
        }
        else
        {
            a[i] = mex;
        }
    }
}

void s()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    unordered_map<int, unordered_set<int>> seen;
    for (auto &v : a)
    {
        cin >> v;
    }

    int it = min(k, k % 2 + 2); // After 2 iterations, the array toggles between 2 states

    while (it--)
    {
        update(a, n);
    }
    ll total = 0;

    for (int i = 0; i < n; i++)
    {
        total += a[i];
    }

    cout << total << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        s();
    return 0;
}