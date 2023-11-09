#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> primes;
vector<bool> eratosthenes;
int M, N, recent_prime = 2;

int main(int argc, char* argv[]) {
    cin >> M >> N;

    eratosthenes.resize(2 * N, true);

    while (recent_prime <= N) {

        if (recent_prime >= M) primes.push(recent_prime);

        int i;

        for (i = recent_prime * 2; i <= N; i += recent_prime) {
            eratosthenes[i] = false;
        }

        for (i = recent_prime + 1; i <= N && eratosthenes[i] == false; i++)
            ;
        
        if (eratosthenes[i] == false) break;
        else recent_prime = i;
    }

    while (!primes.empty()) {
        cout << primes.front() << '\n';
        primes.pop();
    }
}