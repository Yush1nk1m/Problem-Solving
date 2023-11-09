#include <iostream>
#include <vector>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int M, N;
vector<vector<char>> board;
int case1[8][8], case2[8][8];
int case1_res, case2_res;
int result = 2147483647;

int main(int argc, char* argv[]) {
    cin >> M >> N;

    board.resize(M, vector<char>(N));

    for (int r = 0; r < M; r++)
        for (int c = 0; c < N; c++)
            cin >> board[r][c];
    
    for (int startr = 0; startr <= M - 8; startr++) {
        for (int startc = 0; startc <= N - 8; startc++) {
            case1_res = case2_res = 0;

            for (int r = 0; r < 8; r++)
                for (int c = 0; c < 8; c++)
                    case1[r][c] = case2[r][c] = board[startr + r][startc + c];
            
            for (int r = 0; r < 8; r++) {
                for (int c = 0; c < 8; c++) {
                    if ((r % 2 == 0 && c % 2 == 0) || (r % 2 == 1 && c % 2 == 1)) {
                        if (case1[r][c] != 'B') case1_res++;
                        if (case2[r][c] != 'W') case2_res++;
                    }
                    else {
                        if (case1[r][c] != 'W') case1_res++;
                        if (case2[r][c] != 'B') case2_res++;
                    }
                }
            }

            if (MIN(case1_res, case2_res) < result)
                result = MIN(case1_res, case2_res);
        }
    }

    cout << result;
    
    return 0;
}