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
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 

void dfs(int i, int j, int count, int &maxC, vector<vector<bool>> &board){
    // cout << i << " " << j << endl;
    maxC = max(maxC, count);

    if (i >= board.size())
        return;

    if (j >= board[i].size()){
        dfs(i+1, 0, count, maxC, board);
        return;
    }

    if (board[i][j]){
        dfs(i, j+1, count, maxC, board);
        return;
    }
        
    
    // Val H
    if (j + 1 < board[i].size() && (!board[i][j] && !board[i][j+1])){
        board[i][j] = true;
        board[i][j+1] = true;
        dfs(i, j+2, count+1, maxC, board);
        board[i][j] = false;
        board[i][j+1] = false;
    }

    if (i + 1 < board.size() && (!board[i][j] && !board[i+1][j])){
        board[i][j] = true;
        board[i+1][j] = true;
        dfs(i, j+1, count+1, maxC, board);
        board[i][j] = false;
        board[i+1][j] = true;
    }

    dfs(i, j+1, count, maxC, board);

    // Val V
}

int main() { _

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> board(n, vector<bool> (m));

    int ans = 0;

    dfs(0, 0, 0, ans, board);

    cout << ans << "\n";

    return 0;
}