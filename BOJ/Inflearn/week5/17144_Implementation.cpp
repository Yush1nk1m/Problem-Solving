/**
 * @file 17144_Implementation.cpp
 * @brief 00:44:44
 * @date 2024-07-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define CLEANER -1
#define UP      0
#define DOWN    1

int R, C, T;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
vector<vector<int>> room;
vector<pair<int, int>> cleaner;
vector<pair<int, int>> route[2];

inline bool isValidPoint(int r, int c);
inline void InitializeWindRoute();
inline void Spread();
inline void Clean();
inline int Count();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;
    room.resize(R, vector<int>(C));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            cin >> room[r][c];
    
    for (int r = 0; r < R; r++)
        if (room[r][0] == CLEANER)
            cleaner.push_back({ r, 0 });

    InitializeWindRoute();

    for (int _ = 0; _ < T; _++) {
        Spread();
        Clean();
    }

    cout << Count();

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (0 <= r && r < R && 0 <= c && c < C && room[r][c] != CLEANER);
}

inline void InitializeWindRoute() {
    int ur, uc, dr, dc;
    tie(ur, uc) = cleaner[UP];
    tie(dr, dc) = cleaner[DOWN];

    uc++; dc++;

    while (uc < C) {
        route[UP].push_back({ ur, uc++ });
        route[DOWN].push_back({ dr, dc++ });
    }
    uc--; dc--;
    ur--; dr++;

    while (ur >= 0) {
        route[UP].push_back({ ur--, uc });
    }
    ur++; uc--;

    while (dr < R) {
        route[DOWN].push_back({ dr++, dc });
    }
    dr--; dc--;

    while (uc >= 0) {
        route[UP].push_back({ ur, uc-- });
        route[DOWN].push_back({ dr, dc-- });
    }
    uc++; dc++;
    ur++; dr--;

    while (ur <= cleaner[UP].first) {
        route[UP].push_back({ ur++, uc });
    }

    while (dr >= cleaner[DOWN].first) {
        route[DOWN].push_back({ dr--, dc });
    }

    reverse(route[UP].begin(), route[UP].end());
    reverse(route[DOWN].begin(), route[DOWN].end());
}

inline void Spread() {
    queue<tuple<int, int, int>> q;
    
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            if (room[r][c] > 0)
                q.push(make_tuple(r, c, room[r][c] / 5));
        
    while (!q.empty()) {
        int r, c, dusk;
        tie(r, c, dusk) = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (!isValidPoint(nr, nc)) continue;

            room[nr][nc] += dusk;
            room[r][c] -= dusk;
        }
    }
}

inline void Clean() {
    for (int i = 0; i < route[UP].size() - 1; i++) {
        pair<int, int> loc1 = route[UP][i], loc2 = route[UP][i + 1];
        room[loc1.first][loc1.second] = room[loc2.first][loc2.second];
    }
    room[cleaner[UP].first][cleaner[UP].second] = CLEANER;
    room[cleaner[UP].first][cleaner[UP].second + 1] = 0;

    for (int i = 0; i < route[DOWN].size() - 1; i++) {
        pair<int, int> loc1 = route[DOWN][i], loc2 = route[DOWN][i + 1];
        room[loc1.first][loc1.second] = room[loc2.first][loc2.second];
    }
    room[cleaner[DOWN].first][cleaner[DOWN].second] = CLEANER;
    room[cleaner[DOWN].first][cleaner[DOWN].second + 1] = 0;
}

inline int Count() {
    int sum = 0;
    for (int r = 0; r < R; r++)
        sum += accumulate(room[r].begin(), room[r].end(), 0);
    sum += 2;
    
    return sum;
}