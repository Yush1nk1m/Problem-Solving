#include <iostream>
#include <vector>
using namespace std;

static int board[9][9];
static vector<pair<int, int>> unvisited;
static bool solved = false;

inline bool CheckDuplication(int row, int col, int value);
void Sudoku(int index);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char value;
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++) {
            cin >> value;
            board[r][c] = value - '0';
            if (!board[r][c])
                unvisited.push_back({ r, c });
        }
    
    Sudoku(0);

    return 0;
}

inline bool CheckDuplication(int row, int col, int value) {
    bool isDuplicated = false;

    for (int i = 0; i < 9 && !isDuplicated; i++) {
        if (board[i][col] == value)
            isDuplicated = true;
        if (board[row][i] == value)
            isDuplicated = true;
    }

    for (int r = (row / 3) * 3; r < (row / 3) * 3 + 3 && !isDuplicated; r++)
        for (int c = (col / 3) * 3; c < (col / 3) * 3 + 3 && !isDuplicated; c++)
            if (board[r][c] == value)
                isDuplicated = true;

    return isDuplicated;
}

void Sudoku(int index) {
    if (index == unvisited.size()) {
        solved = true;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++)
                cout << board[r][c];
            cout << '\n';
        }

        return;
    }

    int r = unvisited[index].first;
    int c = unvisited[index].second;

    for (int number = 1; number <= 9 && !solved; number++) {
        if (!CheckDuplication(r, c, number)) {
            board[r][c] = number;
            Sudoku(index + 1);
            board[r][c] = 0;
        }
    }
}