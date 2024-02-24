#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> table(N + 1, vector<int>(N + 1, 0));
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> table[r][c];
            table[r][c] += (table[r-1][c] + table[r][c-1] - table[r-1][c-1]);
        }
    }

    for (int _ = 0; _ < M; _++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (table[x2][y2] - table[x1-1][y2] - table[x2][y1-1] + table[x1-1][y1-1]) << '\n';
    }

    return 0;
}