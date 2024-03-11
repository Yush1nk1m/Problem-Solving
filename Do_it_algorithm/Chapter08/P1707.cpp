#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define COLORLESS -1
#define WHITE 0
#define BLACK 1

void InitializeGraph(int V, int E, vector<vector<int>>& graph);
bool IsBipartite(int V, vector<vector<int>>& graph);

bool CheckBipartite(int source);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    for (int _ = 0; _ < K; _++) {
        vector<vector<int>> graph;
        int V, E;
        cin >> V >> E;

        InitializeGraph(V, E, graph);
        cout << (IsBipartite(V, graph) ? "YES\n" : "NO\n");
    }

    return 0;
}

void InitializeGraph(int V, int E, vector<vector<int>>& graph) {
    graph.resize(V + 1);
    for (int _ = 0; _ < E; _++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

bool IsBipartite(int V, vector<vector<int>>& graph) {
    vector<int> colors(V + 1, COLORLESS);

    for (int source = 1; source <= V; source++) {
        if (colors[source] == COLORLESS) {
            queue<int> bfs_queue;
            bfs_queue.push(source);
            colors[source] = WHITE;

            while (!bfs_queue.empty()) {
                int curr = bfs_queue.front();
                int curr_color = colors[curr];
                bfs_queue.pop();

                for (auto neighbor = graph[curr].begin(); neighbor != graph[curr].end(); neighbor++) {
                    if (colors[*neighbor] == COLORLESS) {
                        colors[*neighbor] = (curr_color == WHITE) ? BLACK : WHITE;
                        bfs_queue.push(*neighbor);
                    } else if (colors[*neighbor] == curr_color) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}