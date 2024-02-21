// Code by @Oscar-gg
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPSQ(long long int num)
{
    if ((num == sqrt(num) * sqrt(num)))
        return true;
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<long long int> a(n);
    long long int counter = 1;
    long long int i = 0;

    while (i != n)
    {
        for (i = 0; i < n; i++)
        {
            if (a[i] == 0 || isPSQ(a[i] + counter))
            {
                a[i] = counter;
                counter++;
                i = 0;
                break;
            }
        }
    }

    cout << counter - 1 << "\n";
}


int main()
{
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}