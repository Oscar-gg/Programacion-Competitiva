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


int computeD(int x1, int y1, int x2, int y2 ){

    return pow(abs(x1-x2), 2) + pow(abs(y2-y1), 2);
}

void solve(){
    int n;
    cin >> n;
    
    vector<int> xs(n);
    vector<int> ys(n);

    for(int i = 0; i < n; i++){
        int ne;
        cin >> ne;
        xs[i] = ne;
    }
    for(int i = 0; i < n; i++){
        int ne;
        cin >> ne;
        ys[i] = ne;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ans = max(ans, computeD(xs[i], ys[i], xs[j], ys[j]));
        }
    }
    
    cout << ans << "\n";
}


int main() { _
    solve();
    return 0;
}