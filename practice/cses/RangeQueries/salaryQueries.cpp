// Code by @Oscar-gg

// Solved w / editorial

// Problem from: https://cses.fi/problemset/task/1144/

// Template from: https://www.geeksforgeeks.org/how-to-setup-competitive-programming-in-visual-studio-code-for-c/

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void build(int position, int left, int right, vector<int> &buckets, vector<int> &segTree)
{

    if (left <= right)
    {
        if (left == right)
        {
            segTree[position] = buckets[left];
            return;
        }
        int middle = left + (right - left) / 2;
        build(position * 2, left, middle, buckets, segTree);
        build(position * 2 + 1, middle + 1, right, buckets, segTree);
        segTree[position] = segTree[position * 2] + segTree[position * 2 + 1];
    }
}

// Pass values as original / 100
void update(int position, int value, bool add, int left, int right, vector<int> &segTree)
{
    if (left <= right)
    {
        if (left == right)
        {
            if (add)
            {
                segTree[position]++;
            }
            else
            {
                segTree[position]--;
            }
            return;
        }

        int middle = left + (right - left) / 2;

        if (value <= middle)
        {
            update(position * 2, value, add, left, middle, segTree);
        }
        else
        {
            update(position * 2 + 1, value, add, middle + 1, right, segTree);
        }
        segTree[position] = segTree[position * 2] + segTree[position * 2 + 1];
    }
}

int compute(int position, int leftQ, int rightQ, int left, int right, vector<int> &segTree)
{
    if (leftQ <= rightQ)
    {
        if (leftQ == left && rightQ == right)
        {
            return segTree[position];
        }
        int middle = left + (right - left) / 2;
        int amountLeft = compute(position * 2, leftQ, min(rightQ, middle), left, middle, segTree);
        int amountRight = compute(position * 2 + 1, max(middle + 1, leftQ), rightQ, middle + 1, right, segTree);
        return amountLeft + amountRight;
    }

    return 0;
}

int getBucket(int n)
{
    if (n % 100 == 0)
        n--;

    return n / 100;
}

int calc(int a, int b, map<int, int> &umap)
{
    int total = 0;
    auto lb = umap.lower_bound(a);

    for (auto i = lb; i != umap.end() && i->first <= b; i++)
    {
        total += i->second;
    }

    return total;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    map<int, int> umap;
    vector<int> segTree(1e7 * 4);
    vector<int> buckets(1e7); // initial values
    vector<int> employees(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        buckets[getBucket(x)]++;
        umap[x]++;
        employees[i] = x;
    }

    build(1, 0, 1e7 - 1, buckets, segTree);

    for (int i = 0; i < q; i++)
    {
        char c;
        cin >> c;

        if (c == '!')
        {
            int a, b;
            cin >> a >> b;
            a--;
            umap[employees[a]]--;
            update(1, getBucket(employees[a]), false, 0, 1e7 - 1, segTree);

            employees[a] = b;
            umap[b]++;
            update(1, getBucket(employees[a]), true, 0, 1e7 - 1, segTree);
        }
        else
        {
            int a, b;
            cin >> a >> b;

            int lbucket = getBucket(a);
            int rbucket = getBucket(b);

            int ans = calc(a, min((lbucket + 1) * 100, b), umap);

            ans = ans + ((lbucket != rbucket) ? calc(max(a, rbucket * 100 + 1), b, umap) : 0);

            ans = ans + compute(1, lbucket + 1, rbucket - 1, 0, 1e7 - 1, segTree);

            cout << ans << '\n';
        }
    }
}

int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now();
#endif
    fast_cin();
    solve();
#ifdef OSCAR_GG
    auto end = chrono::high_resolution_clock::now();
    double executionTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    executionTime *= 1e-6;
    cout << "Execution Time: " << fixed << executionTime << setprecision(6);
    cout << " ms\n";
#endif
    return 0;
}

// TLE
// void solve()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<int> p(n);

//     for (auto &x : p)
//     {
//         cin >> x;
//     }

//     multiset<int> ordered(p.begin(), p.end());

//     for (int i = 0; i < q; i++)
//     {
//         char c;
//         int a, b;
//         cin >> c >> a >> b;

//         if (c == '!')
//         {
//             a--;
//             ordered.erase(ordered.find(p[a]));
//             p[a] = b;
//             ordered.insert(p[a]);
//         }
//         else
//         {
//             auto amount = distance(ordered.lower_bound(a), ordered.upper_bound(b));
//             cout << amount << "\n";
//         }
//     }
// }