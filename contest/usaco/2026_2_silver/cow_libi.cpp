#include <bits/stdc++.h>

using namespace std;

void s(int c)
{
    int n;
    cin >> n;
    string s, s2;
    cin >> s >> s2;

    int cj = 0,
        cj2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'J')
            cj++;
        if (s2[i] == 'J')
            cj2++;
    }

    if (cj == cj2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    int t, c;
    cin >> t >> c;
    while (t--)
        s(c);
    return 0;
}