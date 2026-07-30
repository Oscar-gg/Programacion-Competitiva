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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _                                                                      \
  ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0),           \
      cout.precision(15);
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define RFOR(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define FORC(cont, it)                                                         \
  for (typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it)                                                        \
  for (typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define all(x) x.begin(), x.end()
#define nl << "\n"
#define MAXN 10
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template <typename T> istream &operator>>(istream &in, vector<T> &a) {
  for (auto &x : a)
    in >> x;
  return in;
};
template <typename T> ostream &operator<<(ostream &out, vector<T> &a) {
  for (auto &x : a)
    out << x << ' ';
  return out;
};

int cons(int a, int b, vector<int> &w, int s, vector<int> &cache) {
  int r = (~(a ^ b)) & ((1 << s) - 1);

  return cache[r];
}

void compute_res(unordered_map<int, int> &uset, int &tar, vector<int> &w,
                 vector<pair<int, int>> &res_cont, int s, vector<int> &cache) {
  for (auto &v : uset) {
    int c = cons(v.first, tar, w, s, cache);
    res_cont.push_back({c, v.second});
  }
}

int tr(string &t) {
  int res = 0;

  for (int i = 0; i < t.size(); i++) {
    if (t[t.size() - i - 1] == '1') {
      res += 1 << i;
    }
  }
  return res;
}

void s() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n);
  cin >> a;
  unordered_map<int, int> uset;
  for (int i = 0; i < m; i++) {
    string x;
    cin >> x;
    uset[tr(x)]++;
  }

  vector<int> queries;
  vector<int> tar;

  for (int i = 0; i < q; i++) {
    string s;
    int cost;
    cin >> s;
    cin >> cost;
    queries.push_back(cost);
    tar.push_back(tr(s));
  }

  unordered_map<int, vector<pair<int, int>>> res;
  vector<int> wu_score(1 << n, 0);

  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        wu_score[i] += a[n - 1 - j];
      }
    }
  }

  for (int i = 0; i < q; i++) {
    if (res.count(tar[i])) {
      continue;
    }

    compute_res(uset, tar[i], a, res[tar[i]], n, wu_score);
    sort(all(res[tar[i]]));

    for (int j = 1; j < res[tar[i]].size(); j++) {
      res[tar[i]][j].second += res[tar[i]][j - 1].second;
    }

    // for (int j = 0; j < res[tar[i]].size(); j++) {
    //   cout << res[tar[i]][j].first << " (" << res[tar[i]][j].second << "), ";
    // }
    //
    // cout << "\n";
    // cout << res[tar[i]] << "\n";
  }

  for (int i = 0; i < q; i++) {
    // cout << res[tar[i]] << "\n";
    //
    pair<int, int> ptar{queries[i], 1e9};

    int index = upper_bound(res[tar[i]].begin(), res[tar[i]].end(), ptar) -
                res[tar[i]].begin();
    index--;
    if (index < 0) {
      cout << 0 << "\n";
    } else {
      cout << res[tar[i]][index].second << "\n";
    }
  }
}

int main() {
  _;

  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  int t = 1;
  // cin >> t;
  while (t--)
    s();
  return 0;
}
