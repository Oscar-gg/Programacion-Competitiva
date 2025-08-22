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
 

int remove(int num){
    int ret = 0;

    while (num > 0){
        ret += num % 10;
        num /= 10;
    }

    return ret;
}

void test(){

    int max_ = 0;

    for(int i = 1e6 - 10; i < 1e6; i++){
        int c = i;
        int counter = 0;
        while (c > 0){
            c = c - remove(c);
            counter++;
        }
        max_ = max(counter, max_);
    }

    cout << "Max op: " << max_ << "\n";

}

int main() { _

    test();
    return 0;
    int n, k;
    cin >> n >> k;

    priority_queue<int> pq;

    for(int i = 0; i < n; i++){
        int next;
        cin >> next;
        pq.push(next);
    }

    long long int ans = 0;

    if (k > 1e6 * 7){
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 0; i < k; i++){
        if (pq.empty()){
            cout << 0 << "\n";
            return 0;
        }
        int top = pq.top();
        // cout << top << "\n";
        pq.pop();
        int next = remove(top);
        if (top - next > 0)
            pq.push(top - next);
        ans = next;
    }

    cout << ans << "\n";

    return 0;
}