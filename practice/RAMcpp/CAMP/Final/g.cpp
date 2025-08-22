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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

int strToN(string s)
{
    int tot = 0;
    if (s[0] == '1')
        tot += 4;
    if (s[1] == '1')
        tot += 2;
    if (s[2] == '1')
        tot += 1;

    return tot;
}

string getNext(string s, int rule)
{
    string n = "0";
    for (int i = 1; i < s.size() - 1; i++)
    {
        string state = s.substr(i - 1, 3);
        // dbg(state);
        int sel = strToN(state);
        // dbg(sel);
        // dbg(rule);

        if (rule & (1 << sel))
        {
            n += "1";
        }
        else
        {
            n += "0";
            // cout << "added zero\n";
        }
    }

    n += "0";
    return n;
}

int main()
{
    _

        int r,
        k;
    cin >> r >> k;
    string init;
    cin >> init;
    init = '0' + init + '0';

    for (int i = 0; i < init.size(); i++)
    {
        if (init[i] == 'X')
        {
            init[i] = '1';
        }
        else
        {
            init[i] = '0';
        }
    }
    while (k--)
    {
        string n = getNext(init, r);
        // dbg(n);
        for (int i = 1; i < n.size() - 1; i++)
        {
            if (n[i] == '1')
            {
                cout << 'X';
            }
            else
            {
                cout << '.';
            }
        }
        cout << "\n";
        init = n;
    }

    return 0;
}