#include <iostream>

using namespace std;

int main() {
    int t, f, s, p, c, sum, sum2;

    cin >> t >> f >> s >> p >> c;
    sum = t * 6 + f * 3 + s * 2 + p + c * 2;

    cin >> t >> f >> s >> p >> c;
    sum2 = t * 6 + f * 3 + s * 2 + p + c * 2;
    cout << sum << " " << sum2 << '\n';

    return 0;
}