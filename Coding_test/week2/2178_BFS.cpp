#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, M;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
vector<vector<char>> maze;
vector<vector<bool>> visited;
vector<vector<int>> dist;

inline bool isValidPoint(int r, int c);
inline int BFS();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    maze.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));
    dist.resize(N, vector<int>(M, 0));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            cin >> maze[r][c];
            visited[r][c] = !(maze[r][c] - '0');
        }

    cout << BFS();

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < M);
}

inline int BFS() {
    queue<pair<int, int>> q;

    visited[0][0] = true;
    dist[0][0] = 1;
    q.push({ 0, 0 });
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nextr = curr.first + dr[dir], nextc = curr.second + dc[dir];
            if (isValidPoint(nextr, nextc) && !visited[nextr][nextc]) {
                visited[nextr][nextc] = true;
                dist[nextr][nextc] = dist[curr.first][curr.second] + 1;
                if (nextr == N - 1 && nextc == M - 1) return dist[nextr][nextc];
                q.push({ nextr, nextc });
            }
        }
    }

    return INF;
}