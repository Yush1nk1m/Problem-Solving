#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

static vector<vector<pair<int, int>>> graph;

static void Dijkstra(vector<int>& distances, int start, int N);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, E;
    cin >> N >> E;

    graph.resize(N + 1);
    
    for (int _ = 0; _ < E; _++) {
        int from, to, distance;
        cin >> from >> to >> distance;

        graph[from].push_back({distance, to});
        graph[to].push_back({distance, from});
    }

    int stopover1, stopover2;
    cin >> stopover1 >> stopover2;

    vector<int> distanceFromStart(N + 1, INF), distanceFromStopover1(N + 1, INF), distanceFromStopover2(N + 1, INF);
    Dijkstra(distanceFromStart, 1, N);
    Dijkstra(distanceFromStopover1, stopover1, N);
    Dijkstra(distanceFromStopover2, stopover2, N);

    if (distanceFromStart[stopover1] == INF || distanceFromStopover1[stopover2] == INF || distanceFromStopover2[N] == INF || distanceFromStart[stopover2] == INF || distanceFromStopover1[N] == INF)
        cout << -1;
    else {
        int result = min(
            distanceFromStart[stopover1] + distanceFromStopover1[stopover2] + distanceFromStopover2[N],
            distanceFromStart[stopover2] + distanceFromStopover2[stopover1] + distanceFromStopover1[N]
            );
        
        cout << result;
    }

    return 0;
}

static void Dijkstra(vector<int>& distances, int start, int N) {
    vector<bool> visited(N + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distances[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int curr = pq.top().second, currDistance = pq.top().first;
        pq.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

        for (pair<int, int>& nPair : graph[curr]) {
            int neighbor = nPair.second, distance = nPair.first;
            if (!visited[neighbor] && distances[neighbor] > currDistance + distance) {
                distances[neighbor] = currDistance + distance;
                pq.push({distances[neighbor], neighbor});
            }
        }
    }
}