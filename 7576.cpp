#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<bool>> visited;
queue<pair<int, int>> ripens;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> M >> N;
    visited.resize(N, vector<bool>(M, false));

    int tomato_number = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int temp;
            cin >> temp;

            if (temp == 0) tomato_number++;
            else {
                visited[r][c] = true;
                if (temp == 1) ripens.push({r, c});
            }
        }
    }

    int day = -1;
    while (!ripens.empty()) {
        day++;

        int size = ripens.size();

        for (int _ = 0; _ < size; _++) {
            int r = ripens.front().first, c = ripens.front().second;
            ripens.pop();

            if (r - 1 >= 0 && !visited[r-1][c]) {
                visited[r-1][c] = true;
                ripens.push({r-1, c});
                tomato_number--;
            }
            if (r + 1 <= N - 1 && !visited[r+1][c]) {
                visited[r+1][c] = true;
                ripens.push({r+1, c});
                tomato_number--;
            }
            if (c - 1 >= 0 && !visited[r][c-1]) {
                visited[r][c-1] = true;
                ripens.push({r, c-1});
                tomato_number--;
            }
            if (c + 1 <= M - 1 && !visited[r][c+1]) {
                visited[r][c+1] = true;
                ripens.push({r, c+1});
                tomato_number--;
            }
        }
    }

    if (tomato_number == 0) cout << day;
    else cout << -1;

    return 0;
}