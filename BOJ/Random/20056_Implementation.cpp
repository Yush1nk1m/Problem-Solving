/**
 * @file 20056_Implementation.cpp
 * @brief 01:02:53
 * @date 2024-09-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

class Ball {
    public:
        Ball(int row, int column, int mess, int speed, int direction):
            row(row), column(column), mess(mess), speed(speed), direction(direction)
            {};
        int row;
        int column;
        int mess;
        int speed;
        int direction;
        void Move();
};

int N, M, K, result;
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<vector<queue<Ball>>> board;
queue<Ball> remained;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    board.resize(N, vector<queue<Ball>>(N));

    while (M--) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        Ball ball(r-1, c-1, m, s, d);
        remained.push(ball);
        board[r-1][c-1].push(ball);
    }

    while (K--) {
        while (!remained.empty()) {
            Ball curr = remained.front();
            remained.pop();
            board[curr.row][curr.column].pop();

            curr.Move();
            board[curr.row][curr.column].push(curr);
        }

        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++) {
                if (board[r][c].size() == 1)
                    remained.push(board[r][c].front());
                else if (board[r][c].size() > 1) {
                    bool isOdd = false, isEven = false;
                    int n = board[r][c].size();
                    int mess = 0;
                    int speed = 0;

                    while (!board[r][c].empty()) {
                        Ball ball = board[r][c].front();
                        board[r][c].pop();

                        mess += ball.mess;
                        speed += ball.speed;
                        if (ball.direction % 2 == 0)
                            isEven = true;
                        else
                            isOdd = true;
                    }

                    mess /= 5;
                    if (mess == 0) continue;
                    speed /= n;
                    if (isOdd && isEven)
                        for (int d = 1; d < 8; d += 2) {
                            Ball ball(r, c, mess, speed, d);
                            remained.push(ball);
                            board[r][c].push(ball);
                        }
                    else
                        for (int d = 0; d < 8; d += 2) {
                            Ball ball(r, c, mess, speed, d);
                            remained.push(ball);
                            board[r][c].push(ball);
                        }
                }
            }
    }

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            while (!board[r][c].empty()) {
                result += board[r][c].front().mess;
                board[r][c].pop();
            }

    cout << result;

    return 0;
}

void Ball::Move() {
    int nr = row + dr[direction] * speed;
    int nc = column + dc[direction] * speed;

    if (nr >= N)
        nr %= N;
    while (nr < 0)
        nr += N;

    if (nc >= N)
        nc %= N;
    while (nc < 0)
        nc += N;

    row = nr;
    column = nc;
}