#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
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
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define pb push_back

using namespace std;
int find_set(int v, vector<int> &parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void make_set(int v, vector<int> &parent, vector<int> &size) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    sync;

    int n, m;
    cin >> n >> m;

    vector<int> parent(n+1), size(n+1);

    for(int i = 1; i <= n; i++){
        make_set(i, parent, size);
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        union_sets(a, b, parent, size);
    }

    int count = 0;
    vector<pair<int, int>> r;
    for(int i = 1; i <= n; i++){
        if (find_set(1, parent) != find_set(i, parent)){
            count++;
            union_sets(1, i, parent, size);
            r.push_back({1, i});
        }
    }
    cout << count << "\n";

    for(auto x : r){
        cout << x.first << " " << x.second << "\n";
    }
    
    return 0;
}
