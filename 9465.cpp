#include <iostream>
#include <vector>
using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++) {
        int n;
        cin >> n;

        vector<vector<int>> table(2, vector<int>(n));
        vector<vector<int>> result(2, vector<int>(n));

        for (int r = 0; r < 2; r++)
            for (int c = 0; c < n; c++)
                cin >> table[r][c];

        result[0][0] = table[0][0];
        result[1][0] = table[1][0];

        for (int c = 1; c < n; c++) {
            result[0][c] = MAX(result[0][c-1], result[1][c-1] + table[0][c]);
            result[1][c] = MAX(result[1][c-1], result[0][c-1] + table[1][c]);
        }

        cout << MAX(result[0][n-1], result[1][n-1]) << '\n';
    }

    return 0;
}