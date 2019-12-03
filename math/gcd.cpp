#include <iostream>

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


using namespace std;

int main() {

    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;

    return 0;
}