#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define CELL 0
#define WALL 1
#define VIRUS 2

static int dR[4] = { -1, 1, 0, 0 };
static int dC[4] = { 0, 0, -1, 1 };

static int N, M;
static vector<vector<int>> map;
static vector<vector<bool>> visited;
static vector<pair<int, int>> cells;
static vector<pair<int, int>> viruses;

static inline bool isValidPoint(int r, int c);
static inline int CellCount(vector<vector<int>>& map);
static inline int BFS();
static inline int BFS(pair<int, int>& loc1, pair<int, int>& loc2, pair<int, int>& loc3);

static inline void PrintMap(vector<vector<int>>& map) {
    if (CellCount(map) != 12) return;
    cout << "MAP WITH CELL " << CellCount(map) << '\n';
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++)
            cout << map[r][c] << ' ';
        cout << '\n';
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    map.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            cin >> map[r][c];
            switch (map[r][c]) {
                case CELL:
                    cells.push_back({r, c});
                    break;
                case VIRUS:
                    viruses.push_back({r, c});
                    break;
            }
        }

    int maximumSafe = 0;

    // (cells.size()) Combination 3
    for (int i = 0; i < cells.size(); i++)
        for (int j = i + 1; j < cells.size(); j++)
            for (int k = j + 1; k < cells.size(); k++)
                maximumSafe = max(maximumSafe, BFS(cells[i], cells[j], cells[k]));
    
    cout << maximumSafe;

    return 0;
}

static inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < M);
}

static inline int CellCount(vector<vector<int>>& map) {
    int count = 0;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (map[r][c] == CELL) count++;
    return count;
}

static inline int BFS() {
    fill(visited.begin(), visited.end(), vector<bool>(visited[0].size(), false));
    vector<vector<int>> copyMap = map;
    queue<pair<int, int>> bfsQueue;

    for (pair<int, int> virus : viruses) {
        visited[virus.first][virus.second] = true;
        bfsQueue.push({virus});
    }

    while (!bfsQueue.empty()) {
        int r = bfsQueue.front().first, c = bfsQueue.front().second;
        bfsQueue.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nextR = r + dR[dir], nextC = c + dC[dir];
            
            if (!isValidPoint(nextR, nextC))
                continue;

            if (!visited[nextR][nextC] && copyMap[nextR][nextC] == CELL) {
                visited[nextR][nextC] = true;
                copyMap[nextR][nextC] = VIRUS;
                bfsQueue.push({nextR, nextC});
            }
        }
    }

    return CellCount(copyMap);
}

static inline int BFS(pair<int, int>& loc1, pair<int, int>& loc2, pair<int, int>& loc3) {
    map[loc1.first][loc1.second] = WALL;
    map[loc2.first][loc2.second] = WALL;
    map[loc3.first][loc3.second] = WALL;
    int result = BFS();
    map[loc1.first][loc1.second] = CELL;
    map[loc2.first][loc2.second] = CELL;
    map[loc3.first][loc3.second] = CELL;
    return result;
}