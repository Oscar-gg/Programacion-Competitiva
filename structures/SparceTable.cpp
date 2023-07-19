#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100005;
const int LOG = 17;

int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is min among a[i... i+2^j-1]
                   // i is the starting position, [j] indicates size of segment.
                   // The intervals are calculated until i + (1 << k - 1) < n
                   // because otherwise the range calculated would go out of bounds.

int query(int L, int R)
{
    int length = R - L + 1;

    // Get power of 2 of number. Use it to determine size of segment to grab.
    // Leading zeros are used as a way to compute size.
    int k = 31 - __builtin_clz(length);
    return min(m[L][k], m[R - (1 << k) + 1][k]);
}

int main()
{

#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now();
#endif
    // Sparce table. Used for o(1) queries of min, max, gcd in specific range.
    // Requires O(Nlog(N)) for preprocessing.
    int n;
    cin >> n;

    // Read input
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i][0] = a[i];
    }
    // Preprocessing
    for (int k = 1; k < LOG; k++)
    {
        for (int i = 0; i + (1 << k) - 1 < n; i++)
        {
            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < LOG; j++){
            cout << m[i][j] << " ";
        }
        cout << '\n';
    }

    // Answer queries
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << "\n";
    }

    return 0;
}
