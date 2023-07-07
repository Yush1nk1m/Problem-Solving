#include <iostream>
#include <vector>
using namespace std;

#define UP      0
#define RIGHT   1
#define DOWN    2
#define LEFT    3

vector<vector<int>> tile;
vector<vector<bool>> cleaned;

int N, M, r, c, d, result;

bool Check(int r, int c) {
    if ((tile[r - 1][c] != 1 && cleaned[r - 1][c] == false) ||
        (tile[r + 1][c] != 1 && cleaned[r + 1][c] == false) ||
        (tile[r][c - 1] != 1 && cleaned[r][c - 1] == false) ||
        (tile[r][c + 1] != 1 && cleaned[r][c + 1] == false))
        return true;
    return false;
}

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    tile.resize(N, vector<int>(M));
    cleaned.resize(N, vector<bool>(M, false));

    cin >> r >> c >> d;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> tile[r][c];
    
    while (1) {
        if (cleaned[r][c] == false) {
            cleaned[r][c] = true;
            result++;
        }
        if (Check(r, c)) {
            d--;
            if (d < 0) d = 3;
            switch (d) {
                case UP:
                    if (tile[r - 1][c] != 1 && cleaned[r - 1][c] == false) r--;
                    break;
                case LEFT:
                    if (tile[r][c - 1] != 1 && cleaned[r][c - 1] == false) c--;
                    break;
                case DOWN:
                    if (tile[r + 1][c] != 1 && cleaned[r + 1][c] == false) r++;
                    break;
                case RIGHT:
                    if (tile[r][c + 1] != 1 && cleaned[r][c + 1] == false) c++;
                    break;
            }
        }
        else {
            int back_direction = (d + 2) % 4;
            bool termination = false;
            switch (back_direction) {
                case UP:
                    if (tile[r - 1][c] == 1) termination = true;
                    else r--;
                    break;
                case LEFT:
                    if (tile[r][c - 1] == 1) termination = true;
                    else c--;
                    break;
                case DOWN:
                    if (tile[r + 1][c] == 1) termination = true;
                    else r++;
                    break;
                case RIGHT:
                    if (tile[r][c + 1] == 1) termination = true;
                    else c++;
                    break;
            }
            if (termination == true) break;
        }
    }

    cout << result << endl;

    return 0;
}