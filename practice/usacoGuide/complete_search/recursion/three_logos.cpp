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

struct Comb
{
    int logo = -1;
    bool flip = false;
};

bool usedL(vector<Comb> &cur, int t)
{
    for (int i = 0; i < cur.size(); i++)
    {
        if (cur[i].logo == t)
            return true;
    }
    return false;
}

void exploreV(int w, int &h, vector<pair<int, int>> &logos, vector<Comb> &used, vector<Comb> &cur)
{
    if (used.size() > 0)
        return;

    if (cur.size() == logos.size())
    {
        if (w == h)
        {
            used = cur;
            return;
        }
    }

    for (int i = 0; i < logos.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            bool v = j % 2 == 0;

            pair<int, int> temp = logos[i];

            if (v)
            {
                swap(temp.first, temp.second);
            }

            if (cur.size() > 0 && temp.first != w)
                continue;

            if (!usedL(cur, i))
            {
                Comb cmb;
                cmb.logo = i;
                cmb.flip = v;
                cur.push_back(cmb);
                h += temp.second;
                exploreV(temp.first, h, logos, used, cur);
                if (used.size() > 0)
                    return;
                h -= temp.second;
                cur.pop_back();
            }
        }
    }
}

void s()
{
    vector<pair<int, int>> logos(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> logos[i].first >> logos[i].second;
    }
    vector<Comb> ans, cur;

    int n = 0;

    exploreV(0, n, logos, ans, cur);

    if (ans.size() > 0)
    {
        vector<string> f;

        cout << n << "\n";

        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i].flip)
            {
                swap(logos[ans[i].logo].first, logos[ans[i].logo].second);
            }

            while (logos[ans[i].logo].second--)
            {

                f.push_back(string(logos[ans[i].logo].first, 'A' + ans[i].logo));
            }
        }

        for (auto x : f)
        {
            cout << x << "\n";
        }
    }
    else
    {
        vector<int> permut{0, 1, 2};

        do
        {
            for (int i = 0; i < (1 << logos.size()); i++)
            {
                vector<pair<int, int>> cl = logos;
                vector<bool> flip(3);
                for (int j = 0; j < logos.size(); j++)
                {
                    if (i & (1 << j))
                    {
                        flip[permut[j]] = true;
                        swap(cl[permut[j]].first, cl[permut[j]].second);
                    }
                }
                if (cl[permut[1]].first != cl[permut[2]].first)
                    continue;

                int h = cl[permut[0]].first + cl[permut[1]].first;

                if (cl[permut[1]].second + cl[permut[2]].second != cl[permut[0]].second)
                    continue;

                int w = cl[permut[0]].second;

                if (h == w)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        Comb com;
                        com.flip = flip[permut[i]];
                        com.logo = permut[i];
                        ans.push_back(com);
                    }
                    break;
                }
            }

        } while (ans.size() < 1 && next_permutation(all(permut)));

        if (ans.size() > 0)
        {
            vector<string> f;

            for (int i = 0; i < 3; i++)
            {
                if (ans[i].flip)
                {
                    swap(logos[ans[i].logo].first, logos[ans[i].logo].second);
                }
            }
            cout << logos[ans[0].logo].second << "\n";

            while (logos[ans[0].logo].first--)
            {
                f.push_back(string(logos[ans[0].logo].second, 'A' + ans[0].logo));
            }

            while (logos[ans[1].logo].first--)
            {
                string left(logos[ans[1].logo].second, 'A' + ans[1].logo);
                string right(logos[ans[2].logo].second, 'A' + ans[2].logo);

                f.push_back(left + right);
            }

            for (auto x : f)
            {
                cout << x << "\n";
            }
        }
        else
        {
            cout << "-1\n";
        }
    }
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