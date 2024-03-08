#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n;
    cin >> n;

    long long int euler = n;
    for (long long int prime = 2; prime <= sqrtl(n); prime++) {
        if (n % prime == 0) {
            euler -= (euler / prime);
            while (n % prime == 0)
                n /= prime;
        }
    }

    if (n > 1)
        euler -= (euler / n);

    cout << euler;

    return 0;
}