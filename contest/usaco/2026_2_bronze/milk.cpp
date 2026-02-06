#include <bits/stdc++.h>
using namespace std;

#define ll long long

void s2(ll t, vector<ll> &pc)
{
    ll cost = pc[31];
    ll cur = 0;
    ll curCost = 0;

    for (int i = 31; i >= 0; i--)
    {

        ll pos = cur | (1ll << i);
        ll posCost = curCost + pc[i];

        // cout << pos << " " << posCost << "\n";

        if (pos >= t)
        {
            if (posCost < cost)
            {
                // cout << "curAns: " << posCost << "\n";
                cost = posCost;
            }
        }
        if (t & (1ll << i))
        {
            // t -= 1ll << i;
            cur = pos;
            curCost = posCost;
        }
    }

    cout << cost << "\n";
}

void s()
{
    int n, q;
    cin >> n >> q;

    vector<ll> c(n), pc(32);

    for (auto &v : c)
        cin >> v;

    for (int i = n - 2; i >= 0; i--)
    {
        if (c[i] > c[i + 1])
            c[i] = c[i + 1];
    }

    pc[0] = c[0];
    for (int i = 1; i < 32; i++)
    {
        pc[i] = pc[i - 1] * 2;

        if (i < c.size())
            pc[i] = min(pc[i], c[i]);
    }

    while (q--)
    {
        int t;
        cin >> t;
        s2(t, pc);
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
        s();

    return 0;
}