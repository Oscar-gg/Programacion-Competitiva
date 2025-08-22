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
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;

int main()
{
    sync;

    int n;
    int t;
    cin >> n >> t;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;
        a[i] = next;
    }

    int ans = 0;
    int currentT = t;
    int currentA = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > t)
        {
            currentT = t;
            currentA = 0;
            continue;
        }
        currentT -= a[i];
        currentA++;
        if (currentT >= 0)
        {
            // cout << currentA << "\n";
            ans = max(currentA, ans);
        }
        else
        {
            while (currentT < 0)
            {
                currentA--;
                currentT += a[i - currentA];
            }
        }
    }

    // cout << "ans: "; 
    cout << ans << "\n";

    return 0;
}