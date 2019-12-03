#include <iostream>
#include <iomanip>

//Running time: O(log n)

double pow_recursion(double a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    double t = pow_recursion(a, n / 2);
    return t * t * pow_recursion(a, n % 2);
}

double pow(double a, int n) {
    double ret = 1;
    while (n) {
        if (n % 2 == 1) ret *= a;
        a *= a;
        n /= 2;
    }
    return ret;
}

using namespace std;

int main() {

    double a;
    int n;
    cin >> a >> n;

        if (n < 0) {
            a = 1 / a;
            n = abs(n);
        }

    cout << fixed;
    cout << setprecision(5) << pow(a, n);

    return 0;
}