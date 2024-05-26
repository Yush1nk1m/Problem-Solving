#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000001

static inline vector<int> GetSimilarityTable(vector<vector<pair<int, int>>> graph, int video);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int _ = 0; _ < N - 1; _++) {
        int v1, v2, similarity;
        cin >> v1 >> v2 >> similarity;

        graph[v1].push_back({ v2, similarity });
        graph[v2].push_back({ v1, similarity });
    }

    vector<vector<int>> similarities(N + 1);
    for (int i = 1; i <= N; i++)
        similarities[i] = GetSimilarityTable(graph, i);

    for (int _ = 0; _ < Q; _++) {
        int k, v;
        cin >> k >> v;

        int count = 0;
        for (int neighbor = 1; neighbor <= N; neighbor++)
            if (similarities[v][neighbor] >= k)
                count++;
        cout << count << '\n';
    }
}

static inline vector<int> GetSimilarityTable(vector<vector<pair<int, int>>> graph, int video) {
    int N = graph.size();
    vector<int> table(N + 1, INF);
    vector<bool> visited(N + 1, false);
    queue<int> videos;

    visited[video] = true;
    videos.push(video);
    while (!videos.empty()) {
        int curr = videos.front();
        videos.pop();

        for (pair<int, int>& edge : graph[curr]) {
            int neighbor = edge.first, ngbrSimilarity = edge.second;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                videos.push(neighbor);
                table[neighbor] = min(table[curr], ngbrSimilarity);
            }
        }
    }
    table[video] = 0;

    return table;
}