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


void solve(){
    long long int n, k;
    cin >> n >> k;

    // cout << "n:" << n << "\n";
    // cout << "k:" << k << "\n";

    vector<long long int> cost;

    int ans = 0;

    for(int i = 0; i < n; i++){
        int next;
        cin >> next;

        // cout << "next: " << next << "\n";

        // cout << "IN LOOP\n";

        for(int j = 0; j <= 62; j++){
            if (!(next & (1ll << j))){
                cost.push_back(1ll << j);
            } else {
                ans++;
            }
        }
    }


    
    sort(cost.begin(), cost.end());

    // for(int i = 0; i < cost.size(); i++){
    //     cout << cost[i] << " ";
    // }
    // cout << "\n";
    // return;

    for(int i = 0; i < cost.size(); i++){

        // cout << cost[i] << "\n";
        if (k >= cost[i]){
            k -= cost[i];
            ans++;
        } else {
            break;
        }
    }

    // cout << "k:" << k << "\n";

    cout << ans << "\n";

}

int main() { _

    int t;
    cin >> t;

    // cout << "t: " << t << "\n";

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}