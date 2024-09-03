/**
 * @file 1331_Implementation.cpp
 * @brief 00:15:03
 * @date 2024-09-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define CONVERT_NUM(N)  (N - '1')
#define CONVERT_CHAR(C) (C - 'A')

string loc, prior, start;
vector<vector<bool>> table(6, vector<bool>(6, false));

inline bool isValidPoint(string p1, string p2) {
    return (abs(p1[0] - p2[0]) <= 2 && abs(p1[1] - p2[1]) <= 2 && abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]) == 3);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool isValid = true;
    cin >> prior;
    table[CONVERT_CHAR(prior[0])][CONVERT_NUM(prior[1])] = true;
    start = prior;
    for (int _ = 1; _ < 36; _++) {
        cin >> loc;
        if (isValidPoint(loc, prior) && !table[CONVERT_CHAR(loc[0])][CONVERT_NUM(loc[1])])
            table[CONVERT_CHAR(loc[0])][CONVERT_NUM(loc[1])] = true;
        else
            isValid = false;
        prior = loc;
    }
    if (!isValidPoint(prior, start))
        isValid = false;

    if (isValid)
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}