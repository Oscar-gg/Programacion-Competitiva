// Code by @Oscar-gg

// Problem from:

// Template from: https://www.geeksforgeeks.org/how-to-setup-competitive-programming-in-visual-studio-code-for-c/

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <chrono>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
#ifdef OSCAR_GG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        cout << "Case " << it << ": ";
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;

        if ((n1 > n2 && n1 < n3) || (n1 > n3 && n1 < n2)){
            cout << n1 << "\n";
        } else if ((n2 > n1 && n2 < n3) || (n2 > n3 && n2 < n1)){
            cout << n2 << "\n";
        } else {
            cout << n3 << '\n';
        }
    }
    return 0;
}