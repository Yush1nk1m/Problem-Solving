/**
 * @file 13119_Implementation.cpp
 * @brief 00:13:07
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define EMPTY       46
#define MOUNTAIN    35
#define TUNNEL      42
#define BRIDGE      45
#define PIER        124

int N, M, X;
vector<vector<char>> picture;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    picture.resize(N, vector<char>(M, EMPTY));

    for (int i = 0; i < M; i++) {
        int height;
        cin >> height;
        for (int h = 1; h <= height; h++)
            picture[N-h][i] = MOUNTAIN;
        
        if (picture[N-X][i] == EMPTY)
            picture[N-X][i] = BRIDGE;
        else
            picture[N-X][i] = TUNNEL;

        if ((i + 1) % 3 == 0)
            for (int x = N - X + 1; x < N && picture[x][i] != MOUNTAIN; x++)
                picture[x][i] = PIER;
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++)
            cout << picture[r][c];
        cout << '\n';
    }

    return 0;
}