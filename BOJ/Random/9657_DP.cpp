/**
 * @file 9657_DP.cpp
 * @brief 00:30:00
 * @date 2024-10-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    0
#define SK      1
#define CY      2

int N;
int cache[1001][3][5];  // [rock][turn][jump]

int dfs(int rock, int turn);
int game(int rock, int turn);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    int result = dfs(N, SK);
    if (result == SK)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}

int dfs(int rock, int turn) {
    if (rock == 0) {
        return (turn == SK) ? CY : SK;
    }

    int nxt = (turn == SK) ? CY : SK;
    for (int i : { 1, 3, 4 })
        if (cache[rock][turn][i] == NONE && rock >= i)
            cache[rock][turn][i] = dfs(rock - i, nxt);

    for (int i : { 1, 3, 4 })
        if (cache[rock][turn][i] == turn)
            return turn;
    return nxt;
}