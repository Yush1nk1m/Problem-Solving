/**
 * @file 2309.cpp
 * @brief 00:04:26
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> dwarfs(9);

void Print(int n1, int n2) {
    for (int i = 0; i < 9; i++)
        if ((i != n1) && (i != n2))
            cout << dwarfs[i] << '\n';
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++)
        cin >> dwarfs[i];

    sort(dwarfs.begin(), dwarfs.end());
    int sum = accumulate(dwarfs.begin(), dwarfs.end(), 0);

    for (int i = 0; i < 8; i++)
        for (int j = i + 1; j < 9; j++)
            if (sum - (dwarfs[i] + dwarfs[j]) == 100) {
                Print(i, j);
                return 0;
            }

    return 0;
}