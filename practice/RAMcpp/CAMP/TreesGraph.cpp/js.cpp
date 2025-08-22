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
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 

class UnionFind { 
    private:
        vi p, rank; 
    public:
        UnionFind(int N) { 
            rank.assign(N, 0);
            p.assign(N, 0); 
            for (int i = 0; i < N; i++) 
            p[i] = i; 
        }

        int findSet(int i) { 
            return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
        }

        bool isSameSet(int i, int j) { 
            return findSet(i) == findSet(j); 
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) { 
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) 
                p[y] = x; 
            else { 
                p[x] = y;

                if (rank[x] == rank[y]) 
                    rank[y]++; 
            }
        } } 
};

vector< pair<ll, pair<ii,ll> > > EdgeList; 

ll maxEdge = 0;
ll minEdge = INF;

bool kruskal(ll & m, ll & n) {
    UnionFind UF(n+10); 

    bool flag = false;
    for (int i = 0; i < m; i++) { 
        pair<ll, pair<ii,ll>> front = EdgeList[i];
        
        if (!UF.isSameSet(front.second.first.first, front.second.first.second)) { 
            if (front.second.second == 0) //id = 0
                flag = true;
            // cout << front.first << endl;
            maxEdge = max(maxEdge, front.first);
            minEdge = min(minEdge, front.first);
            // mst_cost += front.first; 
            UF.unionSet(front.second.first.first, front.second.first.second); 
        } 
    }

    return flag;

}



int main() { _
    ll n, m, a, b, c;

    cin >> n >> m;

    
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        // scanf("%d %d %d", a, b, c);
        EdgeList.pb({c,{{a,b},i}});
    }   

    // for (auto i : EdgeList) {
    //     cout << i.first << " ";
    // }

    pair<ll, pair<ii,ll>> trap = EdgeList[0];

    sort(EdgeList.begin(), EdgeList.end()); 

    // cout << endl;

    bool already = kruskal(m, n);
    // cout << "\nAlready " << trap.first << endl;

    bool uses;
    ll low = already ? trap.first : minEdge;
    ll high = maxEdge;
    ll mid;

    // cout << "BS" << endl;
    while (low <= high) {
        // flag = false;
        mid = low + (high-low)/2;
        // cout << mid << " ";

        int index = lower_bound(EdgeList.begin(), EdgeList.end(), trap) - EdgeList.begin();
        EdgeList.erase(EdgeList.begin() + index);
        trap.first = mid;

        int x = upper_bound(EdgeList.begin(), EdgeList.end(), trap) - EdgeList.begin(); //returns 4
        EdgeList.insert(EdgeList.begin() + x, trap);

        uses = kruskal(m,n);    

        if (uses) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    
    // cout << endl << "ANS " << mid << endl;
    cout << mid << endl;

    
    return 0;
}