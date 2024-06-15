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
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define RFOR(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define FORC(cont, it) for (typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for (typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

int main()
{
    _

        int n;
    cin >> n;

    unordered_map<int, vector<int>> umap;

    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        umap[u].push_back(v);
        umap[v].push_back(u);
    }

    queue<pair<int, int>> q;
    q.push({1, 0});

    unordered_set<int> visited;
    int l = 1;

    while (!q.empty()){
        auto f = q.front();
        q.pop();
        l = f.first;

        for(auto x : umap[f.first]){
            if (!visited.count(x)){
                visited.insert(x);
                q.push({x, f.second + 1});
            }
        }
    }

    unordered_set<int> v2;
    int ms = 0;
    q.push({l, 0});

    while (!q.empty()){
        auto f = q.front();
        q.pop();
        l = f.first;
        ms = max(ms, f.second);
        // cout << "in\n";

        for(auto x : umap[f.first]){
            if (!v2.count(x)){
                v2.insert(x);
                q.push({x, f.second + 1});
            }
        }
    }

    cout << ms << "\n";



    return 0;
}