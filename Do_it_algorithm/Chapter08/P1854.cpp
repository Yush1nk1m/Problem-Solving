#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2000000000

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numCity, numRoad, k;
    cin >> numCity >> numRoad >> k;

    vector<vector<pair<int, int>>> graph(numCity + 1);
    vector<priority_queue<int, vector<int>, less<int>>> distances(numCity + 1);
    for (int i = 1; i <= numCity; i++)
        for (int _ = 0; _ < k; _++)
            distances[i].push(INF);
    
    for (int _ = 0; _ < numRoad; _++) {
        int from, to, distance;
        cin >> from >> to >> distance;
        graph[from].push_back({distance, to});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[1].pop();
    distances[1].push(0);
    pq.push({0, 1});
    while (!pq.empty()) {
        int curr = pq.top().second, currDistance = pq.top().first;
        pq.pop();

        for (pair<int, int> neighbor : graph[curr]) {
            int next = neighbor.second, distance = neighbor.first;
            if (currDistance + distance < distances[next].top()) {
                distances[next].pop();
                distances[next].push(currDistance + distance);
                pq.push({currDistance + distance, next});
            }
        }
    }

    for (int i = 1; i <= numCity; i++) {
        if (distances[i].top() == INF)
            cout << -1 << '\n';
        else
            cout << distances[i].top() << '\n';
    }

    return 0;
}