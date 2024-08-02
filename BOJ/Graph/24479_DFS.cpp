/**
 * @file 24479_DFS.cpp
 * @brief 00:05:51
 * @date 2024-08-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, R, order = 1;
vector<vector<int>> graph;
vector<int> visited;

void DFS(int vertex);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;
    
    visited.resize(N + 1, 0);
    graph.resize(N + 1);

    for (int _ = 0; _ < M; _++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    DFS(R);

    for (int i = 1; i <= N; i++)
        cout << visited[i] << '\n';

    return 0;
}

void DFS(int vertex) {
    visited[vertex] = order++;
    for (int neighbor : graph[vertex])
        if (!visited[neighbor])
            DFS(neighbor);
}