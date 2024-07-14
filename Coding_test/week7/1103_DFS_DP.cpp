#include <bits/stdc++.h>
using namespace std;

#define HOLE    'H'

int N, M, maxt;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
vector<vector<char>> board;
vector<vector<bool>> visited;
vector<vector<int>> cnt;

inline bool CheckValidPoint(int r, int c);
int DFS(int r, int c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    board.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));
    cnt.resize(N, vector<int>(M, 0));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> board[r][c];

    cout << DFS(0, 0);

    return 0;
}

inline bool CheckValidPoint(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < M && board[r][c] != HOLE);
}

int DFS(int r, int c) {
    if (!CheckValidPoint(r, c))
        return 0;
    if (visited[r][c]) {
        cout << -1;
        exit(0);
    }
    if (cnt[r][c] > 0)
        return cnt[r][c];

    int jmp = board[r][c] - '0';
    visited[r][c] = true;
    for (int d = 0; d < 4; d++) {
        int nr = r + (dr[d] * jmp), nc = c + (dc[d] * jmp);
        cnt[r][c] = max(cnt[r][c], DFS(nr, nc) + 1);        
    }
    visited[r][c] = false;

    return cnt[r][c];
}