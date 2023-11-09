#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> distances;
queue<pair<int, int>> coords;
int n, m;
int target_r, target_c;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;

    visited.resize(n, vector<bool>(m, false));
    distances.resize(n, vector<int>(m, -1));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int option;
            cin >> option;

            if (option == 0) {
                visited[r][c] = true;
                distances[r][c] = 0;
            }
            else if (option == 2) {
                target_r = r;
                target_c = c;

                distances[r][c] = 0;
                visited[r][c] = true;

                coords.push({r, c});
            }
        }
    }

    int distance = 0;
    while (!coords.empty()) {
        int num_of_same_distance = coords.size();

        for (int _ = 0; _ < num_of_same_distance; _++) {
            int r = coords.front().first, c = coords.front().second;
            coords.pop();
            distances[r][c] = distance;

            if (r - 1 >= 0 && !visited[r-1][c]) {
                visited[r-1][c] = true;
                coords.push({r-1, c});
            }
            if (r + 1 <= n - 1 && !visited[r+1][c]) {
                visited[r+1][c] = true;
                coords.push({r+1, c});
            }
            if (c - 1 >= 0 && !visited[r][c-1]) {
                visited[r][c-1] = true;
                coords.push({r, c-1});
            }
            if (c + 1 <= m - 1 && !visited[r][c+1]) {
                visited[r][c+1] = true;
                coords.push({r, c+1});
            }
        }

        distance++;
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cout << distances[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}