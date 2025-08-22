// Rbrgs.cpp
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

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;

void computeSieve(vector<int> &primes)
{
    bitset<1000001> bset;

    bset.set();
    bset[0] = bset[1] = 0;

    for (ll i = 2; i < bset.size(); i++)
    {
        if (bset[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j < bset.size(); j += i)
            {
                bset[j] = 0;
            }
        }
    }
}

void solve(vector<int> &primes)
{
    ll x;
    cin >> x;

    auto index = lower_bound(primes.begin(), primes.end(), x);
    cout << primes[index - primes.begin()];
}

int main()
{
    sync;

    vector<int> primes;

    computeSieve(primes);

    // for (auto x : primes)
    // {
    //     cout << x << " ";
    // }
    solve(primes);

    return 0;
}