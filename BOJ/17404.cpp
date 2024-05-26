#include <iostream>
#include <vector>
using namespace std;

#define R 0
#define G 1
#define B 2
#define INF 1000000

inline int DP(vector<vector<int>> table, int firstColor);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> houses(N, vector<int>(3));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < 3; c++)
            cin >> houses[r][c];

    cout << min(DP(houses, R), min(DP(houses, G), DP(houses, B)));

    return 0;
}

inline int DP(vector<vector<int>> table, int firstColor) {
    int N = table.size();

    for (int color = 0; color < 3; color++)
        if (color != firstColor)
            table[0][color] = INF;

    for (int i = 1; i < N; i++) {
        table[i][R] += min(table[i-1][G], table[i-1][B]);
        table[i][G] += min(table[i-1][R], table[i-1][B]);
        table[i][B] += min(table[i-1][R], table[i-1][G]);
    }

    if (firstColor == R)
        return min(table[N-1][G], table[N-1][B]);
    else if (firstColor == G)
        return min(table[N-1][R], table[N-1][B]);
    else if (firstColor == B)
        return min(table[N-1][R], table[N-1][G]);
    else
        return INF;
}