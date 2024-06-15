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


#define print(x) cout << x << endl;

class Shipping {

public:
    string info;

    Shipping(string info) {
        this->info = info;
    }

    string virtual getInfo(){
        return info;
    }
};

class Package: public Shipping {
    public:
    int cost;
    
    Package(string info, int cost): Shipping(info) {
        this->cost = cost;
    }

    string getInfo(){
        return this->info + " " + to_string(cost);
    }
};

class Envelope: public Shipping {
    public:
    int weight;
    
    Envelope(string info, int weight): Shipping(info) {
        this->weight = weight;
    }

    string getInfo(){
        return this->info + " " + to_string(weight);
    }
};
 
int main() { _

    // vector<Shipping*> shippings;
    // shippings.push_back(new Package("Package", 10));
    // shippings.push_back(new Envelope("Envelope", 5));
    // shippings.push_back(new Package("Package", 20));
    // shippings.push_back(new Envelope("Envelope", 10));


    // for(auto x : shippings){
    //     string next = x->getInfo();
    //     cout << next << endl;
    // }

    print("Hola mundo");

    return 0;
}