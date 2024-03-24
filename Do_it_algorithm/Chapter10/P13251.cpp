#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    int totalNumRocks = 0;
    vector<int> rocks(M);
    for (int i = 0; i < M; i++) {
        cin >> rocks[i];
        totalNumRocks += rocks[i];
    }

    int K;
    cin >> K;

    long double result = 0.0;
    for (int numRock : rocks) {
        if (numRock >= K) {
            long double probability = 1.0;
            for (int i = 0; i < K; i++)
                probability *= static_cast<long double>(numRock - i) / static_cast<long double>(totalNumRocks - i);
            result += probability;
        }
    }

    cout << setprecision(9) << result;

    return 0;
}