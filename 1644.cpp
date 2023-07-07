#include <iostream>
#include <vector>
using namespace std;

int N, l, r, Sum, result;
vector<bool> integers;
vector<int> primes;

int main(int argc, char* argv[]) {
    cin >> N;
    integers.resize(N + 1, true);

    integers[1] = false;
    for (int i = 2; i <= N; i++) {
        if (integers[i] == true) {
            primes.push_back(i);
            for (int j = i * 2; j <= N; j += i)
                integers[j] = false;
        }
    }

    if (!primes.empty()) Sum = primes[0];

    while (r < primes.size()) {
        if (Sum < N) {
            r++;
            if (r < primes.size()) Sum += primes[r];
        }
        else if (Sum == N) {
            result++;
            Sum -= primes[l];
            l++;
        }
        else {
            Sum -= primes[l];
            l++;
        }
    }

    cout << result;

    return 0;
}