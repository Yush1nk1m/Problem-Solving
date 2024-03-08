#include <iostream>
#include <cmath>
using namespace std;

long long int GCD(long long int A, long long int B) {
    if (A < B) {
        long long int temp = A;
        A = B;
        B = temp;
    }

    long long int remainder = A % B;
    while (remainder != 0) {
        A = B;
        B = remainder;
        remainder = A % B;
    }

    return B;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int A, B;
    cin >> A >> B;

    int digits = GCD(A, B);
    for (int _ = 0; _ < digits; _++)
        cout << 1;

    return 0;
}