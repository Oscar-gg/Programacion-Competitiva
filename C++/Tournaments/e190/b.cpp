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

int bruteDist(int index, int num, vector<int> &a){
    int min_ = INT_MAX;

    if (index > 0){
        if (abs(num-a[index -1]) <= 1)
            return 0;

        int t = a[index - 1], b = a[index - 1];
        
        
        for(int i = index-1; i>= 0; i--){
            t = max(t, a[i]);
            b = min(b, a[i]);
            if (num >= b-1 && num <= t+1){
                min_ = index - i - 1;
                break;
            }
        }
    }

    // cout << "min_: " << min_ << "\n";

    if (index < a.size()-2){
        if (abs(num-a[index+1]) <= 1)
            return 0;

        int t = a[index + 1], b = a[index + 1];
        
        
        for(int i = index+1; i< a.size(); i++){
            t = max(t, a[i]);
            b = min(b, a[i]);
            if (num >= b-1 && num <= t+1){
                min_ = min(min_, i - index - 1);
                break;
            }
        }
    }

    return min_;

}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = INT_MAX;

    for(int i = 0; i < n; i++){
        ans = min(ans, bruteDist(i, a[i], a));
    }
    if (ans == INT_MAX){
        cout << -1 << "\n";
        return;
    }

    cout << ans << "\n"; 

}

int main() { _
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}