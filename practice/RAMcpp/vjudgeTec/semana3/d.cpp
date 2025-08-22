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

int getSize(int n)
{
    vll first;
    vll end;
    ll sq = ceil(sqrt(n));
    for (ll i = 1; i < sq; i++)
    {
        if (n % i == 0)
        {
            first.pb(i);
            end.pb(n / i);
        }
    }
    if (sq * sq == n)
    {
        first.pb(n / sq);
    }
    return first.size() + end.size();
}

void solve(vector<int> &primes)
{
    ll n = 0;
    cin >> n;
    vector<ll> d(n, 0);

    for (ll i = 0; i < n; i++)
    {
        ll next = 0;
        cin >> next;
        d[i] = next;
    }

    sort(d.begin(), d.end());

    if (n == 1)
    {
        if (binary_search(primes.begin(), primes.end(), d[0]))
        {
            cout << d[0] * d[0] << "\n";
        }
        else
        {
            cout << "-1\n";
        }
        return;
    }

    ll predict = d[0] * d[n - 1];

    for (ll i = 0; i <= n / 2; i++)
    {
        if (predict != d[i] * d[n - i - 1])
        {
            cout << "-1\n";
            return;
        }
    }

    int val = getSize(predict);

    if (val == n + 2)
    {
        cout << predict << "\n";
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    sync;

    vector<int> primes;

    computeSieve(primes);

    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        solve(primes);
    }
    return 0;
}