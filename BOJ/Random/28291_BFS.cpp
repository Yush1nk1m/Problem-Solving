/**
 * @file 28291_BFS.cpp
 * @brief 00:16:04
 * @date 2024-11-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE        0
#define BLOCK       1
#define DUST        2
#define LAMP_OFF    3
#define LAMP_ON     4

int W, H, N;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
vector<vector<int>> circuit, visited;
vector<pair<int, int>> lamps;
queue<pair<int, int>> q;

inline bool isValidPoint(int r, int c) {
    return 0 <= r && r < H && 0 <= c && c < W;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> W >> H;
    circuit.resize(H, vector<int>(W, NONE));
    visited.resize(H, vector<int>(W, 0));
    
    cin >> N;
    while (N--) {
        string type;
        int r, c;

        cin >> type >> c >> r;
        if (type == "redstone_block") {
            circuit[r][c] = BLOCK;
            visited[r][c] = 16;
            q.push({ r, c });
        }
        else if (type == "redstone_dust")
            circuit[r][c] = DUST;
        else if (type == "redstone_lamp") {
            circuit[r][c] = LAMP_OFF;
            lamps.push_back({ r, c });
        }
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int nextPower = visited[curr.first][curr.second] - 1;
        if (nextPower <= 0) continue;

        for (int d = 0; d < 4; d++) {
            int r = curr.first + dr[d], c = curr.second + dc[d];
            if (!isValidPoint(r, c) || circuit[r][c] == NONE || nextPower <= visited[r][c])
                continue;

            if (circuit[r][c] == LAMP_OFF) {
                circuit[r][c] = LAMP_ON;
                continue;
            }

            visited[r][c] = nextPower;
            q.push({ r, c });
        }
    }

    for (pair<int, int> loc : lamps)
        if (circuit[loc.first][loc.second] == LAMP_OFF) {
            cout << "failed";
            return 0;
        }
    cout << "success";
    return 0;
}