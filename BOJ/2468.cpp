#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> safe_region;
vector<vector<bool>> visited;
vector<vector<int>> region;

int max_height = 0, min_height = 101;
int safe_number, max_safe;
int N;

inline void check(int r, int c) {
    safe_region.push({r, c});
    visited[r][c] = true;

    while (!safe_region.empty()) {
        int temp_r = safe_region.front().first;
        int temp_c = safe_region.front().second;

        safe_region.pop();

        if (temp_r - 1 >= 0 && !visited[temp_r - 1][temp_c]) {
            visited[temp_r - 1][temp_c] = true;
            safe_region.push({temp_r - 1, temp_c});
        }
        if (temp_r + 1 < N && !visited[temp_r + 1][temp_c]) {
            visited[temp_r + 1][temp_c] = true;
            safe_region.push({temp_r + 1, temp_c});
        }
        if (temp_c - 1 >= 0 && !visited[temp_r][temp_c - 1]) {
            visited[temp_r][temp_c - 1] = true;
            safe_region.push({temp_r, temp_c - 1});
        }
        if (temp_c + 1 < N && !visited[temp_r][temp_c + 1]) {
            visited[temp_r][temp_c + 1] = true;
            safe_region.push({temp_r, temp_c + 1});
        }
    }
}

int main(int argc, char* argv[]) {
    cin >> N;

    region.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> region[r][c];
            if (region[r][c] > max_height) max_height = region[r][c];
            if (region[r][c] < min_height) min_height = region[r][c];
        }
    }

    for (int height = min_height - 1; height < max_height; height++) {
        safe_number = 0;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (region[r][c] <= height)
                    visited[r][c] = true;
                else
                    visited[r][c] = false;
            }
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (!visited[r][c]) {
                    check(r, c);
                    safe_number++;
                }
            }
        }

        if (max_safe < safe_number) max_safe = safe_number;
    }

    cout << max_safe;

    return 0;
}