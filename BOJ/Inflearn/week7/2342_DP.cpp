/**
 * @file 2342_DP.cpp
 * @brief 00:25:21
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF     100000000
#define MID     0
#define UP      1
#define LEFT    2
#define DOWN    3
#define RIGHT   4

int command, N;
vector<int> instruction;
vector<vector<vector<int>>> table;      // [turn][left][right]

inline int GetMoveCost(int dir1, int dir2);
int DFS(int turn, int left, int right);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> command) {
        if (command == 0)
            break;

        instruction.push_back(command);
    }
    N = instruction.size();

    table.resize(N, vector<vector<int>>(5, vector<int>(5, 0)));
    cout << DFS(0, 0, 0);

    return 0;
}

inline int GetMoveCost(int dir1, int dir2) {
    if (dir1 == dir2)
        return 1;
    if (dir1 == 0)
        return 2;
    else if (dir1 == UP) {
        if (dir2 == LEFT || dir2 == RIGHT)
            return 3;
        else
            return 4;
    }
    else if (dir1 == LEFT) {
        if (dir2 == UP || dir2 == DOWN)
            return 3;
        else
            return 4;
    }
    else if (dir1 == DOWN) {
        if (dir2 == LEFT || dir2 == RIGHT)
            return 3;
        else
            return 4;
    }
    else if (dir1 == RIGHT) {
        if (dir2 == UP || dir2 == DOWN)
            return 3;
        else
            return 4;
    }
    else
        return INF;
}

int DFS(int turn, int left, int right) {
    if (left != 0 && right != 0 && left == right)
        return INF;

    if (turn == N)
        return 0;

    if (table[turn][left][right] > 0)
        return table[turn][left][right];

    int& ret = table[turn][left][right];
    int nextp = instruction[turn];

    ret = min(
        DFS(turn + 1, nextp, right) + GetMoveCost(left, nextp),
        DFS(turn + 1, left, nextp) + GetMoveCost(right, nextp)
    );

    return ret;
}