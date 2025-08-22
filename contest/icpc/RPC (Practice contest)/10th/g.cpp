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
    int n, L;
    cin >> n >> L;
    vector<pair<double, pair<double, double>>> a(n);

    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, {y, z}};
    }

    // for(auto x : a){
    //     cout << x.first << " " << x.second.first << " " << x.second.second << "\n";
    // }

    sort(a.begin(), a.end());
    a.push_back({L ,{0,0}});
    
    vector<double> minT(a.size(), INT_MAX);

    for(int i = 0; i < a.size(); i++){
        minT[i] = a[i].first;
    }

    for(int i = 0; i < a.size()-1; i++){
        int pd = a[i].first + (a[i].second.first * a[i].second.second);
        // dbg(pd);

        for(int j = i+1; j < a.size()-1; j++){
            if (a[j].first >= pd)
                minT[j] = min(minT[j], minT[i] + a[i].second.second + (a[j].first - pd));
        }

        if (pd <= a.back().first){
            minT.back() = min(minT.back(), L - pd + minT[i] + a[i].second.second);
        } else {
            minT.back() = min(minT.back(), minT[i] + ((L - a[i].first) / a[i].second.first));
        }
    }

    // for(auto t :  minT)
    //     cout << t << " ";

    
    
    // cout << "\n";

    cout << minT.back() << "\n";


}   

int main() { _
    solve();
    return 0;
}