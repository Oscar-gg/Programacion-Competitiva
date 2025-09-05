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

// Ox, Tiger, Rabbit, Dragon, Snake, Horse, Goat, Monkey, Rooster, Dog, Pig, Rat,

// Mildred born in previous Dragon year from Bessie
// Gretta born in previous Monkey year from Mildred
// Elsie born in next Ox year from Gretta
// Paulina born in next Dog year from Bessie

/*
Gretta > Elsie > Mildred > Bessie > Paulina


*/

void s()
{
    int n;
    cin >> n;
    unordered_map<string, int> y{{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};
    unordered_map<string, vector<string>> older, younger;

    unordered_map<string, int> umap;
    for (int i = 0; i < n; i++)
    {
        string s, s2, s3, s4, s5, s6, s7, s8;
        cin >> s >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8;
        umap[s] = y[s5];

        if (s4 == "previous")
        {
            older[s8].push_back(s);
            younger[s].push_back(s8);
        }
        else
        {
            older[s].push_back(s8);
            younger[s8].push_back(s);
        }
    }
    unordered_map<string, int> deltas;

    queue<string> q;
    q.push("Elsie");
    unordered_set<string> v;
    deltas["Elsie"] = 0;

    while (!q.empty() && !deltas.count("Bessie"))
    {
        auto f = q.front();
        q.pop();

        if (v.count(f))
            continue;
        v.insert(f);

        for (auto g : older[f])
        {
            q.push(g);
            if (umap[f] > umap[g])
            {
                deltas[g] = deltas[f] - (umap[f] - umap[g]);
            }
            else
            {
                deltas[g] = deltas[f] - (umap[f] + (12 - umap[g]));
            }
        }
        for (auto g : younger[f])
        {
            q.push(g);
            if (umap[g] > umap[f])
            {
                deltas[g] = deltas[f] + umap[g] - umap[f];
            }
            else
            {
                deltas[g] = deltas[f] + (umap[g] + (12 - umap[f]));
            }
        }
    }

    cout << abs(deltas["Bessie"]) << "\n";
}

int main()
{
    _;

    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
        s();
    return 0;
}