#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

// return value: max depth
bool DepthFirstSearchFor5Depth(vector<vector<int>>& graph, vector<bool> visited, int visit, int depth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    graph.resize(N);
    visited.resize(N);
    for (int _ = 0; _ < M; _++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool isExist = false;
    for (int start = 0; start < N; start++) {
        fill(visited.begin(), visited.end(), false);
        visited[start] = true;
        if ((DepthFirstSearchFor5Depth(graph, visited, start, 1))) {
            isExist = true;
            break;
        }
    }

    cout << (isExist) ? 1 : 0;

    return 0;
}

bool DepthFirstSearchFor5Depth(vector<vector<int>>& graph, vector<bool> visited, int visit, int depth) {
    if (depth == 5) return true;

    for (auto neighbor = graph[visit].begin(); neighbor != graph[visit].end(); neighbor++) {
        if (!visited[*neighbor]) {
            visited[*neighbor] = true;
            if (DepthFirstSearchFor5Depth(graph, visited, *neighbor, depth + 1)) return true;
            visited[*neighbor] = false;
        }
    }

    return false;
}