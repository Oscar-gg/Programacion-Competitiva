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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

struct Pos
{
    int x;
    int y;
    int index;
    Pos(int x, int y, int index)
    {
        this->x = x;
        this->y = y;
        this->index = index;
    }
    bool operator<(const Pos &p2) const
    {
        return x < p2.x;
    }
};

double diff(Pos p, Pos p2)
{
    return sqrt(pow(p.x - p2.x, 2) + pow(p.y - p2.y, 2));
}

double solve(int n)
{
    vector<bool> visited(n);

    vector<pair<int, int>> r(n);

    for (auto &x : r)
    {
        int a, b;
        cin >> a >> b;
        x = {a, b};
    }

    priority_queue<pair<double, Pos>> pq;
    Pos st(r[0].first, r[0].second, 0);
    pq.push({0, st});

    while (!pq.empty())
    {
        auto front = pq.top();
        double cost = front.first * -1;
        auto pos = front.second;
        pq.pop();

        if (visited[pos.index])
            continue;
        visited[pos.index] = true;

        if (pos.index == 1)
        {
            return cost;
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                Pos np(r[i].first, r[i].second, i);
                double ncost = max(cost, diff(pos, np));
                pq.push({ncost * -1, np});
            }
        }
    }

    return -1;
}

int main()
{
    _

        int counter = 1;

    while (true)
    {
        int n;
        cin >> n;
        if (!n)
            break;

        double ans = solve(n);

        cout << "Scenario #" << counter++ << "\n";
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        cout << "Frog Distance = " << ans << "\n\n";
    }

    return 0;
}