#include <bits/stdc++.h>
using namespace std;

int toBit(int n)
{
    return 1 << n;
}

bool bitSet(int i, int n)
{
    return i & toBit(n);
}

string sbits(int n, int k)
{
    string st = "";
    for (int i = k; i >= 0; i--)
    {
        if (n & (1 << i))
            st += "1";
        else
            st += "0";
    }
    return st;
}

void s()
{
    int n, k;
    cin >> n >> k;

    vector<vector<vector<int>>> m(n, vector<vector<int>>(n, vector<int>(n)));

    for (int i = 0; i < k; i++)
    {
        vector<int> a(3);
        for (auto &v : a)
        {
            cin >> v;
            v--;
        }

        sort(a.begin() + 1, a.end());

        // m[a[0]][{a[1], a[2]}]++;
        m[a[0]][a[1]][a[2]]++;
    }

    int max_ = 0;
    int rep = 0;

    // int lim = 1 << n;
    // cout << lim << "\n";

    for (int i = 1; i < 1 << n; i++)
    {
        int cur = 0;
        // cout << "i: " << i << endl;
        // cout << sbits(i, n) << "\n";

        for (int j = 0; j < n; j++)
        {
            if (!bitSet(i, j))
                continue;

            for (int ki = 0; ki < n; ki++)
            {
                if (bitSet(i, ki))
                    continue;
                for (int l = ki + 1; l < n; l++)
                {
                    if (!bitSet(i, l))
                    {
                        cur += m[j][ki][l];
                    }
                }
            }
        }

        if (cur > max_)
        {
            max_ = cur;
            rep = 1;
        }
        else if (cur == max_)
        {
            rep++;
        }
    }

    cout << max_ << " " << rep << "\n";
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