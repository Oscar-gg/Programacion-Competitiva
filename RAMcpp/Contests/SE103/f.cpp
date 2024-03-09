#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
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
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
    sync;
    int n;
    cin >> n;
    
    vector<int> qual(n);
    for(auto &x:qual)
        cin >> x;
    
    int m;
    cin >> m;

    unordered_map<int, int> cost;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (qual[a-1] > qual[b-1]){
            if (cost.count(b)){
                cost[b] = min(cost[b], c);
            } else {
                cost[b] = c;
            }
}
    }

    int tcost = 0, noSup = 0; 

    for(int i = 1; i <= n; i++){
        if(!cost.count(i)){
            noSup++;
        } else {
            tcost += cost[i];
        }
    }

    if (noSup > 1){
        cout << -1 << "\n";
    } else {
        cout << tcost << "\n";
    }

    return 0;
}
