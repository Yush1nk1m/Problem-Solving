#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, num_connected_component;
vector<vector<bool>> graph;
vector<bool> visited;

inline void bfs(int node) {
    num_connected_component++;
    
    queue<int> nodes;

    visited[node] = true;
    nodes.push(node);

    while (!nodes.empty()) {
        int curr = nodes.front();
        nodes.pop();

        for (int neighbor = 1; neighbor <= N; neighbor++) {
            if (graph[curr][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                nodes.push(neighbor);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> N >> M;
    
    graph.resize(N + 1, vector<bool>(N + 1, false));
    visited.resize(N + 1, false);

    for (int _ = 0; _ < M; _++) {
        int u, v;
        cin >> u >> v;
        
        graph[u][v] = true;
        graph[v][u] = true;
    }

    for (int node = 1; node <= N; node++)
        if (!visited[node]) bfs(node);

    cout << num_connected_component;
    
    return 0;
}