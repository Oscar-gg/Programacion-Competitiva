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

int toMin(string s)
{
    int m = 0;
    int h = stoi(s.substr(0, 2));
    m += h * 60;
    m += stoi(s.substr(3, 2));
    return m;
}

void s()
{
    string s, s2, s3, s4;
    cin >> s >> s2 >> s3 >> s4;
    unordered_map<string, int> day{
        {"Mon", 0},
        {"Tue", 1},
        {"Wed", 2},
        {"Thu", 3},
        {"Fri", 4},
        {"Sat", 5},
        {"Sun", 6},
    };

    int min = 0;
    min += day[s3] * 24 * 60;
    min += toMin(s4);
    min -= day[s] * 24 * 60;
    min -= toMin(s2);

    // if (day[s3] < day[s])
    //     min += 7 * 24 * 60;

    if (min <= 0)
    {
        min += 7 * 24 * 60;
    }

    int h = min / 60;
    min -= h * 60;
    int d = h / 24;
    h -= d * 24;

    int c = 0;
    if (h > 0)
        c++;
    if (min > 0)
        c++;
    if (d > 0)
        c++;

    if (d)
    {
        cout << d << " " << "day";
        if (d > 1)
            cout << "s";
        if (c > 2)
            cout << ", ";
        else if (c == 2)
            cout << " and ";
    }

    if (h)
    {
        cout << h << " " << "hour";
        if (h > 1)
            cout << "s";
        if (c == 3)
            cout << ", ";
        else if (c == 2 && d == 0)
            cout << " and ";
    }
    if (min)
    {
        cout << min << " " << "minute";
        if (min > 1)
            cout << "s";
    }
    cout << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        s();
    return 0;
}