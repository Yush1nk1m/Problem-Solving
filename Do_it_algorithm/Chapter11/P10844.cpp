#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000000

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<long long int>> table(101, vector<long long int>(11, 0));

    for (int i = 1; i <= 9; i++)
        table[1][i] = 1;

    for (int n = 2; n <= N; n++) {
        for (int finalNumber = 1; finalNumber <=9; finalNumber++)
            table[n][finalNumber] = ((table[n-1][finalNumber-1] % MOD) + (table[n-1][finalNumber+1] % MOD)) % MOD;
        table[n][0] = table[n-1][1] % MOD;
    }

    long long int total = 0;
    for (int i = 0; i <= 9; i++) {
        total += table[N][i];
        total %= MOD;
    }

    cout << total;

    return 0;
}