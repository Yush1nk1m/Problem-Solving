#include <iostream>
#include <vector>
using namespace std;

static unsigned long long int Combination[201][201];
inline void InitializeCombination();
inline void PrintKthString(int N, int M, int K);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    InitializeCombination();

    int N, M, K;
    cin >> N >> M >> K;

    PrintKthString(N, M, K);

    return 0;
}

inline void InitializeCombination() {
    for (int i = 0; i <= 200; i++)
        Combination[i][0] = Combination[i][i] = 1;
    
    for (int i = 2; i <= 200; i++)
        for (int j = 1; j < i; j++)
            Combination[i][j] = min(Combination[i-1][j] + Combination[i-1][j-1], 1000000001ULL);
}

inline void PrintKthString(int N, int M, int K) {
    if (Combination[N + M][N] < K) {
        cout << -1;
        return;
    }

    while (!(N == 0 && M == 0)) {
        unsigned long long int aCases = Combination[N + M - 1][M];
        if (K <= aCases) {
            cout << 'a';
            N--;
        }
        else {
            cout << 'z';
            M--;
            K -= aCases;
        }
    }
}