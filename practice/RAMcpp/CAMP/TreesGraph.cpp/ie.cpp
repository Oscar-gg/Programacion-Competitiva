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

using namespace std;
#include <stdio.h>
#define MAX_BOLTS 500
#define MAX_NUTS 500
/*globalcopyoftheinputdata*/
int nuts, bolts;
int fits[MAX_BOLTS][MAX_NUTS];
void read_input_data(void)
{
    int n, b;
    scanf("%d%d", &bolts, &nuts);
    for (b = 0; b < bolts; b++)
    {
        for (n = 0; n < nuts; n++)
        {
            scanf("%d", &fits[b][n]);
        }
    }
}
/* data used to match nuts with bolts */
int nut_used[MAX_NUTS];
int bestmatched;

void init_match(void)
{
    int n;
    bestmatched = 0;
    for (n = 0; n < nuts; n++)
        nut_used[n] = 0;
}
void match_bolt(int boltno, int matched)
{
    int n;
    if (boltno == bolts)
    {
        if (matched > bestmatched)
            bestmatched = matched;
        return;
    }
    /* don’t match this bolt */
    match_bolt(boltno + 1, matched);
    /*matchwithallunusednutsthatfitthisbolt*/
    for (n = 0; n < nuts; n++)
    {
        if (!nut_used[n] && fits[boltno][n])
        {
            if (boltno == 2)
            {
                cout << n << " ";
            }
            nut_used[n] = 1;
            match_bolt(boltno + 1, matched + 1);
            nut_used[n] = 0;
        }
        if (boltno == 2 && n == nuts-1)
        {
            cout << "\n";
        }
    }
}

int bfs(){
    unordered_set<vector<bool>> sets;
    
    vector<bool> initial(nuts);
    sets.insert(initial);

    for(int i = 0; i < bolts; i++){
        unordered_set<vector<bool>> nS;
        for(int j = 0; j < nuts; j++){
            if (fits[i][j]){
                for(auto x :sets){
                    // cout << "added set it " << i << " " << j << "\n";
                    vector<bool> next = x;
                    next[j] = true;
                    nS.insert(next);
                    
                }
            }
        }
        // cout << sets.size() << " " << nS.size() << "\n";
        if (!nS.empty()){
            sets = nS;
        }
    }

    int ans = 0;
    for(auto x : sets){
        // cout << x.size() << "\n";
        int c = 0;
        for(auto j : x)
            if (j)
                c++;

        ans = max(ans, c);
    }
    // dbg(sets.size());
    return ans;
}



int main()
{
    int cases, caseno;
    scanf("%d", &cases);
    for (caseno = 1; caseno <= cases; caseno++)
    {
        read_input_data();
        init_match();
        // match_bolt(0, 0);
        printf("Case %d: ", caseno);
        int ans = bfs();
        printf("a maximum of %d nuts and bolts ", ans);
        printf("can be fitted together\n");

        // for(int i = 0; i < bolts; i++){
        //     for(int j = 0; j < nuts; j++){
        //         cout << fits[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
    return 0;
}

