/**
 * @file 17136_Backtracking.cpp
 * @brief 01:11:48
 * @date 2024-07-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

class Paper {
    public:
        int s1, s2, s3, s4, s5;
};

int result = INF;
vector<vector<int>> paper(10, vector<int>(10));

inline bool Coverable(int sr, int sc, int size);
inline void Cover(int sr, int sc, int size);
void DFS(Paper p);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int r = 0; r < 10; r++)
        for (int c = 0; c < 10; c++)
            cin >> paper[r][c];

    bool paperExist = false;
    for (int r = 0; r < 10 && !paperExist; r++)
        for (int c = 0; c < 10 && !paperExist; c++)
            if (paper[r][c]) {
                DFS({ 5, 5, 5, 5, 5 });
                paperExist = true;
            }
    
    if (!paperExist)
        cout << 0;
    else if (result == INF)
        cout << -1;
    else
        cout << result;
}

inline bool Coverable(int sr, int sc, int size) {
    if (sr + size > 10 || sc + size > 10)
        return false;

    for (int r = sr; r < sr + size; r++)
        for (int c = sc; c < sc + size; c++)
            if (!paper[r][c])
                return false;
    
    return true;
}

inline void Cover(int sr, int sc, int size) {
    for (int r = sr; r < sr + size; r++)
        for (int c = sc; c < sc + size; c++)
            paper[r][c] = false;
}

void DFS(Paper p) {
    int nr = -1, nc = -1;
    for (int r = 0; r < 10 && nr == -1 && nc == -1; r++)
        for (int c = 0; c < 10 && nr == -1 && nc == -1; c++)
            if (paper[r][c]) {
                nr = r;
                nc = c;
            }
    
    if (nr == -1 && nc == -1) {
        result = min(result, (5 - p.s1) + (5 - p.s2) + (5 - p.s3) + (5 - p.s4) + (5 - p.s5));
        return;
    }

    vector<vector<int>> temp = paper;
    if (p.s1 && Coverable(nr, nc, 1)) {
        Cover(nr, nc, 1);
        p.s1--;
        DFS(p);
        p.s1++;
        paper = temp;
    }
    if (p.s2 && Coverable(nr, nc, 2)) {
        Cover(nr, nc, 2);
        p.s2--;
        DFS(p);
        p.s2++;
        paper = temp;
    }
    if (p.s3 && Coverable(nr, nc, 3)) {
        Cover(nr, nc, 3);
        p.s3--;
        DFS(p);
        p.s3++;
        paper = temp;
    }
    if (p.s4 && Coverable(nr, nc, 4)) {
        Cover(nr, nc, 4);
        p.s4--;
        DFS(p);
        p.s4++;
        paper = temp;
    }
    if (p.s5 && Coverable(nr, nc, 5)) {
        Cover(nr, nc, 5);
        p.s5--;
        DFS(p);
        p.s5++;
        paper = temp;
    }
}