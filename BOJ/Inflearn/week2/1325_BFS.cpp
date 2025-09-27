/**
 * @file 1325_BFS.cpp
 * @brief 00:09:09
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, maxHack;
vector<int> hack;
vector<vector<int>> graph;

inline int BFS(int start);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N + 1);
    hack.resize(N + 1);
    for (int _ = 0; _ < M; _++) {
        int from, to;
        cin >> to >> from;
        graph[from].push_back(to);
    }

    for (int i = 1; i <= N; i++) {
        hack[i] = BFS(i);
        maxHack = max(maxHack, hack[i]);
    }

    for (int i = 1; i <= N; i++)
        if (hack[i] == maxHack)
            cout << i << ' ';

    return 0;
}

inline int BFS(int start) {
    int cnt = 0;
    queue<int> q;
    vector<bool> visited(N + 1, false);

    q.push(start);
    visited[start] = true;
    cnt++;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                cnt++;
            }
        }
    }

    return cnt;
}