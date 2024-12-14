#include <bits/stdc++.h>
using namespace std;
typedef tuple<char, int, int> tup;

#define EMPTY   '.'
#define WALL    '#'
#define HALL    'O'
#define RED     'R'
#define BLUE    'B'

int N, M, limit;
vector<vector<char>> board;
queue<vector<vector<char>>> states;

inline bool checkRedOut(vector<vector<char>>& board);
inline bool checkBlueOut(vector<vector<char>>& board);
inline bool compareBoards(vector<vector<char>>& board1, vector<vector<char>> board2);
inline bool tiltLeft(vector<vector<char>>& board);
inline bool tiltRight(vector<vector<char>>& board);
inline bool tiltUp(vector<vector<char>>& board);
inline bool tiltDown(vector<vector<char>>& board);

inline void printBoard(vector<vector<char>>& board, string message) {
    cout << "----------------------------" << endl;
    cout << "BOARD STATUS: " << message << endl;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++)
            cout << board[r][c];
        cout << endl;
    }
    cout << "-----------------------------";
    cout << endl;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    board.resize(N, vector<char>(M));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> board[r][c];

    states.push(board);
    bool isCompleted = false;
    while (limit < 10 && !isCompleted) {
        limit++;
        int qSize = states.size();
        while (qSize--) {
            vector<vector<char>> temp;
            vector<vector<char>> curr = states.front();
            states.pop();

            temp = curr;
            if (tiltLeft(temp) && checkRedOut(temp)) {
                isCompleted = true;
                break;
            } else if (!compareBoards(temp, curr)) {
                states.push(temp);
            }

            temp = curr;
            if (tiltRight(temp) && checkRedOut(temp)) {
                isCompleted = true;
                break;
            } else if (!compareBoards(temp, curr)) {
                states.push(temp);
            }

            temp = curr;
            if (tiltUp(temp) && checkRedOut(temp)) {
                isCompleted = true;
                break;
            } else if (!compareBoards(temp, curr)) {
                states.push(temp);
            }

            temp = curr;
            if (tiltDown(temp) && checkRedOut(temp)) {
                isCompleted = true;
                break;
            } else if (!compareBoards(temp, curr)) {
                states.push(temp);
            }
        }
    }

    if (!isCompleted)
        cout << -1;
    else
        cout << limit;

    return 0;
}

inline bool checkRedOut(vector<vector<char>>& board) {
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (board[r][c] == RED)
                return false;
    return true;
}

inline bool checkBlueOut(vector<vector<char>>& board) {
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            if (board[r][c] == BLUE)
                return false;
    return true;
}

inline bool compareBoards(vector<vector<char>>& board1, vector<vector<char>> board2) {
    bool result = true;
    for (int r = 0; r < N && result; r++)
        for (int c = 0; c < M && result; c++)
            if (board1[r][c] != board2[r][c])
                result = false;
    return result;
}

inline bool tiltLeft(vector<vector<char>>& board) {
    stack<tup> stk;

    for (int r = 1; r < N - 1; r++)
        for (int c = M - 1; c > 0; c--)
            if (board[r][c] == RED || board[r][c] == BLUE)
                stk.push(make_tuple(board[r][c], r, c));

    while (!stk.empty()) {
        char b = get<0>(stk.top());
        int br = get<1>(stk.top());
        int bc = get<2>(stk.top());
        stk.pop();

        board[br][bc] = EMPTY;
        while (board[br][bc] != WALL && board[br][bc] != HALL && board[br][bc] != RED && board[br][bc] != BLUE)
            bc--;
        if (board[br][bc] != HALL)
            board[br][bc + 1] = b;
    }

    return !checkBlueOut(board);
}

inline bool tiltRight(vector<vector<char>>& board) {
    stack<tup> stk;

    for (int r = 1; r < N - 1; r++)
        for (int c = 1; c < M - 1; c++)
            if (board[r][c] == RED || board[r][c] == BLUE)
                stk.push(make_tuple(board[r][c], r, c));

    while (!stk.empty()) {
        char b = get<0>(stk.top());
        int br = get<1>(stk.top());
        int bc = get<2>(stk.top());
        stk.pop();

        board[br][bc] = EMPTY;
        while (board[br][bc] != WALL && board[br][bc] != HALL && board[br][bc] != RED && board[br][bc] != BLUE)
            bc++;
        if (board[br][bc] != HALL)
            board[br][bc - 1] = b;
    }

    return !checkBlueOut(board);
}

inline bool tiltUp(vector<vector<char>>& board) {
    stack<tup> stk;

    for (int c = 1; c < M - 1; c++)
        for (int r = N - 1; r > 0; r--)
            if (board[r][c] == RED || board[r][c] == BLUE)
                stk.push(make_tuple(board[r][c], r, c));

    while (!stk.empty()) {
        char b = get<0>(stk.top());
        int br = get<1>(stk.top());
        int bc = get<2>(stk.top());
        stk.pop();

        board[br][bc] = EMPTY;
        while (board[br][bc] != WALL && board[br][bc] != HALL && board[br][bc] != RED && board[br][bc] != BLUE)
            br--;
        if (board[br][bc] != HALL)
            board[br + 1][bc] = b;
    }

    return !checkBlueOut(board);
}

inline bool tiltDown(vector<vector<char>>& board) {
    stack<tup> stk;

    for (int c = 1; c < M - 1; c++)
        for (int r = 1; r < N - 1; r++)
            if (board[r][c] == RED || board[r][c] == BLUE)
                stk.push(make_tuple(board[r][c], r, c));

    while (!stk.empty()) {
        char b = get<0>(stk.top());
        int br = get<1>(stk.top());
        int bc = get<2>(stk.top());
        stk.pop();

        board[br][bc] = EMPTY;
        while (board[br][bc] != WALL && board[br][bc] != HALL && board[br][bc] != RED && board[br][bc] != BLUE)
            br++;
        if (board[br][bc] != HALL)
            board[br - 1][bc] = b;
    }

    return !checkBlueOut(board);
}