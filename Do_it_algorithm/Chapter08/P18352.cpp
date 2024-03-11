#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static vector<vector<int>> graph;
static vector<int> distances;
static vector<bool> visited;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_cities, num_roads, target_dist, source;
    cin >> num_cities >> num_roads >> target_dist >> source;

    graph.resize(num_cities + 1);
    distances.resize(num_cities + 1, 0);
    visited.resize(num_cities + 1, false);

    for (int _ = 0; _ < num_roads; _++) {
        int src, dest;
        cin >> src >> dest;

        graph[src].push_back(dest);
    }

    vector<int> result;
    queue<int> bfs_queue;
    bfs_queue.push(source);
    visited[source] = true;
    while (!bfs_queue.empty()) {
        int curr = bfs_queue.front();
        bfs_queue.pop();

        for (auto neighbor = graph[curr].begin(); neighbor != graph[curr].end(); neighbor++) {
            if (!visited[*neighbor]) {
                visited[*neighbor] = true;

                int dist = distances[curr] + 1;
                if (dist == target_dist)
                    result.push_back(*neighbor);
                else {
                    bfs_queue.push(*neighbor);
                    distances[*neighbor] = dist;
                }
            }
        }
    }

    if (result.empty())
        cout << -1;
    else {
        sort(result.begin(), result.end());
        for (auto it = result.begin(); it != result.end(); it++)
            cout << *it << '\n';
    }

    return 0;
}