#include <iostream>
using namespace std;

#define MOD 1000000000

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    if (N == 1)
        cout << 0;
    else {
        long long int prior = 0, current = 1;
        for (int i = 3; i <= N; i++) {
            long long int priorTemp = prior;
            prior = current;
            current = (((i - 1) % MOD) * ((priorTemp + prior) % MOD)) % MOD;
        }

        cout << current;
    }

    return 0;
}