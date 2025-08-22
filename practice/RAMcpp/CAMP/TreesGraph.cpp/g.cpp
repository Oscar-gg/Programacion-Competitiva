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
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 5001
#define MOD 1000000007

vi graph[MAXN];
vi visited(MAXN, -1);


bool flag = false;
void dfs(int u, int level) {
    if (flag) return;

    visited[u] = 1;
    for (int i = 0; i < (int)graph[u].size(); i++) {
        if (visited[graph[u][i]] == -1)
            dfs(graph[u][i], level+1);
        else if (visited[graph[u][i]] == 1 && level == 2)
            flag = true;
    }

}

int main() { _
    int n,a;
    cin >> n;
    vi nums;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        graph[i].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, 0);
        if (flag) {
            cout << "YES" << endl;
            return 0;
        } 
    }

    cout << "NO" << endl;

    return 0;
}