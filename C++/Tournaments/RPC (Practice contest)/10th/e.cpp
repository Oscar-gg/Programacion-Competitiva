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
 

int sWindow(char c, int m, string &s){

    int l = 0, r = 0, maxLen = 0, rem = 0;
    // cout << "CHECKING " << c << "\n"; 
    while (r < s.size()){
        if (s[r] != c){
            rem++;
        }
        r++;

        while (rem > m){
            if (s[l] != c){
                rem--;
            }
            l++;
        }

        // if (r - l > maxLen)
        //     // cout << l << " " << r << "\n";
        // {for(int j = l; j < r; j++){
        //     cout << s[j];
        // }
        // cout << "\n";}
        maxLen = max(maxLen, r - l - rem);
    }

    return maxLen;
}

void solve(){
    string s;
    int m;

    cin >> s;
    cin >> m;

    int maxL = 0;
    for(char c = 'a'; c <= 'z'; c++){
        int next = sWindow(c, m, s);

        // if (next > maxL){
        //     cout << c << "\n";
        // }
        maxL = max(maxL, next);

    }

    cout << maxL << "\n";

}

int main() { _
    solve();
    return 0;
}