#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, years;
int total_ice;
int ice_rbegin = -1, ice_cbegin = -1;     // 빙산이 처음 등장하는 행과 열
int ice_rend = -1, ice_cend = -1;         // 빙산이 마지막으로 등장하는 행과 열

vector<vector<bool>> visited;
vector<vector<bool>> visited_copy;
queue<pair<int, int>> coords;
vector<vector<int>> iceberg;

inline int meltdown(int r, int c) {
    int result = 0;

    if (r > 0 && iceberg[r-1][c] == 0) result++;
    if (r < N - 1 && iceberg[r+1][c] == 0) result++;
    if (c > 0 && iceberg[r][c-1] == 0) result++;
    if (c < M - 1 && iceberg[r][c+1] == 0) result++;

    return result;
}

inline int bfs(int r, int c) {
    int connected = 0;

    visited_copy = visited;

    coords.push({r, c});
    visited_copy[r][c] = true;
    connected++;

    while (!coords.empty()) {
        int row = coords.front().first;
        int col = coords.front().second;
        coords.pop();

        if (row > 0 && !visited_copy[row-1][col]) {
            visited_copy[row-1][col] = true;
            coords.push({row-1, col});
            connected++;
        }
        if (row < N - 1 && !visited_copy[row+1][col]) {
            visited_copy[row+1][col] = true;
            coords.push({row+1, col});
            connected++;
        }
        if (col > 0 && !visited_copy[row][col-1]) {
            visited_copy[row][col-1] = true;
            coords.push({row, col-1});
            connected++;
        }
        if (col < M - 1 && !visited_copy[row][col+1]) {
            visited_copy[row][col+1] = true;
            coords.push({row, col+1});
            connected++;
        }
    }

    return connected;
}

int main(int argc, char* argv[]) {
    cin >> N >> M;
    
    visited.resize(N, vector<bool>(M));
    iceberg.resize(N, vector<int>(M));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> iceberg[r][c];
            if (iceberg[r][c]) total_ice++;
            visited[r][c] = !iceberg[r][c];
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (iceberg[r][c] != 0) {
                ice_rbegin = r;
                ice_cbegin = c;
                break;
            }
        }
        if (ice_rbegin != -1) break;
    }

    for (int r = N - 1; r >= 0; r--) {
        for (int c = M - 1; c >= 0; c--) {
            if (iceberg[r][c] != 0) {
                ice_rend = r;
                ice_cend = c;
                break;
            }
        }
        if (ice_rend != -1) break;
    }

    if (total_ice != 0 && bfs(ice_rend, ice_cend) != total_ice) {
        cout << years;
        return 0;
    }
    
    while (ice_rbegin <= ice_rend || ice_cbegin <= ice_cend) {
        years++;

        bool destructed = false;

        for (int r = ice_rbegin; r <= ice_rend; r++) {
            for (int c = 0; c < M; c++) {
                if (iceberg[r][c] > 0) {
                    int melt = meltdown(r, c);
                    iceberg[r][c] -= melt;

                    if (iceberg[r][c] <= 0) {
                        iceberg[r][c] = -1;
                        visited[r][c] = true;
                        total_ice--;
                        destructed = true;
                    }

                }
            }
        }

        for (int r = ice_rbegin; r <= ice_rend; r++)
            for (int c = 0; c < M; c++)
                if (iceberg[r][c] == -1) iceberg[r][c] = 0;

        if (destructed) {
            bool term = false;

            for (int r = ice_rbegin; r < N; r++) {
                for (int c = 0; c < M; c++) {
                    ice_rbegin = r;
                    ice_cbegin = c;

                    if (iceberg[r][c]) {
                        term = true;
                        break;
                    }
                }
                if (term) break;
            }

            term = false;
            for (int r = ice_rend; r >= 0; r--) {
                for (int c = M - 1; c >= 0; c--) {
                    ice_rend = r;
                    ice_cend = c;

                    if (iceberg[r][c]) {
                        term = true;
                        break;
                    }
                }
                if (term) break;
            }

            if (total_ice != 0 && bfs(ice_rend, ice_cend) != total_ice) {
                cout << years;
                return 0;
            }

        }
    }

    cout << 0;
    return 0;
}