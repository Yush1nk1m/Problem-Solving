/**
 * @file 14391_Bitmasking.cpp
 * @brief 01:25:20
 * @date 2024-07-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define RIGHT 0
#define DOWN  1

int N, M, maxSum;
vector<vector<char>> paper;
vector<vector<int>> segment;

inline void MarkSegment(int mask);
inline int CalcSum();
inline void CutCombination();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    paper.resize(N, vector<char>(M));
    segment.resize(N, vector<int>(M));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            cin >> paper[r][c];
            paper[r][c] -= '0';
        }

    CutCombination();
    cout << maxSum;

    return 0;
}

inline void MarkSegment(int mask) {
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            int index = (r * M) + c;
            if (mask & (1 << index))
                segment[r][c] = DOWN;
            else
                segment[r][c] = RIGHT;
        }
}

inline int CalcSum() {
    int sum = 0;
    int visited = 0;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            int index = (r * M) + c;
            if (!(visited & (1 << index))) {
                visited |= (1 << index);
                int segsum;
                // right direction
                if (segment[r][c] == RIGHT) {
                    segsum = paper[r][c];
                    for (int nc = c + 1; nc < M && segment[r][nc] == RIGHT; nc++) {
                        int nindex = (r * M) + nc;
                        visited |= (1 << nindex);
                        segsum *= 10;
                        segsum += paper[r][nc];
                    }
                }
                // down direction
                else {
                    segsum = paper[r][c];
                    for (int nr = r + 1; nr < N && segment[nr][c] == DOWN; nr++) {
                        int nindex = (nr * M) + c;
                        visited |= (1 << nindex);
                        segsum *= 10;
                        segsum += paper[nr][c];
                    }
                }

                sum += segsum;
            }
        }
    
    return sum;
}

inline void CutCombination() {
    int mask = 0, bound = (1 << (N * M));
    while (mask < bound) {
        MarkSegment(mask);
        maxSum = max(maxSum, CalcSum());
        mask++;
    }
}