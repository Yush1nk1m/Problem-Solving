#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

static vector<vector<int>> graph;
static unordered_set<int> sources;

int BFS(int source);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    for (int _ = 0; _ < M; _++) {
        int src, dest;
        cin >> dest >> src;
        graph[src].push_back(dest);
        sources.insert(src);
    }

    vector<int> result;
    int max = 1;
    for (auto source = sources.begin(); source != sources.end(); source++) {
        int num_hacked = BFS(*source);
        if (num_hacked == max) {
            result.push_back(*source);
        } else if (num_hacked > max) {
            max = num_hacked;
            result.clear();
            result.push_back(*source);
        }
    }

    sort(result.begin(), result.end());
    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << " ";

    return 0;
}

int BFS(int source) {
    int size = graph.size();
    vector<bool> visited(size, false);
    queue<int> bfs_queue;

    int count = 1;
    visited[source] = true;
    bfs_queue.push(source);
    while (!bfs_queue.empty()) {
        int curr = bfs_queue.front();
        bfs_queue.pop();

        for (auto neighbor = graph[curr].begin(); neighbor != graph[curr].end(); neighbor++)
            if (!visited[*neighbor]) {
                visited[*neighbor] = true;
                bfs_queue.push(*neighbor);
                count++;
            }
    }

    return count;
}