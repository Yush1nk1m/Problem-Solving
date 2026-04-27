class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int sr = 0; sr < 3; ++sr)
            for (int sc = 0; sc < 3; ++sc) {
                int mask = 0;
                for (int r = sr * 3; r < sr * 3 + 3; ++r)
                    for (int c = sc * 3; c < sc * 3 + 3; ++c) {
                        if (board[r][c] == '.')
                            continue;
                        else if ((mask & (1 << (int) (board[r][c] - '1'))) != 0)
                            return false;
                        mask |= 1 << (int) (board[r][c] - '1');
                    }
            }
        for (int i = 0; i < 9; ++i) {
            int rowMask = 0, colMask = 0;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if ((rowMask & (1 << (int) (board[i][j] - '1'))) != 0)
                        return false;
                    rowMask |= 1 << (int) (board[i][j] - '1');
                }
                if (board[j][i] != '.') {
                    if ((colMask & (1 << (int) (board[j][i] - '1'))) != 0)
                        return false;
                    colMask |= 1 << (int) (board[j][i] - '1');
                }
            }
        }

        return true;
    }
}
