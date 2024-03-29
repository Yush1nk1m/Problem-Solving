#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

#define NONBROKEN 0
#define BROKEN 1
#define INF 100000000

static inline int BFS(vector<vector<bool>>& map, int N, int M);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> map(N, vector<bool>(M, false));

    for (int r = 0; r < N; r++) {
        string line;
        cin >> line;

        for (int c = 0; c < M; c++) {
            if (line[c] == '1')
                map[r][c] = true;
        }
    }

    cout << BFS(map, N, M);

    return 0;
}

static inline int BFS(vector<vector<bool>>& map, int N, int M) {
    vector<vector<vector<int>>> distance(2, vector<vector<int>>(N, vector<int>(M, INF)));
    vector<vector<vector<bool>>> visited(2, vector<vector<bool>>(N, vector<bool>(M, false)));

    queue<tuple<int, int, int>> bfsQueue;
    
    visited[NONBROKEN][0][0] = true;
    distance[NONBROKEN][0][0] = 1;
    bfsQueue.push(make_tuple(NONBROKEN, 0, 0));

    while (!bfsQueue.empty()) {
        tuple<int, int, int> curr = bfsQueue.front();
        bfsQueue.pop();

        int isBroken = get<0>(curr), r = get<1>(curr), c = get<2>(curr);

        // range check & wall check & visited check
        if (r - 1 >= 0 && !map[r-1][c] && !visited[isBroken][r-1][c]) {
            visited[isBroken][r-1][c] = true;
            distance[isBroken][r-1][c] = distance[isBroken][r][c] + 1;
            bfsQueue.push(make_tuple(isBroken, r-1, c));
        }
        if (c - 1 >= 0 && !map[r][c-1] && !visited[isBroken][r][c-1]) {
            visited[isBroken][r][c-1] = true;
            distance[isBroken][r][c-1] = distance[isBroken][r][c] + 1;
            bfsQueue.push(make_tuple(isBroken, r, c-1));
        }
        if (r + 1 < N && !map[r+1][c] && !visited[isBroken][r+1][c]) {
            visited[isBroken][r+1][c] = true;
            distance[isBroken][r+1][c] = distance[isBroken][r][c] + 1;
            bfsQueue.push(make_tuple(isBroken, r+1, c));
        }
        if (c + 1 < M && !map[r][c+1] && !visited[isBroken][r][c+1]) {
            visited[isBroken][r][c+1] = true;
            distance[isBroken][r][c+1] = distance[isBroken][r][c] + 1;
            bfsQueue.push(make_tuple(isBroken, r, c+1));
        }

        // check if there's a wall to jump over
        if (!isBroken) {
            if (r - 2 >= 0 && map[r-1][c] && !map[r-2][c] && !visited[BROKEN][r-2][c]) {
                visited[BROKEN][r-2][c] = true;
                distance[BROKEN][r-2][c] = distance[NONBROKEN][r][c] + 2;
                bfsQueue.push(make_tuple(BROKEN, r-2, c));
            }
            if (c - 2 >= 0 && map[r][c-1] && !map[r][c-2] && !visited[BROKEN][r][c-2]) {
                visited[BROKEN][r][c-2] = true;
                distance[BROKEN][r][c-2] = distance[NONBROKEN][r][c] + 2;
                bfsQueue.push(make_tuple(BROKEN, r, c-2));
            }
            if (r + 2 < N && map[r+1][c] && !map[r+2][c] && !visited[BROKEN][r+2][c]) {
                visited[BROKEN][r+2][c] = true;
                distance[BROKEN][r+2][c] = distance[NONBROKEN][r][c] + 2;
                bfsQueue.push(make_tuple(BROKEN, r+2, c));
            }
            if (c + 2 < M && map[r][c+1] && !map[r][c+2] && !visited[BROKEN][r][c+2]) {
                visited[BROKEN][r][c+2] = true;
                distance[BROKEN][r][c+2] = distance[NONBROKEN][r][c] + 2;
                bfsQueue.push(make_tuple(BROKEN, r, c+2));
            }
        }
    }

    if (distance[NONBROKEN][N-1][M-1] == INF && distance[BROKEN][N-1][M-1] == INF)
        return -1;
    else
        return min(distance[NONBROKEN][N-1][M-1], distance[BROKEN][N-1][M-1]);
}