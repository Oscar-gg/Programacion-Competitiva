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

unordered_map<int, int> m;
 
ll _sieve_size; 
bitset<10000010> bs; 
vi primes;

void sieve(ll upperbound) { 
    _sieve_size = upperbound + 1; 
    bs.set(); 
    bs[0] = bs[1] = 0; 
    for (ll i = 2; i <= _sieve_size; i++) 
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i); 
        } 
}

int getN(int cur){
    if (m.count(cur))
        return m[cur];
        
    int ind = 0;

    while (ind < primes.size() && primes[ind] * primes[ind] <= cur){
        if (cur % primes[ind] == 0){
            return m[cur] = cur / primes[ind];
        }
        ind++;
    }

    return 1;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n), b(n);

    for (auto &x : a)
    {
        cin >> x;
    }

    for (auto &x : b)
    {
        cin >> x;
    }

    int op = 0, pv = op;

    for(int i = 0; i < n; i++){
        while (a[i] != b[i]){
            if (a[i] > b[i]){
                a[i] = getN(a[i]);
            } else {
                b[i] = getN(b[i]);
            }
            // cout << a[i <<]
            // cout << a[i] << " " << b[i] << "\n";
            op++;
            // cout << 
        }
        // dbg(op - pv);
        pv = op;
    }

    cout << op << "\n";

}

int main()
{
    _
    sieve(10000000);
        int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}