#include <iostream>
#include <vector>
using namespace std;

int T, N;
int table[2][41];

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    table[0][0] = 1;
    table[0][1] = 0;

    table[1][0] = 0;
    table[1][1] = 1;

    for (int i = 2; i <= 40; i++) {
        table[0][i] = table[0][i - 1] + table[0][i - 2];
        table[1][i] = table[1][i - 1] + table[1][i - 2];
    }

    cin >> T;

    for (int _ = 0; _ < T; _++) {
        cin >> N;
        
        cout << table[0][N] << ' ' << table[1][N] << '\n';
    }

    return 0;
}