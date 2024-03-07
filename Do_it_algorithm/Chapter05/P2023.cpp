#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> result;
int N;

void InterestingPrime(int number, int digit);
inline bool isPrime(int number);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    InterestingPrime(0, 0);
    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << '\n';

    return 0;
}

void InterestingPrime(int number, int digit) {
    if (digit == N) {
        result.push_back(number);
        return;
    }

    int result = 0;
    number *= 10;
    for (int adder = 1; adder <= 9; adder++)
        if (isPrime(number + adder))
            InterestingPrime(number + adder, digit + 1);
}

inline bool isPrime(int number) {
    if (number == 1) return false;
    for (int divider = 2; divider <= number / 2; divider++)
        if (number % divider == 0) return false;
    return true;
}