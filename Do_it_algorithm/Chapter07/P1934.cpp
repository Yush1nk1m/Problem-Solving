#include <iostream>
using namespace std;

int GCD(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int remainder = a % b;
    while (remainder != 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }

    return b;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, A, B;
    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> A >> B;
        cout << A * B / GCD(A, B) << '\n';
    }

    return 0;
}