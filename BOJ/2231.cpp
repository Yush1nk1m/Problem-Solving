#include <iostream>
using namespace std;

inline int SumOfDigits(int number) {
    int result = 0;

    while (number > 0) {
        result += number % 10;
        number /= 10;
    }

    return result;
}

int N;

int main(int argc, char* argv[]) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i + SumOfDigits(i) == N) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
    return 0;
}