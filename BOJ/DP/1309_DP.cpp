/**
 * @file 1309_DP.cpp
 * @brief 00:07:49
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    -1
#define EMPTY   0
#define LEFT    1
#define RIGHT   2
#define MOD     9901

int N;
int position[3] = { EMPTY, LEFT, RIGHT };
vector<vector<int>> table;

int DFS(int depth, int pos);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    table.resize(N + 1, vector<int>(3, NONE));

    cout << DFS(0, EMPTY);

    return 0;
}

int DFS(int depth, int pos) {
    if (depth == N)
        return 1;

    int& ret = table[depth][pos];
    if (ret != NONE)
        return ret;

    ret = 0;
    for (int nextp : position)
        if (!((pos == LEFT && nextp == LEFT) || (pos == RIGHT && nextp == RIGHT))) {
            ret += DFS(depth + 1, nextp);
            ret %= MOD;
        }
    
    return ret;
}