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
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 
int main() { 

    int n;
    cin >> n;


    vector<pair<int, int>> v(n);

    vector<pair<int, int>> dp[2];

    for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        v[i] = {x, h};
    }
    int count = 2;
    dp[0].push_back({1, v[0].first});
    dp[1].push_back({1, v[0].first});

    for(int i = 1; i < n-1; i++){
        pair<int, int> next0, next1;

        int n0c = dp[0].back().first;
        if (v[i].first - v[i].second > dp[0].back().second)
            n0c++;
        
        if (v[i].first + v[i].second > dp[0].back().second)
            n0c++;

        // next0 = max(dp[0].back(), d)
    }

    cout << max(dp[0].back().first, dp[1].back().first) << "\n";

    return 0;
}