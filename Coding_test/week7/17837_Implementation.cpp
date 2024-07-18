/**
 * @file 17837_Implementation.cpp
 * @brief 01:37:08
 * @date 2024-07-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define WHITE   0
#define RED     1
#define BLUE    2
#define RIGHT   1
#define LEFT    2
#define UP      3
#define DOWN    4

class Piece {
    public:
        int id;
        int r;
        int c;
        int dir;
        pair<int, int> next();
        void rotate180();
};

int N, K, turn;
int dr[5] = { 0, 0, 0, -1, 1 }, dc[5] = { 0, 1, -1, 0, 0 };
vector<vector<int>> table;
vector<Piece> pieces;
vector<vector<deque<int>>> pieceTable;

inline bool CheckRange(int r, int c);
inline bool MoveAll();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    table.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> table[r][c];

    pieceTable.resize(N, vector<deque<int>>(N));
    pieces.resize(K);
    for (int i = 0; i < K; i++) {
        cin >> pieces[i].r >> pieces[i].c >> pieces[i].dir;
        pieces[i].r--; pieces[i].c--;
        pieces[i].id = i;
        pieceTable[pieces[i].r][pieces[i].c].push_back(i);
    }

    while (++turn <= 1000) {
        if (!MoveAll())
            break;
    }
    
    if (turn <= 1000)
        cout << turn;
    else
        cout << -1;

    return 0;
}

inline bool CheckRange(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < N);
}

inline bool MoveAll() {
    for (int i = 0; i < K; i++) {
        Piece& p = pieces[i];

        int nr, nc;
        tie(nr, nc) = p.next();
        if (!CheckRange(nr, nc) || table[nr][nc] == BLUE) {
            p.rotate180();
            tie(nr, nc) = p.next();
            if (!CheckRange(nr, nc) || table[nr][nc] == BLUE)
                continue;
        }

        deque<int> up;
        while (pieceTable[p.r][p.c].back() != p.id) {
            up.push_front(pieceTable[p.r][p.c].back());
            pieceTable[p.r][p.c].pop_back();
        }
        up.push_front(pieceTable[p.r][p.c].back());
        pieceTable[p.r][p.c].pop_back();
        
        if (table[nr][nc] == WHITE)
            while (!up.empty()) {
                int ni = up.front();
                up.pop_front();
                pieces[ni].r = nr;
                pieces[ni].c = nc;
                pieceTable[nr][nc].push_back(ni);
            }
        
        if (table[nr][nc] == RED) {
            reverse(up.begin(), up.end());

            while (!up.empty()) {
                int ni = up.front();
                up.pop_front();
                pieces[ni].r = nr;
                pieces[ni].c = nc;
                pieceTable[nr][nc].push_back(ni);
            }
        }

        if (pieceTable[nr][nc].size() >= 4)
            return false;
    }

    return true;
}

pair<int, int> Piece::next() {
    return { r + dr[dir], c + dc[dir] };
}

void Piece::rotate180() {
    if (dir == LEFT)
        dir = RIGHT;
    else if (dir == RIGHT)
        dir = LEFT;
    else if (dir == UP)
        dir = DOWN;
    else if (dir == DOWN)
        dir = UP;
}