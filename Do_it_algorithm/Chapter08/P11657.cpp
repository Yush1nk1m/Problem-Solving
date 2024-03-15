#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define INF 2000000000

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numCity, numPath;
    cin >> numCity >> numPath;

    vector<tuple<int, int, long long int>> graph;
    vector<long long int> distances(numCity + 1, INF);

    for (int _ = 0; _ < numPath; _++) {
        int src, dest;
        long long int distance;
        cin >> src >> dest >> distance;

        graph.push_back(make_tuple(src, dest, distance));
    }

    distances[1] = 0;
    for (int _ = 0; _ < numCity - 1; _++) {
        for (tuple<int, int, long long int> edge : graph) {
            int source = get<0>(edge), destination = get<1>(edge);
            long long int distance = get<2>(edge);
            if (distances[source] != INF && distances[source] + distance < distances[destination])
                distances[destination] = distances[source] + distance;
        }
    }

    bool isCycle = false;
    for (tuple<int, int, long long int> edge : graph) {
        int source = get<0>(edge), destination = get<1>(edge);
        long long int distance = get<2>(edge);
        if (distances[source] != INF && distances[source] + distance < distances[destination]) {
            isCycle = true;
            break;
        }
    }

    if (isCycle) {
        cout << -1;
    } else {
        for (int city = 2; city <= numCity; city++) {
            if (distances[city] == INF)
                cout << -1 << '\n';
            else
                cout << distances[city] << '\n';
        }
    }

    return 0;
}