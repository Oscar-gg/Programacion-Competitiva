#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve()
{
    string in;
    cin >> in;

    int exp = 0;
    ll denom = 0;
    ll num = 0;
    int n = in.size()-1;

    for(int i = in.size()-1 ; i >= 0; i--){
        int current = in[i] - '0';
        if (current == 0){
            exp++;
            continue;
        }
        ll f = pow(2, n-exp);

        num += pow(3, exp) * current * f;
        denom = pow(2, exp) * f;
        exp++;
    }

    if (num % denom == 0){
        cout << num / denom << '\n';
    } else {
        int div = 0;
        while (num > denom){
            div++;
            num -= denom;
        }
        cout << div << " ";

        int gcdN = gcd(num, denom); 

        cout << num / gcdN << "/" << denom / gcdN;
        cout << '\n';
    }
}

int main()
{
    solve();

    return 0;
}
