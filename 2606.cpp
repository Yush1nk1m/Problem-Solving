#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int node_number, edge_number, result;
vector<vector<bool>> graph;
vector<bool> visited;
queue<int> infected;

int main(int argc, char* argv[]) {
    cin >> node_number >> edge_number;

    graph.resize(node_number + 1, vector<bool>(node_number + 1, false));
    visited.resize(node_number + 1, false);

    for (int _ = 0; _ < edge_number; _++) {
        int src, dest;
        cin >> src >> dest;

        graph[src][dest] = true;
        graph[dest][src] = true;
    }
    
    visited[1] = true;
    infected.push(1);
    
    while (!infected.empty()) {
        int curr = infected.front();
        infected.pop();
        result++;

        for (int node = 1; node <= node_number; node++)
            if (graph[curr][node] && !visited[node]) {
                visited[node] = true;
                infected.push(node);
            }
    }

    cout << result - 1;     // 1번 노드 제외

    return 0;
}