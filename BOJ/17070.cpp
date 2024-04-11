#include <iostream>
#include <vector>
using namespace std;

#define CELL 0
#define WALL 1

static int N;
static int count = 0;
vector<vector<int>> map;

static void DFS(int r, int c, int angle);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    map.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> map[r][c];
    
    DFS(0, 1, 0);

    cout << count;

    return 0;
}

static void DFS(int r, int c, int angle) {
    if (r == N - 1 && c == N - 1) {
        count++;
        return;
    }

    if (angle == 0) {
        // right
        if (c + 1 < N && map[r][c+1] == CELL)
            DFS(r, c+1, 0);

        // diagonal
        if (r + 1 < N && c + 1 < N && map[r][c+1] == CELL && map[r+1][c] == CELL && map[r+1][c+1] == CELL) {
            DFS(r+1, c+1, 45);
        }
    }
    if (angle == 45) {
        // right
        if (c + 1 < N && map[r][c+1] == CELL) {
            DFS(r, c+1, 0);
        }

        // down
        if (r + 1 < N && map[r+1][c] == CELL) {
            DFS(r+1, c, 90);
        }

        // diagonal
        if (r + 1 < N && c + 1 < N && map[r][c+1] == CELL && map[r+1][c] == CELL && map[r+1][c+1] == CELL) {
            DFS(r+1, c+1, 45);
        }
    }
    if (angle == 90) {
        // down
        if (r + 1 < N && map[r+1][c] == CELL) {
            DFS(r+1, c, 90);
        }

        // diagonal
        if (r + 1 < N && c + 1 < N && map[r][c+1] == CELL && map[r+1][c] == CELL && map[r+1][c+1] == CELL) {
            DFS(r+1, c+1, 45);
        }
    }
}