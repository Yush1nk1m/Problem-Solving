#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> distances(n + 1, -INF);
    vector<bool> visited(n + 1, false);
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int _ = 0; _ < n - 1; _++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        
        graph[from].push_back({weight, to});
        graph[to].push_back({weight, from});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    
    distances[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int curr = pq.top().second, currDistance = pq.top().first;
        pq.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

        for (pair<int, int>& nPair : graph[curr]) {
            int neighbor = nPair.second, distance = nPair.first;
            if (!visited[neighbor] && distances[neighbor] < currDistance + distance) {
                distances[neighbor] = currDistance + distance;
                pq.push({distances[neighbor], neighbor});
            }
        }
    }

    int maxDist = 0, maxNode = 1;
    for (int node = 2; node <= n; node++)
        if (maxDist < distances[node]) {
            maxDist = distances[node];
            maxNode = node;
        }

    fill(visited.begin(), visited.end(), false);
    fill(distances.begin(), distances.end(), -INF);
    
    distances[maxNode] = 0;
    pq.push({0, maxNode});
    while (!pq.empty()) {
        int curr = pq.top().second, currDistance = pq.top().first;
        pq.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

        for (pair<int, int>& nPair : graph[curr]) {
            int neighbor = nPair.second, distance = nPair.first;
            if (!visited[neighbor] && distances[neighbor] < currDistance + distance) {
                distances[neighbor] = currDistance + distance;
                pq.push({distances[neighbor], neighbor});
            }
        }
    }

    maxDist = 0;
    for (int node = 1; node <= n; node++)
        maxDist = max(maxDist, distances[node]);

    cout << maxDist;

    return 0;
}