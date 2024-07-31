/**
 * @file 1149_DP.cpp
 * @brief 00:07:57
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define RED     0
#define GREEN   1
#define BLUE    2
#define NONE    100000000

int N;
int colors[3] = { RED, GREEN, BLUE };
vector<vector<int>> rgb;
vector<vector<int>> table;

int DFS(int depth, int prevColor);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    rgb.resize(N, vector<int>(3));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < 3; c++)
            cin >> rgb[r][c];

    table.resize(N, vector<int>(3, NONE));
    cout << min(DFS(0, RED), min(DFS(0, GREEN), DFS(0, BLUE)));

    return 0;
}

int DFS(int depth, int prevColor) {
    if (depth == N)
        return 0;

    int& ret = table[depth][prevColor];
    if (ret != NONE)
        return ret;

    for (int color : colors)
        if (color != prevColor)
            ret = min(ret, DFS(depth + 1, color));
    ret += rgb[depth][prevColor];

    return ret;
}