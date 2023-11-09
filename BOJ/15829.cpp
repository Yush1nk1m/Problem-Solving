#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long H, r;
int L;
string line;

int main(int argc, char* argv[]) {
    cin >> L;
    cin >> line;

    for (int i = 0; i < line.length(); i++) {
        r = line[i] - 96;
        for (int j = 0; j < i; j++) {
            r *= 31;
            r %= 1234567891;
        }
        H += r;
        H %= 1234567891;
    }

    cout << H;

    return 0;
}