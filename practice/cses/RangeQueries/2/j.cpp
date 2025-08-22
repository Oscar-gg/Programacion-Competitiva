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

int element_count(unordered_map<int, int> &umap)
{
    int ans = 0;
    for (auto c : umap)
    {
        ans += c.second;
    }

    return ans;
}

void update(int index, int l, int r, int pos, int val, vector<int> &seg, vector<unordered_map<int, int>> &bucket, bool insert)
{
    if (l == r)
    {
        if (insert)
        {
            bucket[l][val]++;
            seg[index] = element_count(bucket[l]);
        }
        else
        {
            bucket[l][val]--;
            seg[index] = element_count(bucket[l]);
        }

        return;
    }

    int mid = l + (r - l) / 2;

    if (pos <= mid)
    {
        update(index * 2, l, mid, pos, val, seg, bucket, insert);
    }
    else
    {
        update(index * 2 + 1, mid + 1, r, pos, val, seg, bucket, insert);
    }
    seg[index] = seg[index * 2] + seg[index * 2 + 1];
}

int query(int index, int l, int r, int qL, int qR, vector<int> &seg, vector<unordered_map<int, int>> &bucket)
{

    if (l == qL && r == qR)
    {
        return seg[index];
    }

    int total = 0;
    int mid = l + (r - l) / 2;

    if (qL <= mid)
    {
        total += query(index * 2, l, mid, qL, min(qR, mid), seg, bucket);
    }

    if (qR >= mid + 1)
    {
        total += query(index * 2 + 1, mid + 1, r, max(qL, mid + 1), qR, seg, bucket);
    }

    return total;
}

int out(int min_, int max_, int bucketIndex, vector<unordered_map<int, int>> &bucket)
{
    int ans = 0;
    for (auto val : bucket[bucketIndex])
    {
        if (val.first < min_ || val.first > max_)
            ans += val.second;
    }
    return ans;
}

int getIndex(int num)
{
    return num / 1000;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n), seg(4 * (1e6 + 1));
    vector<unordered_map<int, int>> bucket(1e6 + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        update(1, 0, 1e6, getIndex(a[i]), a[i], seg, bucket, true);
    }

    for (int i = 0; i < q; i++)
    {
        char c;
        cin >> c;

        if (c == '!')
        {
            int k, x;
            cin >> k >> x;
            k--;
            update(1, 0, 1e6, getIndex(a[k]), a[k], seg, bucket, false);
            a[k] = x;
            update(1, 0, 1e6, getIndex(a[k]), a[k], seg, bucket, true);
        }
        else
        {
            int a, b;
            cin >> a >> b;

            int total = query(1, 0, 1e6, getIndex(a), getIndex(b), seg, bucket);

            total -= out(a, b, getIndex(a), bucket);

            if (getIndex(a) != getIndex(b))
            {
                total -= out(a, b, getIndex(b), bucket);
            }
            cout << total << "\n";
        }
    }
}

int main()
{
    _ solve();
    return 0;
}