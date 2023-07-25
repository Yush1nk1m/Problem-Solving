#include <iostream>
#include <vector>
using namespace std;

vector<int> coins;
int N, K, result;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    coins.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> coins[i];    
    }

    int i = N - 1;

    while (coins[i] > K) i--;

    while (K > 0) {
        result += K / coins[i];
        K %= coins[i];
        i--;
    }

    cout << result;

    return 0;
}