/**
 * @file 12759_Implementation.cpp
 * @brief 00:15:!4
 * @date 2024-10-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int turn;
vector<pair<int, int>> place;
int board[4][4];

inline int getWinner();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> turn;
    for (int i = 0; i < 9; i++) {
        int r, c;
        cin >> r >> c;
        place.push_back({ r, c });
    }

    for (pair<int, int>& p : place) {
        board[p.first][p.second] = turn;
        int winner;
        if ((winner = getWinner())) {
            cout << winner;
            exit(0);
        }
        turn = (turn == 1) ? 2 : 1;
    }
    cout << 0;

    return 0;
}

inline int getWinner() {
    // row checking
    if (0 != board[1][1] && board[1][1] == board[1][2] && board[1][1] == board[1][3])
        return board[1][1];
    if (0 != board[2][1] && board[2][1] == board[2][2] && board[2][1] == board[2][3])
        return board[2][1];
    if (0 != board[3][1] && board[3][1] == board[3][2] && board[3][1] == board[3][3])
        return board[3][1];
    
    // column checking
    if (0 != board[1][1] && board[1][1] == board[2][1] && board[1][1] == board[3][1])
        return board[1][1];
    if (0 != board[1][2] && board[1][2] == board[2][2] && board[1][2] == board[3][2])
        return board[1][2];
    if (0 != board[1][3] && board[1][3] == board[2][3] && board[1][3] == board[3][3])
        return board[1][3];

    // diagonal checking
    if (0 != board[1][1] && board[1][1] == board[2][2] && board[1][1] == board[3][3])
        return board[1][1];
    if (0 != board[1][3] && board[1][3] == board[2][2] && board[1][3] == board[3][1])
        return board[1][3];

    return 0;
}