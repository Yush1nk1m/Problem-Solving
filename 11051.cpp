#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> table(N + 1);
    for (int i = 1; i <= N; i++)
        table[i].resize(i + 1, 1);
    
    for (int n = 2; n <= N; n++) {
        for (int k = 1; k < n; k++) {
            table[n][k] = (table[n-1][k-1] + table[n-1][k]) % 10007;
        }
    }

    cout << table[N][K];
    
    return 0;
}