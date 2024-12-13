#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

#define WALL    '*'
#define EMPTY   '.'
#define DOC     '$'

int t, h, w;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

inline bool isValidPoint(int r, int c);
inline int solve();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--)
        cout << solve() << '\n';

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return 0 <= r && r < h && 0 <= c && c < w;
}

inline int solve() {
    cin >> h >> w;

    int cnt = 0;
    vector<vector<char>> table(h, vector<char>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<pii> q;
    map<char, bool> opened;
    map<char, vector<pii>> doors;
    string keys;

    for (int r = 0; r < h; r++)
        for (int c = 0; c < w; c++) {
            cin >> table[r][c];
            if (table[r][c] == WALL)
                visited[r][c] = true;
        }
    cin >> keys;
    if (keys != "0")
        for (char key : keys)
            opened[key - 32] = true;
    
    for (int r = 0; r < h; r++) {
        if (!visited[r][0]) {
            if (table[r][0] == EMPTY) {
                visited[r][0] = true;
                q.push({ r, 0 });
            } else if (table[r][0] == DOC) {
                cnt++;
                visited[r][0] = true;
                q.push({ r, 0 });
            } else if ('a' <= table[r][0] && table[r][0] <= 'z') {
                opened[table[r][0] - 32] = true;
                visited[r][0] = true;
                q.push({ r, 0 });
                for (pii door : doors[table[r][0] - 32])
                    q.push(door);
                doors[table[r][0] - 32].clear();
            } else if ('A' <= table[r][0] && table[r][0] <= 'Z') {
                if (opened.find(table[r][0]) != opened.end()) {
                    visited[r][0] = true;
                    q.push({ r, 0 });
                } else {
                    visited[r][0] = true;
                    doors[table[r][0]].push_back({ r, 0 });
                }
            }
        }

        if (!visited[r][w-1]) {
            if (table[r][w-1] == EMPTY) {
                visited[r][w-1] = true;
                q.push({ r, w-1 });
            } else if (table[r][w-1] == DOC) {
                cnt++;
                visited[r][w-1] = true;
                q.push({ r, w-1 });
            } else if ('a' <= table[r][w-1] && table[r][w-1] <= 'z') {
                opened[table[r][w-1] - 32] = true;
                visited[r][w-1] = true;
                q.push({ r, w-1 });
                for (pii door : doors[table[r][w-1] - 32])
                    q.push(door);
                doors[table[r][w-1] - 32].clear();
            } else if ('A' <= table[r][w-1] && table[r][w-1] <= 'Z') {
                if (opened.find(table[r][w-1]) != opened.end()) {
                    visited[r][w-1] = true;
                    q.push({ r, w-1 });
                } else {
                    visited[r][w-1] = true;
                    doors[table[r][w-1]].push_back({ r, w-1 });
                }
            }
        }
    }
    for (int c = 0; c < w; c++) {
        if (!visited[0][c]) {
            if (table[0][c] == EMPTY) {
                visited[0][c] = true;
                q.push({ 0, c });
            } else if (table[0][c] == DOC) {
                cnt++;
                visited[0][c] = true;
                q.push({ 0, c });
            } else if ('a' <= table[0][c] && table[0][c] <= 'z') {
                opened[table[0][c] - 32] = true;
                visited[0][c] = true;
                q.push({ 0, c });
                for (pii door : doors[table[0][c] - 32])
                    q.push(door);
                doors[table[0][c] - 32].clear();
            } else if ('A' <= table[0][c] && table[0][c] <= 'Z') {
                if (opened.find(table[0][c]) != opened.end()) {
                    visited[0][c] = true;
                    q.push({ 0, c });
                } else {
                    visited[0][c] = true;
                    doors[table[0][c]].push_back({ 0, c });
                }
            }
        }

        if (!visited[h-1][c]) {
            if (table[h-1][c] == EMPTY) {
                visited[h-1][c] = true;
                q.push({ h-1, c });
            } else if (table[h-1][c] == DOC) {
                cnt++;
                visited[h-1][c] = true;
                q.push({ h-1, c });
            } else if ('a' <= table[h-1][c] && table[h-1][c] <= 'z') {
                opened[table[h-1][c] - 32] = true;
                visited[h-1][c] = true;
                q.push({ h-1, c });
                for (pii door : doors[table[h-1][c] - 32])
                    q.push(door);
                doors[table[h-1][c] - 32].clear();
            } else if ('A' <= table[h-1][c] && table[h-1][c] <= 'Z') {
                if (opened.find(table[h-1][c]) != opened.end()) {
                    visited[h-1][c] = true;
                    q.push({ h-1, c });
                } else {
                    visited[h-1][c] = true;
                    doors[table[h-1][c]].push_back({ h-1, c });
                }
            }
        }
    }

    while (!q.empty()) {
        pii curr = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = curr.first + dr[d], nc = curr.second + dc[d];

            if (!isValidPoint(nr, nc) || visited[nr][nc])
                continue;
            visited[nr][nc] = true;

            if (table[nr][nc] == EMPTY) {
                q.push({ nr, nc });    
            } else if (table[nr][nc] == DOC) {
                cnt++;
                q.push({ nr, nc });
            } else if ('a' <= table[nr][nc] && table[nr][nc] <= 'z') {
                q.push({ nr, nc });
                opened[table[nr][nc] - 32] = true;
                for (pii door : doors[table[nr][nc] - 32])
                    q.push(door);
                doors[table[nr][nc]].clear();
            } else if ('A' <= table[nr][nc] && table[nr][nc] <= 'Z') {
                if (opened.find(table[nr][nc]) != opened.end()) {
                    q.push({ nr, nc });
                } else {
                    doors[table[nr][nc]].push_back({ nr, nc });
                }
            }
        }
    }

    return cnt;
}