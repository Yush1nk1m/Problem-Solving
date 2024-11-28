/**
 * @file 3980_Backtracking.cpp
 * @brief 00:07:53
 * @date 2024-11-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int T, maxStat;
int graph[11][11];
bool visited[11];

void dfs(int order, int total);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        maxStat = 0;
        fill(visited, visited + 11, false);
        for (int r = 0; r < 11; r++)
            for (int c = 0; c < 11; c++)
                cin >> graph[r][c];
        
        dfs(0, 0);
        cout << maxStat << '\n';
    }
}

void dfs(int order, int total) {
    if (order == 11) {
        maxStat = max(maxStat, total);
        return;
    }

    for (int i = 0; i < 11; i++)
        if (!visited[i] && graph[order][i]) {
            visited[i] = true;
            dfs(order + 1, total + graph[order][i]);
            visited[i] = false;
        }
}