#include <iostream>
#include <vector>
using namespace std;

static int R, C;
static int dR[4] = { -1, 1, 0, 0 };
static int dC[4] = { 0, 0, -1, 1 };

static vector<vector<char>> board;
static vector<vector<bool>> visitedCell;
static vector<bool> visitedAlphabet;

static inline bool isValidPoint(int r, int c);
static int DFS(int r, int c);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    visitedAlphabet.resize('Z' - 'A' + 1, false);
    visitedCell.resize(R, vector<bool>(C, false));
    board.resize(R, vector<char>(C));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            cin >> board[r][c];

    cout << DFS(0, 0);

    return 0;
}

static inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < R && 0 <= c && c < C);
}

static int DFS(int r, int c) {
    visitedCell[r][c] = true;
    visitedAlphabet[board[r][c] - 'A'] = true;

    int result = 0;
    for (int dir = 0; dir < 4; dir++) {
        int nextR = r + dR[dir], nextC = c + dC[dir];
        if (!isValidPoint(nextR, nextC)) continue;

        if (!visitedCell[nextR][nextC] && !visitedAlphabet[board[nextR][nextC] - 'A']) {
            result = max(result, DFS(nextR, nextC));
            visitedCell[nextR][nextC] = false;
            visitedAlphabet[board[nextR][nextC] - 'A'] = false;
        }
    }

    return result + 1;
}