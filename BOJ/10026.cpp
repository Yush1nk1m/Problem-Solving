#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<char>> screen;
vector<vector<bool>> visited;
vector<vector<bool>> color_blind_visited;

inline void BFS(int r, int c);
inline void colorBlindBFS(int r, int c);

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> N;
    screen.resize(N, vector<char>(N));
    visited.resize(N, vector<bool>(N, false));
    color_blind_visited.resize(N, vector<bool>(N, false));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> screen[r][c];
    
    int result1, result2;
    result1 = result2 = 0;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            if (!visited[r][c]) {
                result1++;
                BFS(r, c);
            }
            if (!color_blind_visited[r][c]) {
                result2++;
                colorBlindBFS(r, c);
            }
        }
    
    cout << result1 << ' ' << result2;

    return 0;
}

inline void BFS(int r, int c) {
    char color = screen[r][c];

    queue<pair<int, int>> bfs_queue;
    bfs_queue.push({r, c});
    visited[r][c] = true;

    while (!bfs_queue.empty()) {
        int row = bfs_queue.front().first, col = bfs_queue.front().second;
        bfs_queue.pop();

        if (row - 1 >= 0 && screen[row-1][col] == color && !visited[row-1][col]) {
            visited[row-1][col] = true;
            bfs_queue.push({row-1, col});
        }
        if (row + 1 <= N - 1 && screen[row+1][col] == color && !visited[row+1][col]) {
            visited[row+1][col] = true;
            bfs_queue.push({row+1, col});
        }
        if (col - 1 >= 0 && screen[row][col-1] == color && !visited[row][col-1]) {
            visited[row][col-1] = true;
            bfs_queue.push({row, col-1});
        }
        if (col + 1 <= N - 1 && screen[row][col+1] == color && !visited[row][col+1]) {
            visited[row][col+1] = true;
            bfs_queue.push({row, col+1});
        }
    }
}

inline void colorBlindBFS(int r, int c) {
    char color1 = screen[r][c];
    char color2;
    if (color1 == 'R') color2 = 'G';
    else if (color1 == 'G') color2 = 'R';
    else color2 = 'B';

    queue<pair<int, int>> bfs_queue;
    bfs_queue.push({r, c});
    color_blind_visited[r][c] = true;

    while (!bfs_queue.empty()) {
        int row = bfs_queue.front().first, col = bfs_queue.front().second;
        bfs_queue.pop();

        if (row - 1 >= 0 && (screen[row-1][col] == color1 || screen[row-1][col] == color2) && !color_blind_visited[row-1][col]) {
            color_blind_visited[row-1][col] = true;
            bfs_queue.push({row-1, col});
        }
        if (row + 1 <= N - 1 && (screen[row+1][col] == color1 || screen[row+1][col] == color2) && !color_blind_visited[row+1][col]) {
            color_blind_visited[row+1][col] = true;
            bfs_queue.push({row+1, col});
        }
        if (col - 1 >= 0 && (screen[row][col-1] == color1 || screen[row][col-1] == color2) && !color_blind_visited[row][col-1]) {
            color_blind_visited[row][col-1] = true;
            bfs_queue.push({row, col-1});
        }
        if (col + 1 <= N - 1 && (screen[row][col+1] == color1 || screen[row][col+1] == color2) && !color_blind_visited[row][col+1]) {
            color_blind_visited[row][col+1] = true;
            bfs_queue.push({row, col+1});
        }
    }
}