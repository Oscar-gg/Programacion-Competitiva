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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

int main()
{
    _

        ll n,
        m;
    cin >> n >> m;
    unordered_map<ll, vector<pair<ll, ll>>> umap;

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        umap[a].push_back({b, c});
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    unordered_map<ll, ll> visited;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto f = pq.top();
        pq.pop();
        if (visited.count(f.second))
            continue;
        visited[f.second] = f.first;

        for (auto neighbour : umap[f.second])
        {
            if (!visited.count(neighbour.first))
            {
                pq.push({f.first + neighbour.second, neighbour.first});
            }
        }
    }

    for(ll i = 1; i <= n; i++){
        cout << visited[i] << " ";
    }
    cout << "\n";

    return 0;
}