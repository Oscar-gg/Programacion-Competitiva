#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define RFOR(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define FORC(cont, it) for (typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for (typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define all(x) x.begin(), x.end()
#define nl << "\n";

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

bool valid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void s()
{
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    for (auto &c : maze)
        cin >> c;
    bool res = false;

    vector<vector<char>> dir(n, vector<char>(m, '.'));

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 'A')
            {
                q.push({i, j});
                dir[i][j] = '0';
                break;
            }
        }
    }
    vector<int> x{1, -1, 0, 0};
    vector<int> y{0, 0, 1, -1};
    vector<char> d{'D', 'U', 'L', 'R'};
    unordered_map<char, char> inv = {{'D', 'D'}, {'U', 'U'}, {'L', 'R'}, {'R', 'L'}};

    unordered_map<char, int> xR = {{'U', 1}, {'D', -1}, {'L', 0}, {'R', 0}};
    unordered_map<char, int> yR = {{'U', 0}, {'D', 0}, {'L', 1}, {'R', -1}};

    pair<int, int> finalP = {-1, -1};

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        if (maze[f.first][f.second] == 'B')
        {
            finalP = f;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int r = f.first + x[i], c = f.second + y[i];
            if (valid(r, c, n, m) && dir[r][c] == '.' && maze[r][c] != '#')
            {
                dir[r][c] = inv[d[i]];
                q.push({r, c});
            }
        }
    }

    // for (auto x : dir)
    // {
    //     for (auto y : x)
    //         cout << y;
    //     cout << endl;
    // }

    if (finalP.first != -1)
    {
        cout << "YES" nl
                string w = "";
        while (dir[finalP.first][finalP.second] != '0')
        {
            w += dir[finalP.first][finalP.second];
            int t = finalP.first, t2 = finalP.second;
            finalP.first += xR[dir[t][t2]];
            finalP.second += yR[dir[t][t2]];
        }
        reverse(w.begin(), w.end());
        cout << w.size() nl;
        cout << w nl
    }
    else
    {
        cout << "NO" nl
    }
}

int main()
{
    _

        int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}