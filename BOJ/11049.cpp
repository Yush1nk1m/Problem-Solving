#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<pair<long long int, long long int>> matrixTable;
vector<vector<long long int>> operationTimeTable;

inline long long int MatrixMulTime(int, int);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    matrixTable.resize(N);
    operationTimeTable.resize(N);

    for (int i = 0; i < N; i++) {
        operationTimeTable[i].resize(N, 0);
        
        cin >> matrixTable[i].first >> matrixTable[i].second;
    }

    for (int range = 1; range <= N; range++) {
        for (int i = 0, j = i + range; j < N; i++, j++) {
            long long int minimum = numeric_limits<long long int>::max();
            for (int k = i; k < j; k++)
                minimum = min(minimum,
                operationTimeTable[i][k] + operationTimeTable[k+1][j] +
                (matrixTable[i].first * matrixTable[k].second * matrixTable[j].second));
            
            operationTimeTable[i][j] = minimum;
        }
    }

    cout << operationTimeTable[0][N-1];

    return 0;
}