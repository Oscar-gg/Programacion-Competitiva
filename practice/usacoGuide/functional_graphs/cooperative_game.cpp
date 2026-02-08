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
#define MAXN 10
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};

vector<int> read()
{
    string s;
    cin >> s;
    if (s == "stop")
        return {};

    int k = stoi(s);
    vector<int> a(k);

    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            a[i] |= 1 << (s[j] - '0');
        }
    }

    return a;
}

vector<int> pr(int s, int e)
{
    cout << "next ";
    for (int i = s; i <= e; i++)
        cout << i << " ";

    cout nl;
    cout.flush();
    return read();
}

bool found(vector<int> &a, int f, int s)
{
    for (int i = 0; i < a.size(); i++)
    {
        if ((a[i] & (1 << f)) && (a[i] & (1 << s)))
            return true;
    }
    return false;
}

void s()
{
    bool f = false;
    vector<int> res;
    bool p2 = false;

    while (!found(res, 0, 1))
    {

        res = pr(0, 1);
        if (res.size() == 0)
            return;

        res = pr(1, 1);
        if (res.size() == 0)
            return;
    }

    while (res.size() != 1)
    {
        if (res.size() == 0)
            return;
        res = pr(0, 9);
    }

    cout << "done\n";
    cout.flush();
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