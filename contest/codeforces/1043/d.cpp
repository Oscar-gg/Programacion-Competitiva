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

vector<ll> pos(long long int n)
{
    ll level = 0;

    ll levelS = 9;
    ll levelSum = 9;

    while (n > levelS)
    {
        level++;
        levelS *= 10;
        levelSum += levelS;
    }

    ll comp;

    return {1};
}

// 00001
// 00002
// 00003
// 00005
// 00006
// 00007
// 00008
// 00009
// 00010
// 00011
// 00012
// 00013
// 00014
// 00015
// 00016
// 00017
// 00018

// Get actual number
// amount of one level = prev level * (1) + prev level *

// level 1 -> 9
// level 2 -> (1 + prev) + (2 + prev) ... + (9 + prev) -> prev(1 + 2 ... + 9)
// level 3 -> (1 + prev) + ... (9 + prev) -> prev(1 + 2 ... + 9)

void s()
{
    ll k;
    cin >> k;
    unordered_map<int, int> umap;
    for (int i = 1; i < 1e8; i++)
    {
        umap[(int)log10(i)]++;
    }
    for (auto x : umap)
    {
        cout << x.first << " " << x.second << "\n";
    }

    cout << pos(10) << "\n";
    cout << pos(100) << "\n";
    cout << pos(1) << "\n";
}
int main()
{
    _ int t;
    cin >> t;
    while (t--)
        s();
    return 0;
}