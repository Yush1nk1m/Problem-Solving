/**
 * @file 10709_DP.cpp
 * @brief 00:08:13
 * @date 2024-06-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE -1
#define CLOUD 0

int H, W;

vector<vector<int>> table;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W;
    table.resize(H, vector<int>(W, NONE));

    for (int r = 0; r < H; r++)
        for (int c = 0; c < W; c++) {
            char ch;
            cin >> ch;
            if (ch == 'c') table[r][c] = CLOUD;
        }
    
    for (int r = 0; r < H; r++)
        for (int c = 1; c < W; c++)
            if (table[r][c-1] != NONE) {
                if (table[r][c] == NONE) table[r][c] = table[r][c-1] + 1;
                else table[r][c] = min(table[r][c], table[r][c-1] + 1);
            }

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++)
            cout << table[r][c] << ' ';
        cout << '\n';
    }

    return 0;
}