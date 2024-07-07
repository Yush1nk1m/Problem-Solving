/**
 * @file 17825_Implementation.cpp
 * @brief 01:49:20
 * @date 2024-07-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int nexts[41], turn[10], maxScore;
pair<int, bool> piece[4];

inline void InitializeNext();
void DFS(int depth, int score);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    InitializeNext();
    for (int i = 0; i < 10; i++)
        cin >> turn[i];
    
    DFS(0, 0);

    cout << maxScore;

    return 0;
}

inline void InitializeNext() {
    nexts[13] = 16;
    nexts[16] = 19;
    nexts[19] = 25;

    nexts[22] = 24;
    nexts[24] = 25;

    nexts[28] = 27;
    nexts[27] = 26;
    nexts[26] = 25;

    nexts[25] = 30;
    nexts[30] = 35;
    nexts[35] = 40;
    nexts[40] = 42;
}

void DFS(int depth, int score) {
    // moved 10 times successfully
    if (depth == 10) {
        maxScore = max(maxScore, score);
        return;
    }

    for (pair<int, bool>& p : piece) {
        pair<int, bool> temp = p;
        int jump = turn[depth];
        int curr = p.first;
        bool special = p.second;

        // if it is already arrived to the end-point
        if (curr > 40) continue;

        // update the status of special route and move 1 point
        if (curr == 10 && !special) {
            jump--;
            curr = 13;
            special = true;
        } else if (curr == 20 && !special) {
            jump--;
            curr = 22;
            special = true;
        } else if (curr == 30 && !special) {
            jump--;
            curr = 28;
            special = true;
        }

        if (!special) { // if it is on the non-special route
            curr += (jump * 2);
        } else {        // if it is on the special route
            for (int _ = 0; _ < jump && curr <= 40; _++)
                curr = nexts[curr];
        }

        if (curr == 40) special = false;

        // check if it is not arrived to the end-point and duplicated with some other piece
        bool dup = false;
        for (pair<int, bool>& neighbor : piece)
            if (neighbor.first == curr && neighbor.second == special && curr <= 40) {
                dup = true;
                break;
            }
        if (dup) continue;

        // update the status of the piece
        p.first = curr;
        p.second = special;

        // PrintStatus("after move");

        // if it is arrived to the end-point, do not add score and jump to the next turn
        if (curr > 40)
            DFS(depth + 1, score);
        else
            DFS(depth + 1, score + curr);
        // restore the status of the piece 
        p = temp;
    }
}