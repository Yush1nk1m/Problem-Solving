#include <iostream>
using namespace std;

#define MOD 1000000007

static inline unsigned long long int InverseElement(unsigned long long int number);
static unsigned long long int ModularPower(unsigned long long int number, unsigned long long int power);
static inline unsigned long long int GCD(unsigned long long int a, unsigned long long int b);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    unsigned long long int result = 0;

    for (int _ = 0; _ < M; _++) {
        unsigned long long int N, S;
        cin >> N >> S;

        unsigned long long int gcd = GCD(N, S);
        N /= gcd;
        S /= gcd;

        result += (((InverseElement(N) % MOD) * (S % MOD)) % MOD);
        result %= MOD;
    }

    cout << result;

    return 0;
}

static inline unsigned long long int InverseElement(unsigned long long int number) {
    return ModularPower(number, MOD - 2);
}

static unsigned long long int ModularPower(unsigned long long int number, unsigned long long int power) {
    if (power == 1)
        return number % MOD;

    if (power % 2 == 0) {
        unsigned long long int subSolution = ModularPower(number, power / 2);
        return ((subSolution % MOD) * (subSolution % MOD)) % MOD;
    } else {
        unsigned long long int subSolution = ModularPower(number, power / 2);
        return ((((subSolution % MOD) * (subSolution % MOD)) % MOD) * (number % MOD)) % MOD;
    }
}

static inline unsigned long long int GCD(unsigned long long int a, unsigned long long int b) {
    if (a < b) {
        unsigned long long int temp = a;
        a = b;
        b = temp;
    }

    while (a % b != 0) {
        unsigned long long int remainder = a % b;
        a = b;
        b = remainder;
    }

    return b;
}