#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<long long int>> graph;
vector<long long int> materials;

long long int GCD(long long int a, long long int b) {
    if (a < b) {
        long long int temp = a;
        a = b;
        b = temp;
    }

    long long int remainder = a % b;
    while (remainder != 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }

    return b;
}

vector<long long int> GetNeighbors(vector<vector<long long int>>& graph, long long int start) {
    vector<long long int> result;
    queue<long long int> neighbors;
    vector<bool> visited(graph.size(), false);

    neighbors.push(start);
    visited[start] = true;

    while (!neighbors.empty()) {
        long long int curr = neighbors.front();
        neighbors.pop();

        for (long long neighbor : graph[curr])
            if (!visited[neighbor]) {
                result.push_back(neighbor);
                neighbors.push(neighbor);
                visited[neighbor] = true;
            }
    }

    return result;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int N;
    cin >> N;

    if (N == 1) {
        cout << 1;
        return 0;
    }

    graph.resize(N);
    materials.resize(N, 0);

    for (long long int _ = 0; _ < N - 1; _++) {
        long long int from, to, from_rate, to_rate;
        cin >> from >> to >> from_rate >> to_rate;

        if (materials[from] == 0 && materials[to] == 0) {
            materials[from] = from_rate;
            materials[to] = to_rate;
        }
        else if (materials[from] != 0 && materials[to] == 0) {
            materials[to] = materials[from] * to_rate;
            for (long long int neighbor : GetNeighbors(graph, from))
                materials[neighbor] *= from_rate;
            materials[from] *= from_rate;
        }
        else if (materials[from] == 0 && materials[to] != 0) {
            materials[from] = materials[to] * from_rate;
            for (long long int neighbor : GetNeighbors(graph, to))
                materials[neighbor] *= to_rate;
            materials[to] *= to_rate;
        }
        else {  // materials[from] != 0 && materials[to] != 0
            long long int lcm = materials[from] * materials[to] / GCD(materials[from], materials[to]);

            for (long long int neighbor : GetNeighbors(graph, from)) {
                materials[neighbor] = lcm * from_rate * materials[neighbor] / materials[from];
            }
            
            for (long long int neighbor : GetNeighbors(graph, to)) {
                materials[neighbor] = lcm * to_rate * materials[neighbor] / materials[to];
            }
            
            materials[from] = lcm * from_rate;
            materials[to] = lcm * to_rate;
        }

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    long long int gcd = GCD(materials[0], materials[1]);
    for (long long int node = 2; node < N; node++) {
        gcd = GCD(materials[node], gcd);
    }

    for (long long int node = 0; node < N; node++) {
        materials[node] /= gcd;
        cout << materials[node] << " ";
    }

    return 0;
}