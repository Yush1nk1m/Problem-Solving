/**
 * @file 18808_Implementation.cpp
 * @brief 00:43:43
 * @date 2024-10-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, K, row, col;
vector<vector<bool>> visited;

inline bool Apply(vector<vector<bool>>& table, vector<vector<bool>>& sticker);
inline void Rotate(vector<vector<bool>>& sticker);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    visited.resize(N, vector<bool>(M, false));

    while (K--) {
        cin >> row >> col;

        vector<vector<bool>> sticker(row, vector<bool>(col));
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++) {
                int element;
                cin >> element;
                sticker[r][c] = (bool)element;
            }

        for (int i = 0; i < 4; i++) {
            if (Apply(visited, sticker))
                break;
            Rotate(sticker);
        }
    }

    int cnt = 0;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cnt += visited[r][c];
    cout << cnt;

    return 0;
}

inline bool Apply(vector<vector<bool>>& table, vector<vector<bool>>& sticker) {
    if (row > N || col > M)
        return false;

    for (int startR = 0; startR <= N - row; startR++)
        for (int startC = 0; startC <= M - col; startC++) {
            bool isApplicable = true;
            for (int r = 0; r < row && isApplicable; r++)
                for (int c = 0; c < col && isApplicable; c++)
                    if (sticker[r][c] && table[startR + r][startC + c])
                        isApplicable = false;
            
            if (isApplicable) {
                for (int r = 0; r < row; r++)
                    for (int c = 0; c < col; c++)
                        if (sticker[r][c])
                            table[startR + r][startC + c] = true;
                return true;
            }
        }
    return false;
}

inline void Rotate(vector<vector<bool>>& sticker) {
    vector<vector<bool>> temp(col, vector<bool>(row));

    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            temp[c][row - r - 1] = sticker[r][c];

    int temp2 = row;
    row = col;
    col = temp2;
    sticker = temp;
}
