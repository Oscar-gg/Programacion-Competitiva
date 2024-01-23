// Code by @Oscar-gg

// Problem from: https://cses.fi/problemset/task/1190

// https://cp-algorithms.com/data_structures/segment_tree.html#finding-subsegments-with-the-maximal-sum

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

// Maximum subarray sum in [0, n-1]

struct Node
{
    ll total;
    ll maxPrefix;
    ll maxSuffix;
    ll maxSubSegment;
    Node(ll value)
    {
        this->total = value;
        this->maxPrefix = max(value, 0LL);
        this->maxSuffix = max(value, 0LL);
        maxSubSegment = max(value, 0LL);
    }
    Node()
    {
        this->total = 0;
        this->maxPrefix = 0;
        this->maxSuffix = 0;
        this->maxSubSegment = 0;
    }
};

Node mergeNodes(Node n1, Node n2)
{
    Node n;
    n.total = n1.total + n2.total;
    n.maxPrefix = max(n1.maxPrefix, n1.total + n2.maxPrefix);
    n.maxSuffix = max(n2.maxSuffix, n1.maxSuffix + n2.total);
    n.maxSubSegment = max(n1.maxSuffix + n2.maxPrefix, max(n2.maxSubSegment, n1.maxSubSegment));
    return n;
}

void build(ll index, ll left, ll right, vector<Node> &segTree, vector<ll> &values)
{
    if (left <= right)
    {
        if (left == right)
        {
            Node n(values[left]);
            segTree[index] = n;
        }
        else
        {
            ll middle = left + (right - left) / 2;
            build(index * 2, left, middle, segTree, values);
            build(index * 2 + 1, middle + 1, right, segTree, values);
            segTree[index] = mergeNodes(segTree[index * 2], segTree[index * 2 + 1]);
        }
    }
}

void update(ll index, ll position, ll value, ll left, ll right, vector<Node> &segTree)
{
    if (left <= right)
    {
        if (left == right)
        {
            Node n(value);
            segTree[index] = n;
        }
        else
        {
            ll middle = left + (right - left) / 2;
            if (position <= middle)
            {
                update(index * 2, position, value, left, middle, segTree);
            }
            else
            {
                update(index * 2 + 1, position, value, middle + 1, right, segTree);
            }
            segTree[index] = mergeNodes(segTree[index * 2], segTree[index * 2 + 1]);
        }
    }
}

Node compute(int index, int leftQ, int rightQ, int left, int right, vector<Node> &segTree)
{
    // cout << index << " " << leftQ << " " << rightQ << " " << left << " " << right << "\n";
    if (leftQ <= rightQ)
    {
        if (leftQ == left && rightQ == right)
        {
            return segTree[index];
        }

        int middle = left + (right - left) / 2;

        Node leftN = compute(index * 2, leftQ, min(middle, rightQ), left, middle, segTree);
        Node rightN = compute(index * 2 + 1, max(leftQ, middle + 1), rightQ, middle + 1, right, segTree);

        return mergeNodes(leftN, rightN);
    }
    Node n;
    return n;
}

void solve()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> x(n);
    for (auto &element : x)
    {
        cin >> element;
    }

    vector<Node> segTree(4 * n);

    build(1, 0, n - 1, segTree, x);

    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        update(1, a - 1, b, 0, n - 1, segTree);
        cout << segTree[1].maxSubSegment << "\n";
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