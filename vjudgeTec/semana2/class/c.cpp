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

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    priority_queue<ll> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // pq.push(a[i]);
        pq.push(a[i] * -1);
    }

    ll ans = 0;

    if (pq.size() == 1)
    {
        cout << "0\n";
        // cout << pq.top() << "\n";
        return;
    }

    while (!pq.empty())
    {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ll sum = a + b;
        sum *= -1;
        ans += sum;
        if (pq.empty())
            break;
        pq.push(sum * -1);
        // pq.push(sum);
    }
    
    cout << ans << "\n";
}

int main()
{
    sync;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}