/**
 * @file 17143_Implementation.cpp
 * @brief 01:00:00
 * @date 2024-07-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define UP      1
#define DOWN    2
#define RIGHT   3
#define LEFT    4

class Shark {
    public:
        int r;
        int c;
        int speed;
        int dir;
        int size;
        inline void Move();
};

int R, C, M, result;
vector<vector<int>> table;
vector<Shark> sharks;

inline bool isValidPoint(int r, int c);
inline void KillShark(int idx);
inline int KillShark(int r, int c);
inline void EatShark();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> M;
    table.resize(R + 1, vector<int>(C + 1, 0));
    sharks.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> sharks[i].r >> sharks[i].c >> sharks[i].speed >> sharks[i].dir >> sharks[i].size;
        table[sharks[i].r][sharks[i].c]++;
        
        if (sharks[i].dir == UP || sharks[i].dir == DOWN)
            sharks[i].speed %= (R - 1) * 2;
        else
            sharks[i].speed %= (C - 1) * 2;
    }

    for (int man = 1; man <= C; man++) {
        for (int r = 1; r <= R; r++)
            // if there's a shark existing
            if (table[r][man] > 0) {
                table[r][man] = 0;
                result += KillShark(r, man);
                break;
            }
        
        for (Shark& s : sharks)
            s.Move();

        EatShark();
    }

    cout << result;

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return (1 <= r && r <= R && 1 <= c && c <= C);
}

inline void Shark::Move() {
    // no need to move
    if (r == 0 || c == 0) return;                               // shark had been killed
    if ((dir == UP || dir == DOWN) && R == 1) return;           // shark cannot move 
    else if ((dir == LEFT || dir == RIGHT) && C == 1) return;   // shark cannot move

    table[r][c]--;
    for (int _ = 0; _ < speed; _++) {
        if (dir == UP) {
            int nr = r - 1;
            if (!isValidPoint(nr, c)) {
                nr = r + 1;
                dir = DOWN;
            }
            r = nr;
        }
        else if (dir == DOWN) {
            int nr = r + 1;
            if (!isValidPoint(nr, c)) {
                nr = r - 1;
                dir = UP;
            }
            r = nr;
        }
        else if (dir == LEFT) {
            int nc = c - 1;
            if (!isValidPoint(r, nc)) {
                nc = c + 1;
                dir = RIGHT;
            }
            c = nc;
        }
        else if (dir == RIGHT) {
            int nc = c + 1;
            if (!isValidPoint(r, nc)) {
                nc = c - 1;
                dir = LEFT;
            }
            c = nc;
        }
    }
    table[r][c]++;
}

inline int KillShark(int r, int c) {
    for (Shark& s : sharks) {
        if (s.r == r && s.c == c) {
            s.r = s.c = 0;
            return s.size;
        }
    }
    return -1;
}

inline void KillShark(int idx) {
    table[sharks[idx].r][sharks[idx].c]--;
    sharks[idx].r = sharks[idx].c = 0;
}

inline void EatShark() {
    for (int r = 1; r <= R; r++)
        for (int c = 1; c <= C; c++)
            if (table[r][c] >= 2) {
                queue<int> q;
                int msize = 0, midx;

                for (int i = 0; i < sharks.size(); i++)
                    if (sharks[i].r == r && sharks[i].c == c) {
                        q.push(i);
                        if (msize < sharks[i].size) {
                            msize = sharks[i].size;
                            midx = i;
                        }
                    }
                
                while (!q.empty()) {
                    int i = q.front();
                    q.pop();
                    
                    if (i == midx) continue;

                    KillShark(i);
                }
            }

}