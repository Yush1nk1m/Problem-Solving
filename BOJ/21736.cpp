#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<char>> map;
vector<vector<bool>> visited;
queue<pair<int, int>> coords;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> N >> M;
    map.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> map[r][c];

            if (map[r][c] == 'X') visited[r][c] = true;
            else if (map[r][c] == 'I') {
                coords.push({r, c});
                visited[r][c] = true;
            }
        }
    }

    int result = 0;
    while (!coords.empty()) {
        int r = coords.front().first, c = coords.front().second;
        coords.pop();

        if (map[r][c] == 'P') result++;

        if (r - 1 >= 0 && !visited[r-1][c]) {
            visited[r-1][c] = true;
            coords.push({r-1, c});
        }
        if (r + 1 < N && !visited[r+1][c]) {
            visited[r+1][c] = true;
            coords.push({r+1, c});
        }
        if (c - 1 >= 0 && !visited[r][c-1]) {
            visited[r][c-1] = true;
            coords.push({r, c-1});
        }
        if (c + 1 < M && !visited[r][c+1]) {
            visited[r][c+1] = true;
            coords.push({r, c+1});
        }
    }

    if (result == 0) cout << "TT";
    else cout << result;

    return 0;
}