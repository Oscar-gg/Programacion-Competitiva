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

template <class T> struct SegTree {
	T U = 1e9;
	T F(T a, T b) { return min(a, b); }
	int N;
	vector<T> t;
	SegTree() {}
	SegTree(int N) : N(N), t(4 * N, U) {}
	void upd(int I, T V) { upd(I, V, 1, 1, N); }
	void upd(int I, T V, int i, int l, int r) {
		if (l == r) {
			t[i] = V;
			return;
		}
		int m = (l + r) / 2;
		if (I <= m) upd(I, V, i * 2, l, m);
		else upd(I, V, i * 2 + 1, m + 1, r);
		t[i] = F(t[i * 2], t[i * 2 + 1]);
	}
	T qry(int L, int R) { return qry(L, R, 1, 1, N); }
	T qry(int L, int R, int i, int l, int r) {
		if (L <= l && r <= R) return t[i];
		if (R < l || L > r) return U;
		int m = (l + r) / 2;
		return F(qry(L, R, i * 2, l, m), qry(L, R, i * 2 + 1, m + 1, r));
	}
};
const int maxn = 2e5 + 5;

int n, q;
SegTree<int> tree;

// https://usaco.guide/problems/cses-2206-pizzeria-queries/solution

void solve(){
    int n, q;
    cin >> n >> q;

    SegTree<int> downT(n), uptT(n);
    
    for(int i = 1; i <= n; i++){
        int next;
        cin >> next;
        downT.upd(i, next - i);
        uptT.upd(i, next + i);
    }
    
    for(int i = 0; i < q; i++){
        int qt;
        cin >> qt;

        if (qt == 1){
            int k, x;
            cin >> k >> x;
            downT.upd(k, x - k);
            uptT.upd(k, x + k);
        } else {
            int k;
            cin >> k;
            int min1 = downT.qry(1, k) + k;
            int min2 = uptT.qry(k,  n) - k;
            // cout << min1 << " " << min2 << " ";
            cout << min(min1, min2) << "\n";
        }
    }

}

int main() { _
    solve();
    return 0;
}