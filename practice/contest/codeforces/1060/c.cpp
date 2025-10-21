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
#define all(x) x.begin(), x.end()
#define nl << "\n"

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

ll _sieve_size;
bitset<200001> bs;
vi primes;

void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i])
        {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}

vi primeFactors(ll N, unordered_map<int, vector<int>> &cache)
{
    if (cache.count(N))
        return cache[N];

    if (N < 2)
    {
        return cache[N] = {};
    }
    int cn = N;

    unordered_set<int> factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N)
    {
        while (N % PF == 0)
        {
            N /= PF;
            factors.insert(PF);
        }
        PF = primes[++PF_idx];
    }

    if (N != 1)
        factors.insert(N);

    vector<int> un(factors.begin(), factors.end());
    return cache[cn] = un;
}

void s(unordered_map<int, vector<int>> &cache)
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (auto &v : a)
        cin >>
            v;
    for (auto &v : b)
        cin >> v;

    unordered_map<int, int> primes;

    for (int i = 0; i < n; i++)
    {
        vector<int> p = primeFactors(a[i], cache);

        for (int j = 0; j < p.size(); j++)
        {
            if (primes[p[j]] > 0)
            {
                cout << "0\n";
                return;
            }
        }

        for (int j = 0; j < p.size(); j++)
        {
            primes[p[j]]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> p = primeFactors(a[i], cache);
        vector<int> p2 = primeFactors(a[i] + 1, cache);

        for (int j = 0; j < p.size(); j++)
        {
            primes[p[j]]--;
        }

        for (int j = 0; j < p2.size(); j++)
        {
            if (primes[p2[j]] > 0)
            {
                cout << "1\n";
                return;
            }
        }

        for (int j = 0; j < p.size(); j++)
        {
            primes[p[j]]++;
        }
    }

    if (primes[2] > 0)
    {
        cout << "1\n";
    }
    else
    {
        cout << "2\n";
    }
}

int main()
{
    _;
    sieve(200001);
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t = 1;
    unordered_map<int, vector<int>> cache;

    cin >> t;
    while (t--)
        s(cache);
    return 0;
}