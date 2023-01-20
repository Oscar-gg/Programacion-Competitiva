// Code by @Oscar-gg

// Problem from:

// Template from: https://www.geeksforgeeks.org/how-to-setup-competitive-programming-in-visual-studio-code-for-c/

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
#define dbg(x) cout << #x << " = " << x << ln
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

short int mapH[100][100];
short int costM[100][100];
bool visited[100][100];

vector<unordered_set<int>> mapT[100][100];

int n, m;

pair<int, int> getNearest()
{
    int min = INT32_MAX;
    int r = -1, c = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && costM[i][j] < min)
            {
                min = costM[i][j];
                r = i;
                c = j;
            }
        }
    }
    // cout << "r: " << r << " c: " << c << '\n';

    return {r, c};
}

void visitN(int r, int c)
{
    visited[r][c] = true;
    vector<int> indexR{-1, 0, 0, 1};
    vector<int> indexC{0, -1, 1, 0};

    for (int i = 0; i < 4; i++)
    {
        int nRow = r + indexR[i];
        int nCol = c + indexC[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m)
        {
            if (!visited[nRow][nCol])
            {
                for (auto x : mapT[r][c])
                {
                    unordered_set<int> copy = x;
                    copy.insert(mapH[nRow][nCol]);
                    if (costM[nRow][nCol] > copy.size())
                    {
                        costM[nRow][nCol] = copy.size();
                        mapT[nRow][nCol].clear();
                        mapT[nRow][nCol].push_back(copy);
                    }
                    else if (costM[nRow][nCol] == copy.size())
                    {
                        mapT[nRow][nCol].push_back(copy);
                    }
                }
            }
        }
    }

    mapT[r][c].clear();
}

int dijkstra(int sr, int sc, int tr, int tc)
{
    costM[sr][sc] = 1;

    unordered_set<int> uset;
    uset.insert(mapH[sr][sc]);
    mapT[sr][sc].push_back(uset);

    pair<int, int> tar = getNearest();

    while (tar.first != tr || tar.second != tc)
    {
        visitN(tar.first, tar.second);
        tar = getNearest();
    }
    /*
    cout << "tr: " << tr << " "
         << "tc: " << tc << "\n";
    */
    return costM[tr][tc];
}

void solve()
{
    // int n, m;
    cin >> n >> m;
    int sr, sc;
    cin >> sr >> sc;
    sr--;
    sc--;
    int tr, tc;
    cin >> tr >> tc;
    tr--;
    tc--;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int curr;
            cin >> curr;
            mapH[i][j] = curr;
        }
    }

    

    int ans = dijkstra(tr, tc, sr, sc);

    cout << ans << '\n';
}

int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_cin();
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            mapH[i][j] = 10;
            costM[i][j] = 10;
            visited[i][j] = false;
        }
    }

    solve();

    return 0;
}