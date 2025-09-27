/**
 * @file 1629_Recursive.cpp
 * @brief 00:11:23
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 어떤 숫자가 k^N이라면, 그 숫자는 k^(N/2) * k^(N/2)로 나타낼 수 있다.
 * 그러나 이 지수 연산을 하나의 문제라고 생각하면 부분 문제가 불필요하게 반복된다.
 * 그러므로 부분 문제를 한 번만 해결할 수 있도록 재귀적으로 해결한다.
 * 이때 지수가 홀수일 경우 k^(N/2)를 두 번 곱하고 k를 한 번 곱하면 된다.
 */

#include <bits/stdc++.h>
using namespace std;

unsigned long long int A, B, C;

unsigned long long int Multiply(unsigned long long int num, unsigned long long int pow, unsigned long long int mod) {
    if (pow == 0) return (1 % mod);
    else if (pow == 1) return (num % mod);
    unsigned long long int res = 1;

    unsigned long long int prior = Multiply(num, pow / 2, mod);
    res = ((prior % mod) * (prior % mod)) % mod;
    
    if (pow % 2 != 0) {
        res *= (num % mod);
        res %= mod;
    }

    return res;
}

int main(int argc, char* argv[]) {
    cin >> A >> B >> C;
    cout << Multiply(A, B, C);
    return 0;
}