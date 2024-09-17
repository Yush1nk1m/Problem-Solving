/**
 * @file 1713_Implementation.cpp
 * @brief 00:23:14
 * @date 2024-09-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, recommend, order;
vector<tuple<int, int, int>> board; // <student number, order, recommend counter>

inline void append(int student);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> recommend;
    board.resize(N, make_tuple(0, 0, 0));
    while (recommend--) {
        int student;
        cin >> student;
        append(student);
    }

    sort(board.begin(), board.end());
    for (tuple<int, int, int>& tup : board)
        if (get<0>(tup) != 0)
            cout << get<0>(tup) << ' ';

    return 0;
}

inline void append(int student) {
    int minRecommend = INF, minOrder = INF, minIdx;
    bool isExisting = false;
    for (int i = 0; i < N; i++) {
        tuple<int, int, int>& slot = board[i];

        // if the slot is empty
        if (get<0>(slot) == 0) {
            slot = make_tuple(student, order++, 1);
            isExisting = true;
            break;
        }
        // if the student is already in the board
        else if (get<0>(slot) == student) {
            slot = make_tuple(student, get<1>(slot), get<2>(slot) + 1);
            isExisting = true;
            break;
        }
        // if the student is not existing
        else {
            if (get<2>(slot) < minRecommend) {
                minIdx = i;
                minRecommend = get<2>(slot);
                minOrder = get<1>(slot);
            }
            else if (get<2>(slot) == minRecommend && get<1>(slot) < minOrder) {
                minIdx = i;
                minOrder = get<1>(slot);
            }
        }
    }

    if (!isExisting) {
        board[minIdx] = make_tuple(student, order++, 1);
    }
}