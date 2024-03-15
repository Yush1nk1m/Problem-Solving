#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    vector<int> structures(N + 1);
    vector<int> degrees(N + 1, 0);
    vector<int> theFirsts;
    vector<int> times(N + 1, 0);
    queue<int> result;

    for (int i = 1; i <= N; i++) {
        int prior;

        cin >> structures[i];
        cin >> prior;
        while (prior != -1) {
            degrees[i]++;
            graph[prior].push_back(i);
            cin >> prior;
        }
    }

    for (int node = 1; node <= N; node++)
        if (degrees[node] == 0) {
            theFirsts.push_back(node);
        }
    
    for (int first : theFirsts) {
        result.push(first);
        times[first] = structures[first];
        while (!result.empty()) {
            int curr = result.front();
            result.pop();

            for (int neighbor : graph[curr]) {
                if (times[neighbor] < times[curr] + structures[neighbor]) {
                    times[neighbor] = times[curr] + structures[neighbor];
                }

                if (--degrees[neighbor] == 0)
                    result.push(neighbor);
            }
        }
    }

    for (int node = 1; node <= N; node++) {
        cout << times[node] << '\n';
    }

    return 0;
}