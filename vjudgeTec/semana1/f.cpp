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

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define RFOR(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define FORC(cont, it) for (typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for (typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

void solve()
{
    int n;
    cin >> n;
    priority_queue<int> pq;                            // 3 greatest elements
    priority_queue<int, vector<int>, greater<int>> gq; // 3 smallest elements

    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;
        pq.push(next);
        gq.push(next);
        if (pq.size() > 3)
            pq.pop();
        if (gq.size() > 3)
            gq.pop();
    }

    vector<long double> vals;
    while (!pq.empty())
    {
        vals.push_back(pq.top());
        pq.pop();
    }
    while (!gq.empty())
    {
        vals.push_back(gq.top());
        gq.pop();
    }
    sort(vals.begin(), vals.end());

    if (n != 5)
    {
        long double s1 = vals[0];
        long double s2 = vals[1];
        long double e1 = vals[vals.size() - 2];
        long double e2 = vals[vals.size() - 1];
        cout << (e1 + e2) / 2 - (s1 + s2) / 2 << endl;
    }
    else
    {
        long double s1 = vals[0];
        long double s2 = vals[1];
        long double s3 = vals[2];

        long double e1 = vals[vals.size() - 1];
        long double e2 = vals[vals.size() - 2];
        long double e3 = vals[vals.size() - 3];

        long double op1 = (e3 + e1) / 2 - (s1 + s2) / 2;
        long double op2 = (e2 + e1) / 2 - (s1 + s3) / 2;

        long double ans = max(op1, op2);
        cout << ans << "\n";
    }
}

int main()
{
    _
        ll h,
        w, n;
    cin >> h >> w >> n;

    int _max = max(h, w);
    int ans = n / _max;
    if (n % _max != 0)
        ans++;

    cout << ans;

    return 0;
}

// g++ -std=c++11