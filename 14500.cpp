#include <iostream>
#include <vector>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

vector<vector<int>> paper;
int N, M;

inline int findMaxTetromino(int r, int c) {
    int sum = 0;
    
    if (r + 3 < N) {
        sum = paper[r][c] + paper[r+1][c] + paper[r+2][c] + paper[r+3][c];
    }
    if (r + 2 < N && c + 1 < M) {
        int tempsum = paper[r][c] + paper[r+1][c] + paper[r+2][c];
        tempsum += MAX(paper[r][c+1], MAX(paper[r+1][c+1], paper[r+2][c+1]));

        sum = MAX(sum, tempsum);

        tempsum = paper[r][c+1] + paper[r+1][c+1] + paper[r+2][c+1];
        tempsum += MAX(paper[r][c], MAX(paper[r+1][c], paper[r+2][c]));

        sum = MAX(sum, tempsum);

        tempsum = paper[r+1][c] + paper[r+1][c+1];
        tempsum += MAX(paper[r][c] + paper[r+2][c+1], paper[r][c+1] + paper[r+2][c]);

        sum = MAX(sum, tempsum);
    }
    if (r + 1 < N && c + 1 < M) {
        int tempsum = paper[r][c] + paper[r][c+1] + paper[r+1][c] + paper[r+1][c+1];

        sum = MAX(sum, tempsum);
    }
    if (r + 1 < N && c + 2 < M) {
        int tempsum = paper[r][c] + paper[r][c+1] + paper[r][c+2];
        tempsum += MAX(paper[r+1][c], MAX(paper[r+1][c+1], paper[r+1][c+2]));

        sum = MAX(sum, tempsum);

        tempsum = paper[r+1][c] + paper[r+1][c+1] + paper[r+1][c+2];
        tempsum += MAX(paper[r][c], MAX(paper[r][c+1], paper[r][c+2]));

        sum = MAX(sum, tempsum);

        tempsum = paper[r][c+1] + paper[r+1][c+1];
        tempsum += MAX(paper[r][c] + paper[r+1][c+2], paper[r+1][c] + paper[r][c+2]);

        sum = MAX(sum, tempsum);
    }
    if (c + 3 < M) {
        int tempsum = paper[r][c] + paper[r][c+1] + paper[r][c+2] + paper[r][c+3];

        sum = MAX(sum, tempsum);
    }

    return sum;
}

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> N >> M;
    paper.resize(N, vector<int>(M));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> paper[r][c];
        }
    }

    int result = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int tempsum = findMaxTetromino(r, c);

            if (result < tempsum) result = tempsum;
        }
    }

    cout << result;

    return 0;
}