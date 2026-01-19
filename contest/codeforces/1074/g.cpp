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

pair<int, int> get_m(vector<int> &a, vector<int> &freq)
{
    freq = vector<int>(a.size() + 1);

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < freq.size())
            freq[a[i]]++;
    }

    for (int i = 0; i < freq.size(); i++)
    {
        if (!freq[i])
        {
            int j = i + 1;
            for (; j < freq.size(); j++)
            {
                if (!freq[j])
                    break;
            }
            if (i == 0)
            {
                return {i, j - i};
            }

            return {i, j - i};
        }
    }
    return {0, 0};
}

void s()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n);
    vector<vector<int>> freq(n);

    ll elem = 0;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        elem += l;
        while (l--)
        {
            int v;
            cin >> v;
            m[i].push_back(v);
        }
    }
    vector<pair<ll, ll>> v(n);

    ll mSum = 0;
    unordered_map<int, ll> mF;
    for (int i = 0; i < n; i++)
    {
        v[i] = get_m(m[i], freq[i]);
        mF[v[i].first] += v[i].second;
        mSum += v[i].first;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            // dbg(mSum * (n - 1) + mF[m[i][j]]);
            // dbg(mSum);
            // dbg(mF[m[i][j]]);
            ans += mSum * (n - 1) + mF[m[i][j]];

            if (m[i][j] < freq[i].size() && freq[i][m[i][j]] == 1 && m[i][j] <= v[i].first)
                ans -= (n - 1) * (v[i].first - m[i][j]);
        }
    }

    cout << ans << "\n";
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