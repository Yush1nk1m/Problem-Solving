/**
 * @file 13244_BFS.cpp
 * @brief 00:16:15
 * @date 2024-07-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define SIZE 1001

int T, N, M;
vector<bool> visited(SIZE);
vector<vector<bool>> graph(SIZE, vector<bool>(SIZE));

inline void Initialize();
inline bool BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> N >> M;
        Initialize();

        for (int e = 0; e < M; e++) {
            int n1, n2;
            cin >> n1 >> n2;
            graph[n1][n2] = graph[n2][n1] = true;
        }

        if (BFS()) cout << "tree\n";
        else cout << "graph\n";
    }
}

inline void Initialize() {
    fill(visited.begin(), visited.end(), false);
    fill(graph.begin(), graph.end(), vector<bool>(SIZE, false));
}

inline bool BFS() {
    if (M != N - 1) return false;
    queue<int> q;
    
    visited[1] = true;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor = 1; neighbor <= N; neighbor++)
            if (!visited[neighbor] && graph[curr][neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
    }

    return (accumulate(visited.begin(), visited.end(), 0) == N);
}