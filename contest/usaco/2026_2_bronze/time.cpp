#include <bits/stdc++.h>
using namespace std;

void s(int k)
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string t = "";

    bool f = false;

    for (int i = n - 1; i >= 0; i--)
    {
        t += f ? s[i] == 'O' ? 'M' : 'O' : s[i];

        if (t.back() == 'O')
            f = !f;
    }

    reverse(t.begin(), t.end());

    cout << "YES\n";

    if (k)
        cout << t << "\n";
}

int main()
{
    int t, k;
    cin >> t >> k;

    while (t--)
        s(k);

    return 0;
}