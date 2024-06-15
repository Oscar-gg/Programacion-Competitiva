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

int find_set(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void make_set(int v, vector<int> &parent, vector<int> &size)
{
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size)
{
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    _;

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1), size(n + 1);

    for (int i = 1; i <= n; i++)
    {
        make_set(i, parent, size);
    }

    int components = n;
    int maxS = 1;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (find_set(a, parent) != find_set(b, parent))
        {
            components--;
            union_sets(a, b, parent, size);
            maxS = max(maxS, size[find_set(a, parent)]);
        }
        cout << components << " " << maxS << "\n";

    }

    return 0;
}