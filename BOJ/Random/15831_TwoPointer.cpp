/**
 * @file 15831_TwoPointer.cpp
 * @brief 00:23:11
 * @date 2024-10-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define BLACK   'B'
#define WHITE   'W'

int N, B, W, i, j, b, w, len, maxLen;
string line;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B >> W;
    cin >> line;

    while (i <= j && j < N) {
        if (line[j] == WHITE) {
            j++;
            len++;
            w++;
        } else if (line[j] == BLACK) {
            if (b < B) {
                j++;
                len++;
                b++;
            } else {
                if (i < j) {
                    (line[i++] == BLACK) ? b-- : w--;
                    len--;
                } else {
                    i++;
                    j++;
                }
            }
        }

        if (b <= B && w >= W)
            maxLen = max(maxLen, len);
    }

    cout << maxLen;

    return 0;
}