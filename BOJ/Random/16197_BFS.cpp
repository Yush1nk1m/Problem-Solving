/**
 * @file 16197_BFS.cpp
 * @brief 00:29:01
 * @date 2024-10-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define COIN    'o'
#define EMPTY   '.'
#define WALL    '#'
#define LEFT    0
#define RIGHT   1
#define UP      2
#define DONW    3

int N, M;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };
vector<vector<char>> board;
vector<pair<int, int>> coins;
queue<vector<pair<int, int>>> q;

inline int solve();
inline bool isValidPoint(pair<int, int>& coin);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    board.resize(N, vector<char>(M));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            cin >> board[r][c];
            if (board[r][c] == COIN)
                coins.push_back({ r, c });
        }
    
    cout << solve();

    return 0;
}

inline int solve() {
    int button = 0;
    q.push(coins);
    while (button < 10) {
        button++;
        int qsize = q.size();
        while (qsize--) {
            vector<pair<int, int>> curr = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int outCount = 0;
                
                pair<int, int> coin1 = curr[0];
                coin1.first += dr[dir]; coin1.second += dc[dir];
                if (!isValidPoint(coin1)) {
                    outCount++;
                } else if (board[coin1.first][coin1.second] == WALL) {
                    coin1 = curr[0];
                }

                pair<int, int> coin2 = curr[1];
                coin2.first += dr[dir]; coin2.second += dc[dir];
                if (!isValidPoint(coin2)) {
                    outCount++;
                } else if (board[coin2.first][coin2.second] == WALL) {
                    coin2 = curr[1];
                }

                if (outCount == 1) {
                    return button;
                } else if (outCount == 2 || (coin1 == curr[0] && coin2 == curr[1])) {
                    continue;
                } else {
                    q.push({ coin1, coin2 });
                }
            }
        }
    }

    return -1;
}

inline bool isValidPoint(pair<int, int>& coin) {
    return 0 <= coin.first && coin.first < N && 0 <= coin.second && coin.second < M;
}