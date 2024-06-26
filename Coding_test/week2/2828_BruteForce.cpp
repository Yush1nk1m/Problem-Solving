/**
 * @file 2828_BruteForce.cpp
 * @brief 00:10:18
 * @date 2024-06-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, J, currLoc = 1, dist;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> J;

    for (int _ = 0; _ < J; _++) {
        int loc;
        cin >> loc;

        if (currLoc + M - 1 < loc) {
            int move = loc - (currLoc + M - 1);
            currLoc += move;
            dist += move;
        } else if (loc < currLoc) {
            int move = currLoc - loc;
            currLoc -= move;
            dist += move;
        }
    }

    cout << dist;

    return 0;
}