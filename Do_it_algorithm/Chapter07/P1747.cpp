#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> Eratosthenes(vector<bool>& sieve, int upperbound);
bool IsPalindrome(int number);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<bool> sieve;
    // 어떤 자연수 N과 2N 사이에는 소수가 하나 이상 존재한다.
    vector<int> primes = Eratosthenes(sieve, 2000000);

    for (int prime : primes) {
        if (prime >= N && IsPalindrome(prime)) {
            cout << prime;
            break;
        }
    }

    return 0;
}

vector<int> Eratosthenes(vector<bool>& sieve, int upperbound) {
    vector<int> primes;
    sieve.resize(upperbound + 1, true);
    for (int n = 2; n <= upperbound; n++) {
        if (sieve[n]) {
            for (int multiple = n * 2; multiple <= upperbound; multiple += n)
                sieve[multiple] = false;
            primes.push_back(n);
        }
    }

    return primes;
}

bool IsPalindrome(int number) {
    int digit = 1;
    int divider = 10;

    while (number / divider > 0) {
        digit++;
        divider *= 10;
    }

    bool isPalindrome = true;
    stack<int> stk;
    divider = 10;
    
    for (int _ = 0; _ < digit / 2; _++) {
        stk.push(number % 10);
        number /= 10;
    }
    
    if (digit % 2 != 0) number /= 10;
    
    for (int _ = 0; _ < digit / 2; _++) {
        int remainder = number % 10;
        if (remainder != stk.top()) {
            isPalindrome = false;
            break;
        }
        
        stk.pop();
        number /= 10;
    }

    return isPalindrome;
}