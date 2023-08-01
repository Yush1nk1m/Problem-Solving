#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> graph;
int N;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> N;
    graph.resize(N, vector<bool>(N, false));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int temp;
            cin >> temp;
            graph[r][c] = static_cast<bool>(temp);
        }
    }

    for (int m = 0; m < N; m++) {
        for (int s = 0; s < N; s++) {
            for (int e = 0; e < N; e++) {
                graph[s][e] = (graph[s][e]) || (graph[s][m] && graph[m][e]);
            }
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << graph[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}