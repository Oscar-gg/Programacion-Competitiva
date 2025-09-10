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

// Brute force
void s()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v : a)
        cin >> v;

    if (n % 2 == 1)
    {
        a.push_back(0);
        n++;
    }

    vector<int> scores;

    int x = 0;
    int cost = 0;

    for (int i = 0; i < n - 1; i += 2)
    {
        cost += a[i] - a[i + 1];
    }

    bool alice = true;
    int it = 1;
    while (it--)
    {
        int minDelta = cost;
        int maxDelta = cost;
        int index1 = -1, index2 = -1;
        int index3 = -1, index4 = -1;
        int curCost = cost;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int tempcost = cost;

                int delta = j - i;
                if (i % 2 == 0 && j == i + 1)
                {
                    tempcost -= a[i] - a[j];
                    swap(a[i], a[j]);
                    tempcost += delta + a[i] - a[j];
                    if (tempcost < minDelta)
                    {
                        index1 = i;
                        index2 = j;
                        minDelta = tempcost;
                    }
                    if (tempcost > maxDelta)
                    {
                        index3 = i;
                        index4 = j;
                        maxDelta = tempcost;
                    }
                    swap(a[i], a[j]);
                }
                else
                {
                    if (i % 2 == 0)
                    {
                        tempcost -= a[i] - a[i + 1];
                    }
                    else
                    {
                        tempcost -= a[i - 1] - a[i];
                    }

                    if (j % 2 == 0)
                    {
                        tempcost -= a[j] - a[j + 1];
                    }
                    else
                    {
                        tempcost -= a[j - 1] - a[j];
                    }
                    swap(a[i], a[j]);

                    if (i % 2 == 0)
                    {
                        tempcost += a[i] - a[i + 1];
                    }
                    else
                    {
                        tempcost += a[i - 1] - a[i];
                    }

                    if (j % 2 == 0)
                    {
                        tempcost += a[j] - a[j + 1];
                    }
                    else
                    {
                        tempcost += a[j - 1] - a[j];
                    }
                    swap(a[i], a[j]);
                    tempcost += delta;
                    if (tempcost < minDelta)
                    {
                        index1 = i;
                        index2 = j;
                        minDelta = tempcost;
                    }
                    if (tempcost > maxDelta)
                    {
                        index3 = i;
                        index4 = j;
                        maxDelta = tempcost;
                    }
                }
            }
        }
        if (alice)
        {
            scores.push_back(maxDelta);
            cost = maxDelta;
            swap(a[index3], a[index4]);
        }
        else
        {
            scores.push_back(minDelta);
            cost = minDelta;
            swap(a[index1], a[index2]);
        }
        alice = !alice;
        break;
    }

    cout << scores[0] << "\n";
}

// from editorial
void s2()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &v : a)
        cin >> v;

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum += a[i];
        }
        else
        {
            sum -= a[i];
        }
    }

    ll ans = sum;

    for (int i = n - 1; i > n - 3 && i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            ans = max(ans, sum + i);
        }
        else
        {
            ans = max(ans, sum + i - 1);
        }
    }

    ll maxOdd = INT_MIN, minEven = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            ans = max(ans, sum + i - 2 * a[i] + maxOdd);
            minEven = min(minEven, i + 2 * a[i]);
        }
        else
        {
            ans = max(ans, sum + i + 2 * a[i] - minEven);
            maxOdd = max(maxOdd, -i + 2 * a[i]);
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
        s2();
    return 0;
}