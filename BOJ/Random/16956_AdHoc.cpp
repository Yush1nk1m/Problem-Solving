#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

#define EMPTY   '.'
#define LAMB    'S'
#define WOLF    'W'
#define WALL    'D'

int R, C;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
vector<pii> lambs;
vector<vector<char>> m;

inline bool isValidPoint(int r, int c);
inline bool mark();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    m.resize(R, vector<char>(C));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++) {
            cin >> m[r][c];
            if (m[r][c] == LAMB)
                lambs.push_back({ r, c });
        }
    
    bool isAvailable = mark();
    if (isAvailable) {
        cout << "1\n";
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++)
                cout << m[r][c];
            cout << '\n';
        }
    } else cout << 0;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return 0 <= r && r < R && 0 <= c && c < C;
}

inline bool mark() {
    for (pii& lamb : lambs)
        for (int d = 0; d < 4; d++) {
            int r = lamb.first + dr[d], c = lamb.second + dc[d];
            if (!isValidPoint(r, c)) continue;
            else if (m[r][c] == WOLF) return false;
            else if (m[r][c] == EMPTY) m[r][c] = WALL;
        }
    return true;
}