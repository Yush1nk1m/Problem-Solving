/**
 * @file 15511_BipartiteGraph.cpp
 * @brief 00:54:41
 * @date 2024-11-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE    0
#define RED     1
#define BLACK   2

int n, m;
vector<int> color;
vector<vector<int>> graph;

bool dfs(int node, int c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    graph.resize(n + 1);
    color.resize(n + 1, RED);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        color[v1] = color[v2] = NONE;
    }

    for (int i = 1; i <= n; i++)
        if (color[i] == NONE && !dfs(i, RED)) {
            cout << "IMPOSSIBLE";
            return 0;
        }

    cout << "POSSIBLE";
    return 0;
}

bool dfs(int node, int c) {
    color[node] = c;
    
    bool isPossible = true;
    for (int neighbor : graph[node]) {
        if (color[neighbor] == color[node])
            return false;
        else if (color[neighbor] == NONE)
            isPossible &= dfs(neighbor, color[node] == RED ? BLACK : RED);

        if (!isPossible)
            break;
    }

    return isPossible;
}