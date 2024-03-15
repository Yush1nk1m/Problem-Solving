#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numCity, numBus;
    cin >> numCity >> numBus;

    vector<vector<pair<int, int>>> graph(numCity + 1);
    vector<bool> visited(numCity + 1, false);
    vector<int> distances(numCity + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int _ = 0; _ < numBus; _++) {
        int from, to, distance;
        cin >> from >> to >> distance;
        graph[from].push_back({distance, to});
    }

    int source, destination;
    cin >> source >> destination;

    distances[source] = 0;
    pq.push({distances[source], source});
    while (!pq.empty()) {
        int currDistance = pq.top().first, curr = pq.top().second;
        pq.pop();
        
        if (!visited[curr]) {
            visited[curr] = true;
        } else {
            continue;
        }

        for (pair<int, int> neighbor : graph[curr]) {
            int distance = neighbor.first, next = neighbor.second;
            if (currDistance + distance < distances[next]) {
                distances[next] = currDistance + distance;
                pq.push({distances[next], next});
            }
        }
    }

    cout << distances[destination];

    return 0;
}