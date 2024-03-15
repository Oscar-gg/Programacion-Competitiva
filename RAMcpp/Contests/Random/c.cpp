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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

string delSpaces(string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

bool fc = true;

void solve()
{
    if (fc)
    {
        fc = false;
    }
    else
    {
        cout << endl;
    }
    vector<int> a;
    unordered_map<int, int> parent;

    while (true)
    {
        string line;
        getline(cin, line);
        if (line == "")
            break;
        a.push_back(stoi(delSpaces(line)));
    }

    vector<int> is;

    for (int i = 0; i < a.size(); i++)
    {
        int index = lower_bound(is.begin(), is.end(), a[i]) - is.begin();
        if (index == 0)
            parent[a[i]] = -1;
        else {
            parent[a[i]] = is[index-1];
        }

        if (index == is.size())
            is.push_back(a[i]);
        else
            is[index] = a[i];
    }

    cout << "Max hits: " << is.size() << "\n";

    vector<int> rec;
    int cur = is.back();
    while (parent[cur] != -1)
    {
        rec.push_back(cur);
        cur = parent[cur];
    }
    rec.push_back(cur);
    
    reverse(rec.begin(), rec.end());
    
    for(auto x : rec){
        cout << x << "\n";
    }

}

void generator()
{
    int total = 10;

    cout << total << "\n\n";

    int lowerBound = 0, upperBound = 10000000;

    // Seed the random number generator with current time
    srand(time(0));

    for (int i = 0; i < total; i++)
    {
        int n = rand() % 30 + 10;
        for (int i = 0; i < n; ++i)
        {
            int randomNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;
            cout << randomNumber << "\n";
        }
        cout << "\n";
    }
}

int main()
{
    _
    // generator();
        string line;
    getline(cin, line);
    int c = stoi(delSpaces(line));
    getline(cin, line);

    for (int i = 0; i < c; i++)
        solve();

    return 0;
}