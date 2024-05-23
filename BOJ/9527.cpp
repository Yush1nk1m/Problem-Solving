#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

static unsigned long long int A, B;
static unsigned long long int bitNumbers[54 + 1];           // 비트별 숫자 개수를 저장할 배열

inline void InitializeBitArray();
inline unsigned long long int CountOnes(unsigned long long int);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    InitializeBitArray();

    cout << CountOnes(B) - CountOnes(A - 1);

    return 0;
}

inline void InitializeBitArray() {
    bitNumbers[1] = 1;
    for (int i = 2; i <= 54; i++) {
        bitNumbers[i] = (1ULL << (i - 1)) + (2 * bitNumbers[i - 1]);
    }
}

inline unsigned long long int CountOnes(unsigned long long int number) {
    unsigned long long int count = 0;

    if (1ULL & number) count++;
    for (int power = 54; power >= 1; power--)
        if ((1ULL << power) & number) {
            count += bitNumbers[power] + (number - (1ULL << power) + 1);
            number -= (1ULL << power);
        }
    
    return count;
}