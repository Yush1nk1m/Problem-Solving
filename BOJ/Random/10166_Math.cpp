/**
 * @file 10166_Math.cpp
 * @brief 00:25:46
 * @date 2024-08-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int D1, D2;
vector<vector<bool>> table;

inline int GCD(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (a % b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }

    return b;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> D1 >> D2;
    table.resize(D2 + 1, vector<bool>(D2 + 1, false));

    for (int i = D1; i <= D2; i++)
        for (int j = 1; j <= i; j++) {
            int gcd = GCD(i, j);
            table[i/gcd][j/gcd] = true;
        }

    int sum = 0;
    for (int i = 1; i <= D2; i++)
        for (int j = 1; j <= i; j++)
            sum += table[i][j];

    cout << sum;

    return 0;
}