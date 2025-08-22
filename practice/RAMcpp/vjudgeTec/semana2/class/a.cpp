//Rbrgs.cpp
#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define RFOR(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define FORC(it, cont) for (auto it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(it, cont) for (auto it = (cont).rbegin(); it != (cont).rend(); it++)
#define aFor(i, a) for (auto &i : a)
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;

#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


void solve(unordered_set<ll> &nums){

    ll x;
    cin >> x;

    for (ll i = 1; i < nums.size(); i++){
        ll next = i * i * i;
        ll target = x - next;
        if (nums.count(target)){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    unordered_set<ll> nums;
    for (ll i = 1; i < 10e4 + 1; i++){
        // ll next = pow(i, 3);
        ll next = i * i * i;
        nums.insert(next);
    }

    sync;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        solve(nums);
    }
    return 0;
}