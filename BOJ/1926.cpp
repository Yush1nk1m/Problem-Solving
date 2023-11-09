#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, max_size, picture_num;
vector<vector<int>> paper;
vector<vector<bool>> visited;

inline int bfs(int r, int c) {
    int result = 0;
    queue<pair<int, int>> picture;

    picture.push({r, c});
    visited[r][c] = true;
    
    while (!picture.empty()) {
        int row = picture.front().first;
        int col = picture.front().second;
        picture.pop();
        result++;

        if (row - 1 >= 0 && !visited[row - 1][col]) {
            visited[row - 1][col] = true;
            picture.push({row - 1, col});
        }
        if (row + 1 < n && !visited[row + 1][col]) {
            visited[row + 1][col] = true;
            picture.push({row + 1, col});
        }
        if (col - 1 >= 0 && !visited[row][col - 1]) {
            visited[row][col - 1] = true;
            picture.push({row, col - 1});
        }
        if (col + 1 < m && !visited[row][col + 1]) {
            visited[row][col + 1] = true;
            picture.push({row, col + 1});
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    paper.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> paper[r][c];
            if (paper[r][c] == 0) visited[r][c] = true;
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (visited[r][c] == false) {
                picture_num++;
                int temp = bfs(r, c);
                if (temp > max_size) max_size = temp;
            }
        }
    }

    cout << picture_num << '\n' << max_size;

    return 0;
}