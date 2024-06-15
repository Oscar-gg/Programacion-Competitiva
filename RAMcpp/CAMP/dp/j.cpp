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
 
#define MAXN 1000
#define MOD 1000000007


int solve(vector<string> & strs, vi & costs, vector<vi> & dp, int index, bool rev, string curr) {
    cout << index << " ";
    int y = rev;
    if (index == strs.size()-1) {
        return rev ? costs[index] : 0;
    }

    if (dp[index][y] != -2) return dp[index][y];
    
    int a = -1;
    int b = -1;

    if (strs[index+1] > curr)
        a = solve(strs, costs, dp, index+1, false, strs[index+1]);

    string rev2 = strs[index+1];
    reverse(rev2.begin(), rev2.end());

    if (strs[index+1] > curr) {
        b = solve(strs, costs, dp, index+1, true, rev2) + costs[index+1];
        // cout << b << endl;
        // b += (b != -1) ? costs[index+1] : 0;
    }

    if (a == -1 && b == -1) {
        dp[index][y] = -1;
    } else if (a == -1) {
        dp[index][y] = b;
    } else if (b == -1) {
        dp[index][y] = a;
    } else {
        dp[index][y] = min(a,b);
    }
    
    cout << index << " " << dp[index][y] << endl;
    return dp[index][y];
}
 
int main() { _

    int n, a;
    vi costs;
    vector<string> strs;
    string x;
    vector<vi> dp(MAXN, vector<int>(2,-2));

    // vi dp(n+1, -2);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        costs.pb(a);
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        strs.pb(x);
    }

    int ans = solve(strs, costs, dp, 0, false, strs[0]);
    x = strs[0];
    reverse(x.begin(), x.end());
    int ans2 = solve(strs, costs, dp, 0, true, x);

    cout << endl;
    if (ans == -1 && ans2 == -1) {
        cout << -1; 
        
    } else if (ans == -1) {
        cout << ans2;

    } else if (ans2 == -1) {
        cout << ans;
        
    } else {
        cout << min(ans, ans2) << endl;
    }

    cout << endl;

    return 0;
}