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

// with editorial
void s()
{
    int n;
    cin >> n;
    vector<int> a(n);

    int pos1 = -1, posN = -1;

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        a[i] = v;

        if (v == 1)
        {
            pos1 = i;
        }
        if (v == n)
        {
            posN = i;
        }
    }

    string s;
    cin >> s;

    if (s[0] == '1' || s[n - 1] == '1' || s[pos1] == '1' || s[posN] == '1')
    {
        cout << "-1\n";
        return;
    }
    pos1++;
    posN++;

    cout << 5 << "\n";
    cout << 1 << " " << pos1 << "\n";
    cout << 1 << " " << posN << "\n";
    cout << min(pos1, posN) << " " << max(pos1, posN) << "\n";
    cout << pos1 << " " << n << "\n";
    cout << posN << " " << n << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    cin >> t;

    while (t--)
    {
        s();
    }
    return 0;
}