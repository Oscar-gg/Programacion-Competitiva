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
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    int pos = 0;

    for(int i = 2; i < n; i++){
        for(int j = 1; j < i; j++){

            int bin = lower_bound(a.begin(), a.begin() + j, a[i] - a[j]+1) - a.begin();

            if (j == bin){
                bin--;
                if (bin < 0)
                    continue;
            }
            
            if (a[i] + a[j] + a[bin] <= a.back())
                continue;

            if (a[i] >= a[j] + a[bin]){
                bin++;
                if (bin >=j)
                    continue;
                if (a[i] >= a[j] + a[bin])
                    continue;

            }
            
            // cout << "diff: " << a[i] - a[j] << "\n";
            // cout << i << " " << j << " " << bin  << "\n"; 

            // cout << a[i] << " " << a[j] << " " << a[bin]  << " " << a.back() << "\n"; 

            pos += j - bin;
        }
    }

    cout << pos << "\n";

}

int main() { _

    int t;
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}