#include <iostream>
using namespace std;

long long power(long long A, long long B, long long C) {
    if (B > 1) {
        long long subsum = power(A, B / 2, C);
        if (B % 2 == 0) {
            return ((subsum % C) * (subsum % C)) % C;    
        }
        else {
            return ((((subsum % C) * (subsum % C)) % C) * (A % C)) % C;
        }
    }
    else
        return A % C;
}

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    long long A, B, C;
    cin >> A >> B >> C;
    
    cout << power(A, B, C);

    return 0;
}