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

void solve(int n, int k) {
    ll find = n*k;
    // if (k % 2 != 0) {
    //     cout << ((find % 2 == 0) ? "Teemo" : "Omda") << endl;
    //     return;
    // }

    vector<bool> dp(k+2, true);
    for (int i = 1; i < k; i++) {
        if (i % 2 == 0)
            dp[i] = false;
    }

    dp[k] = true;
    dp[k+1] = false;

    // for (int i = 0; i<= k+1;i++) {
    //     cout << i << " ";
    //     cout << dp[i] << endl;
    // }

    ll index = find % (k+1);
    if (index == 0)
        index = k+1;

    // cout << index << endl;
    if (dp[index]) {
        printf("Omda\n");
        // cout << "Omda" << endl;
    } else {
        printf("Teemo\n");
        // cout << "Teemo" << endl;
    }
        
}

int main() { 
    freopen("dotak.in", "r", stdin);
    int t,n,k;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        // printf("Omda\nOmda\n");
        solve(n,k);

    }
    

    return 0;
}