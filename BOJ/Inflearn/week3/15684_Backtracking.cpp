/**
 * @file 15684_Backtracking.cpp
 * @brief 00:44:02
 * @date 2024-06-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, H, minDepth = 4;
vector<vector<bool>> table;

inline bool Down(int number);
void DFS(int height, int depth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;
    table.resize(H + 2, vector<bool>(N + 2, false));
    for (int _ = 0; _ < M; _++) {
        int a, b;
        cin >> a >> b;
        table[a][b] = true;
    }

    DFS(1, 0);
    if (minDepth == 4) cout << -1;
    else cout << minDepth;

    return 0;
}

inline bool Down(int number) {
    int n = number;
    int h = 1;
    while (h <= H) {
        if (table[h][n])
            n++;
        else if (table[h][n - 1])
            n--;
        h++;
    }
    return (n == number);
}

void DFS(int height, int depth) {
    if (depth >= minDepth) return;

    bool success = true;
    for (int i = 1; i <= N; i++)
        if (!Down(i)) {
            success = false;
            break;
        }
    if (success) {
        minDepth = min(minDepth, depth);
        return;
    }

    for (int h = height; h <= H; h++)
        for (int n = 1; n <= N - 1; n++)
            if (!table[h][n-1] && !table[h][n] && !table[h][n+1]) {
                table[h][n] = true;
                DFS(h, depth + 1);
                table[h][n] = false;
            }
}