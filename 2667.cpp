#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<char>> Map;
vector<vector<bool>> visited;
queue<pair<int, int>> bfs_tree;
vector<int> houses;
int N, complex;

inline int bfs(int r, int c) {
    int house_number = 0;
    complex++;

    visited[r][c] = true;
    bfs_tree.push({r, c});
    house_number++;
    
    while (!bfs_tree.empty()) {
        pair<int, int> temp = bfs_tree.front();
        bfs_tree.pop();
        int row = temp.first, col = temp.second;
        if (row > 0 && !visited[row - 1][col]) {
            visited[row - 1][col] = true;
            bfs_tree.push({row - 1, col});
            house_number++;
        }
        if (row < N - 1 && !visited[row + 1][col]) {
            visited[row + 1][col] = true;
            bfs_tree.push({row + 1, col});
            house_number++;
        }
        if (col > 0 && !visited[row][col - 1]) {
            visited[row][col - 1] = true;
            bfs_tree.push({row, col - 1});
            house_number++;
        }
        if (col < N - 1 && !visited[row][col + 1]) {
            visited[row][col + 1] = true;
            bfs_tree.push({row, col + 1});
            house_number++;
        }
    }

    return house_number;
}

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    Map.resize(N, vector<char>(N, 0));
    visited.resize(N, vector<bool>(N, false));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> Map[r][c];
            if (Map[r][c] == '0') visited[r][c] = true;
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (!visited[r][c]) {
                houses.push_back(bfs(r, c));
            }
        }
    }

    sort(houses.begin(), houses.end());

    cout << complex << '\n';
    for (int i = 0; i < houses.size(); i++) {
        cout << houses[i] << '\n';
    }

    return 0;
}