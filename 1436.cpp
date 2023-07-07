#include <iostream>
#include <string>
using namespace std;

int N, i = 1, result = 666;

bool isIncluded(int number) {
    int acc6 = 0;
    int remainder;
    while (number > 0) {
        remainder = number % 10;
        if (remainder == 6) acc6++;
        else acc6 = 0;

        if (acc6 == 3) return true;
        number /= 10;
    }
    return false;
}

int main(int argc, char* argv[]) {
    cin >> N;

    while (i < N) {
        ++result;
        if (isIncluded(result)) i++;
    }

    cout << result;

    return 0;
}