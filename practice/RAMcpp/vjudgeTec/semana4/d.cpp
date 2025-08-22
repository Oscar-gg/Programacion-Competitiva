// Rbrgs.cpp
#include <bits/stdc++.h>

#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define aFor(i, a) for (auto &i : a)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

void dfs(ll n, vvll &graph, ll prev, vll &vals, vll &res)
{
    prev += vals[n];
    res[n] += prev;
    for (ll i : graph[n])
    {
        dfs(i, graph, prev, vals, res);
    }
}

void bfs(ll n, vvll &graph, ll prev, vll &vals, vll &res)
{
    queue<pair<ll, ll>> q;
    q.push({1, 0});

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        res[front.first] = front.second + vals[front.first];
        for (ll i : graph[front.first])
        {
            q.push({i, res[front.first]});
        }
    }
}

int main()
{
    sync;
    ll n, q;
    cin >> n >> q;
    ll a, b;
    vvll graph(n + 1);
    vll vals(n + 1, 0);
    for (ll i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].pb(b);
    }
    for (ll i = 0; i < q; i++)
    {
        cin >> a >> b;
        vals[a] += b;
    }
    vll res(n + 1, 0);
    bfs(1, graph, (ll)0, vals, res);
    
    for (ll i = 1; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << " ";
    }

    return 0;
}
