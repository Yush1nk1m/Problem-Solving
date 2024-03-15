#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    int node;
    int distance;
} Neighbor;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numCities, numRoads;
    cin >> numCities >> numRoads;

    vector<vector<Neighbor>> graph(numCities + 1);
    vector<vector<Neighbor>> reverseGraph(numCities + 1);
    vector<int> degrees(numCities + 1, 0);
    for (int _ = 0; _ < numRoads; _++) {
        int from, to, distance;

        cin >> from >> to >> distance;
        graph[from].push_back({to, distance});
        reverseGraph[to].push_back({from, distance});
        degrees[to]++;
    }

    int from, to;
    cin >> from >> to;

    vector<int> distances(numCities + 1, 0);
    queue<int> cities;
    cities.push(from);
    while (!cities.empty()) {
        int curr = cities.front();
        cities.pop();

        for (Neighbor neighbor : graph[curr]) {
            if (--degrees[neighbor.node] == 0) {
                cities.push(neighbor.node);
            }

            if (distances[neighbor.node] < distances[curr] + neighbor.distance) {
                distances[neighbor.node] = distances[curr] + neighbor.distance;
            }
        }
    }

    int numAllRoads = 0;
    vector<bool> visited(numCities + 1, false);
    cities.push(to);
    visited[to] = true;
    while (!cities.empty()) {
        int curr = cities.front();
        cities.pop();

        for (Neighbor parent : reverseGraph[curr])
            if (distances[parent.node] + parent.distance == distances[curr]) {
                numAllRoads++;
                
                if (!visited[parent.node]) {
                    visited[parent.node] = true;
                    cities.push(parent.node);
                }
            }
    }

    cout << distances[to] << '\n' << numAllRoads;

    return 0;
}