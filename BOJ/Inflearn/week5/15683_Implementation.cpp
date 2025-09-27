/**
 * @file 15683_Implementation.cpp
 * @brief 00:55:47
 * @date 2024-07-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define RIGHT   0
#define UP      1
#define LEFT    2
#define DOWN    3
#define EMPTY   0
#define WALL    6
#define COVER   7
#define INF     100000000

class CCTV {
    public:
        CCTV(int id, int r, int c) {
            this->id = id;
            this->r = r;
            this->c = c;
            this->dir = RIGHT;
        }
        int id;
        int r;
        int c;
        int dir;
        inline void markright();
        inline void markdown();
        inline void markleft();
        inline void markup();
        inline void mark();
};

int N, M, minBlind = INF;
int d[6] = { 0, 4, 2, 4, 4, 1 };
vector<vector<int>> room;
vector<CCTV> cctv;

inline void Print() {
    cout << "ROOM" << endl;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++)
            cout << room[r][c] << '\t';
        cout << endl;
    }
}
inline int CountBlindArea();
void DFS(int idx);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    room.resize(N, vector<int>(M));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            cin >> room[r][c];
            if (room[r][c] != EMPTY && room[r][c] != WALL)
                cctv.push_back(CCTV(room[r][c], r, c));
        }
    
    DFS(0);

    cout << minBlind;

    return 0;
}

inline int CountBlindArea() {
    int cnt = 0;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cnt += (room[r][c] == EMPTY);
    return cnt;
}

void DFS(int idx) {
    if (idx == cctv.size()) {
        minBlind = min(minBlind, CountBlindArea());
        return;
    }

    vector<vector<int>> temp = room;
    CCTV& curr = cctv[idx];

    for (int dir = 0; dir < d[curr.id]; dir++) {
        curr.dir = dir;
        curr.mark();
        DFS(idx + 1);
        room = temp;
    }
}

inline void CCTV::markright() {
    int p = this->c + 1;
    while (p < M && room[r][p] != WALL) {
        if (room[r][p] % COVER == 0)
            room[r][p++] += COVER;
        else p++;
    }
}

inline void CCTV::markdown() {
    int p = this->r + 1;
    while (p < N && room[p][c] != WALL) {
        if (room[p][c] % COVER == 0)
            room[p++][c] += COVER;
        else p++;
    }
}

inline void CCTV::markleft() {
    int p = this->c - 1;
    while (p >= 0 && room[r][p] != WALL) {
        if (room[r][p] % COVER == 0)
            room[r][p--] += COVER;
        else p--;
    }
}

inline void CCTV::markup() {
    int p = this->r - 1;
    while (p >= 0 && room[p][c] != WALL) {
        if (room[p][c] % COVER == 0)
            room[p--][c] += COVER;
        else p--;
    }
}

inline void CCTV::mark() {
    if (id == 1) {
        switch (dir) {
            case RIGHT:
                markright();
                break;
            case DOWN:
                markdown();
                break;
            case LEFT:
                markleft();
                break;
            case UP:
                markup();
                break;
        }
    }
    else if (id == 2) {
        switch (dir) {
            case RIGHT:
            case LEFT:
                markright();
                markleft();
                break;
            case DOWN:
            case UP:
                markdown();            
                markup();
                break;
        }
    }
    else if (id == 3) {
        switch (dir) {
            case RIGHT:
                markup();
                markright();
                break;
            case DOWN:
                markright();
                markdown();
                break;
            case LEFT:
                markdown();
                markleft();
                break;
            case UP:
                markleft();
                markup();
                break;
        }
    }
    else if (id == 4) {
        switch (dir) {
            case RIGHT:
                markleft();
                markup();
                markright();
                break;
            case DOWN:
                markup();
                markright();
                markdown();
                break;
            case LEFT:
                markright();
                markdown();
                markleft();
                break;
            case UP:
                markdown();
                markleft();
                markup();
                break;
        }
    }
    else if (id == 5) {
        markright();
        markdown();
        markleft();
        markup();
    }
}