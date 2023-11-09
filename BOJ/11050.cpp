#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> bin_coef;

int N, K, i, j;

int main(int argc, char* argv[]) {
    cin >> N >> K;
    bin_coef.resize(N + 1);

    for (i = 1; i <= N; i++) {
        bin_coef[i].resize(i + 1, 0);
        bin_coef[i][0] = 1;
    }
    bin_coef[1][1] = 1;

    for (i = 2; i <= N; i++) {
        for (j = 1; j < i; j++)
            bin_coef[i][j] = bin_coef[i - 1][j - 1] + bin_coef[i - 1][j];
        bin_coef[i][j] = 1;
    }

    cout << bin_coef[N][K];

    return 0;
}