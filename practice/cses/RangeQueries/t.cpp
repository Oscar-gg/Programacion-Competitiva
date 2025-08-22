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

template <class T>
struct SegTree
{
    T U = 0;
    T F(T a, T b) { return a ^ b; }
    int N;
    vector<T> t;
    SegTree() {}
    SegTree(int N) : N(N), t(4 * N, U) {}
    void upd(int I, T V) { upd(I, V, 1, 1, N); }
    void upd(int I, T V, int i, int l, int r)
    {
        if (l == r)
        {
            t[i] = V;
            return;
        }
        int m = (l + r) / 2;
        if (I <= m)
            upd(I, V, i * 2, l, m);
        else
            upd(I, V, i * 2 + 1, m + 1, r);
        t[i] = F(t[i * 2], t[i * 2 + 1]);
    }
    T qry(int L, int R) { return qry(L, R, 1, 1, N); }
    T qry(int L, int R, int i, int l, int r)
    {
        if (L <= l && r <= R)
            return t[i];
        if (R < l || L > r)
            return U;
        int m = (l + r) / 2;
        return F(qry(L, R, i * 2, l, m), qry(L, R, i * 2 + 1, m + 1, r));
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    SegTree<ll> t(n);

    for(int i = 1; i <= n; i++){
       int next;
       cin >> next;
       t.upd(i, next);
    }

    for(int i = 0; i < q; i++){
        int c;
        c = 2;
        // cin >> c;
        int a, b;
        cin >> a >> b;
        if (c == 2){
            cout << t.qry(a, b) << "\n";
        } else {
            t.upd(a, b);
        }
        
    }

}

int main()
{
    _
        solve();

        return 0;
}