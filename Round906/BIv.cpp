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

bool isGood(string &s)
{
    char prev = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == prev)
        {
            return false;
        }
        prev = s[i];
    }
    return true;
}

int main()
{
    sync;
    int T;
    cin >> T;
    int n, m;
    string s, t;
    while (T--)
    {
        cin >> n;
        cin >> m;
        cin >> s;
        cin >> t;
        char validRes;
        bool isTGood = true;
        if (isGood(t))
        {
            if (t[0] != t.back())
            {
                isTGood = false;
            }
            else
            {
                validRes = t[0];
            }
        }
        else
        {
            isTGood = false;
        }
        if (!isTGood)
        {
            if (isGood(s))
            {
                // smn
                cout << "Yes" << endl;
            }
            else
            {
                // no
                cout << "No" << endl;
            }
        }
        else
        {
            char prev = s[0];
            bool flag = true;
            for (int i = 1; i < s.size(); i++)
            {
                if (s[i] == prev)
                {
                    if (s[i] == validRes)
                    {
                        // no
                        cout << "No" << endl;
                        flag = false;
                        break;
                    }
                }
                prev = s[i];
            }
            if (flag)
            {
                // smn
                cout << "Yes" << endl;
            }
        }
    }

    return 0;
}