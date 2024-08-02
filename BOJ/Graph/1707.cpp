/**
 * @file 1707.cpp
 * @brief 00:15:58
 * @date 2024-08-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define RED     1
#define BLACK   -1

int K, V, E;

inline bool Solve(int V, int E);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for (int _ = 0; _ < K; _++) {
        cin >> V >> E;
        bool res = Solve(V, E);

        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

inline bool Solve(int V, int E) {
    vector<vector<int>> graph(V + 1);
    vector<bool> visited(V + 1, false);
    vector<int> mark(V + 1, 0);
    queue<int> q;

    for (int _ = 0; _ < E; _++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= V; i++)
        if (!visited[i]) {
            visited[i] = true;
            mark[i] = RED;
            q.push(i);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) {
                    if (mark[neighbor] == mark[curr])
                        return false;
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        mark[neighbor] = -mark[curr];
                        q.push(neighbor);
                    }
                }
            }
        }
    
    return true;
}