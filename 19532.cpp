#include <iostream>
using namespace std;

int a, b, c, d, e, f, x, y;

int main(int argc, char* argv[]) {
    cin >> a >> b >> c >> d >> e >> f;
    
    for (x = -999; x <= 999; x++) {
        for (y = -999; y <= 999; y++) {
            if (a * x + b * y == c && d * x + e * y == f) {
                cout << x << ' ' << y;
                return 0;
            }
        }
    }
}