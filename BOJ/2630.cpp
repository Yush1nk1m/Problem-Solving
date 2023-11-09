#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> paper;
int N, zero_result, one_result;

// (row, col)을 좌상단 꼭짓점으로 하는 N * N 색종이 분할 문제
inline void SplitPaper(int row, int col, int N) {
    bool all_zero = true, all_one = true;
    for (int r = row; r < row + N; r++) {
        for (int c = col; c < col + N; c++) {
            if (paper[r][c] == 0) all_one = false;
            if (paper[r][c] == 1) all_zero = false;
        }
    }

    if (all_zero) zero_result++;
    else if (all_one) one_result++;
    else {
        SplitPaper(row, col, N / 2);
        SplitPaper(row, col + N / 2, N / 2);
        SplitPaper(row + N / 2, col, N / 2);
        SplitPaper(row + N / 2, col + N / 2, N / 2);
    }
}

int main(int argc, char* argv[]) {
    cin >> N;
    paper.resize(N, vector<int>(N));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++)
            cin >> paper[r][c];
    }

    SplitPaper(0, 0, N);

    cout << zero_result << '\n' << one_result;

    return 0;
}