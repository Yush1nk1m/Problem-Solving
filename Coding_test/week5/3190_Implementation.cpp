/**
 * @file 3190_Implementation.cpp
 * @brief 00:43:09
 * @date 2024-07-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define RIGHT   0
#define DOWN    1
#define LEFT    2
#define UP      3

#define SNAKE -1
#define EMPTY 0
#define APPLE 1

int N, K, L, T, dir;
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
vector<vector<int>> board;
queue<pair<int, char>> turn;
deque<pair<int, int>> snake;

inline void Rotate(char toward);
inline bool isValidPoint(int r, int c);
inline bool Move();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    board.resize(N, vector<int>(N, EMPTY));
    for (int _ = 0; _ < K; _++) {
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] = APPLE;
    }

    cin >> L;
    for (int _ = 0; _ < L; _++) {
        int t;
        char toward;
        cin >> t >> toward;
        turn.push({ t, toward });
    }

    board[0][0] = SNAKE;
    snake.push_front({ 0, 0 });
    while (1) {
        T++;
        
        if (!Move()) break;

        if (!turn.empty() && turn.front().first == T) {
            Rotate(turn.front().second);
            turn.pop();
        }
    }

    cout << T;

    return 0;
}

inline void Rotate(char toward) {
    if (toward == 'L')
        dir = (dir + 3) % 4;    
    else
        dir = (dir + 1) % 4;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < N && board[r][c] != SNAKE);
}

inline bool Move() {
    int r, c;
    tie(r, c) = snake.front();
    r += dr[dir]; c += dc[dir];

    if (!isValidPoint(r, c))
        return false;

    if (board[r][c] == EMPTY) {
        int tr, tc;
        tie(tr, tc) = snake.back();
        board[tr][tc] = EMPTY;
        snake.pop_back();
    }

    snake.push_front({ r, c });
    board[r][c] = SNAKE;

    return true;
}