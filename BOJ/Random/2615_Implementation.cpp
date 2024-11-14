/**
 * @file 2615_Implementation.cpp
 * @brief 00:28:46
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int piece, row, col;
int board[20][20];

inline bool isValidPoint(int r, int c);
inline bool checkUpperDiagonal(int r, int c);
inline bool checkRight(int r, int c);
inline bool checkLowerDiagonal(int r, int c);
inline bool checkDown(int r, int c);
inline int checkAllDirection(int r, int c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int r = 1; r <= 19; r++)    
        for (int c = 1; c <= 19; c++)
            cin >> board[r][c];

    for (int r = 1; r <= 19 && !piece; r++)
        for (int c = 1; c <= 19 && !piece; c++)
            if (board[r][c]) {
                piece = checkAllDirection(r, c);
                row = piece ? r : 0;
                col = piece ? c : 0;
            }
    
    cout << piece;
    if (piece)
        cout << '\n' << row << ' ' << col;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return 1 <= r && r <= 19 && 1 <= c && c <= 19;
}

inline bool checkUpperDiagonal(int r, int c) {
    if (isValidPoint(r+1, c-1) && board[r][c] == board[r+1][c-1])
        return false;

    int cnt = 0, p = board[r][c];
    while (isValidPoint(r, c) && p == board[r][c]) {
        cnt++;
        r--;
        c++;
    }
    return cnt == 5;
}

inline bool checkRight(int r, int c) {
    if (isValidPoint(r, c-1) && board[r][c] == board[r][c-1])
        return false;

    int cnt = 0, p = board[r][c];
    while (isValidPoint(r, c) && p == board[r][c]) {
        cnt++;
        c++;
    }
    return cnt == 5;
}

inline bool checkLowerDiagonal(int r, int c) {
    if (isValidPoint(r-1, c-1) && board[r][c] == board[r-1][c-1])
        return false;

    int cnt = 0, p = board[r][c];
    while (isValidPoint(r, c) && p == board[r][c]) {
        cnt++;
        r++;
        c++;
    }
    return cnt == 5;
}

inline bool checkDown(int r, int c) {
    if (isValidPoint(r-1, c) && board[r][c] == board[r-1][c])
        return false;

    int cnt = 0, p = board[r][c];
    while (isValidPoint(r, c) && p == board[r][c]) {
        cnt++;
        r++;
    }
    return cnt == 5;
}

inline int checkAllDirection(int r, int c) {
    if (checkUpperDiagonal(r, c) || checkRight(r, c) || checkLowerDiagonal(r, c) || checkDown(r, c))
        return board[r][c];
    return 0;
}