#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;

    int trucks, charge,boats, minimum;

    // Minimum capacity of truck
    minimum = D+C;

    // Check if the minimum can be satisified by trucks being at full capacity
    if (minimum%A == 0 ){
        trucks = minimum/A;
    } else {
        trucks = (minimum/A) + 1; 
    }
    // Update the charge variable
    charge = trucks*A;

    // Check the charge after Mester
    charge -= D;

    // Check if exactly boats
    if (charge%B != 0) {
        boats = -1;
    } else { 
        boats = charge/B;
    }

    if (boats == -1) {
        cout << "No solution.";
    } else if(boats == 1 && trucks == 1) {
        cout << "We need " << trucks << " truck and " << boats << " boat.";
    } else if (boats == 1) {
        cout << "We need " << trucks << " trucks and " << boats << " boat.";
    } else if (trucks == 1) {
        cout << "We need " << trucks << " truck and " << boats << " boats.";
    } else { 
        cout << "We need " << trucks << " trucks and " << boats << " boats.";
    }

    cout << '\n';

    return 0;
}