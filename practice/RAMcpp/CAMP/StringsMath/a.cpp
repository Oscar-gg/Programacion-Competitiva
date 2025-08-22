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

class TrieNode
{
public:
    vector<TrieNode *> childrens;
    bool isEndOfWord;
    int sizeOfChilds;
    TrieNode()
    {
        childrens = vector<TrieNode *>(26, nullptr);
        isEndOfWord = false;
        sizeOfChilds = 0;
    }
    void insertWord(string s, int i = 0)
    {
        if (s.size() == i)
        {
            isEndOfWord = true;
            return;
        }
        if (childrens[s[i] - 'a'] == nullptr)
        {
            childrens[s[i] - 'a'] = new TrieNode();
            sizeOfChilds++;
        }
        childrens[s[i] - 'a']->insertWord(s, i + 1);
    }
};

void TraverseTrie(TrieNode *node, string cur)
{
    if (node->isEndOfWord)
        cout << cur << endl;

    for (int i = 0; i < 26; i++)
    {
        if (node->childrens[i] != nullptr)
        {
            // cout << "traversing " << (char)(i + 'a') << endl;
            TraverseTrie(node->childrens[i], cur + (char('a' + i)) );
        }
    }
}

void findW(string &s, int index, int count, TrieNode *node, bool &found, TrieNode *root, string cur)
{
    
    if (count > 2 || found){
        // if (count > 2)
        //     cout << "count is 2 " << s << endl;
        return;
    }


    // if (cur == "abab"){
    //     cout << "FOUND\n";
    //     cout << (node == root) << "\n";
    //     cout << index << " " << s.size() << endl;
    //     cout << count << "\n";
    // }

    // if (node == root){
    //     cout << "node is root\n";
    // }

    if (node == root && index == s.size() && count == 2)
    {
        found = true;
        // cout << "cur: " << cur << "\n";
        // dbg(s);
        return;
    } 
    
    // cout << cur << " " << count << " " << index << " "<< s << "\n";

    // if (cur == "aba"){
    //     cout << "next: ";
    //     if (node->childrens[s[index] - 'a'] != nullptr){
    //         cout << "yes\n";
    //     } else {
    //         cout << "np\n";
    //     }
    // }

    if (node->isEndOfWord)
    {
        findW(s, index, count + 1, root, found, root, cur + s[index]);
        // dbg(cur + s[index]);
        if (found)
            return;
    }

    if (index == s.size())
        return;

    // cout << s[index] << " " << s[index] - 'a' << "\n";
    if (node->childrens[s[index] - 'a'] != nullptr)
    {
        findW(s, index+1, count, node->childrens[s[index] - 'a'], found, root, cur + s[index]);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    TrieNode *root = new TrieNode();

    for (auto &x : s)
    {
        cin >> x;
        root->insertWord(x);
    }

    // TraverseTrie(root, "");
    // return;

    for (auto x : s)
    {
        bool found = false;
        findW(x, 0, 0, root, found, root, "");
        if (found)
            cout << "1";
        else
            cout << "0";
        // break;
    }

    cout << "\n";
}

int main()
{
    _ int t;
    cin >> t;
    // t = 1;
    while (t--)
        solve();
    return 0;
}