/**
 * @file 2979_Hash.cpp
 * @brief 00:05:24
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int arrive, leave;
int trucks[101];
int total;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;

    for (int i = 0; i < 3; i++) {
        cin >> arrive >> leave;
        for (int t = arrive; t < leave; t++)
            trucks[t]++;
    }

    for (int i = 1; i <= 100; i++)
        if (trucks[i] == 1) total += A;
        else if (trucks[i] == 2) total += (B * 2);
        else if (trucks[i] == 3) total += (C * 3);

    cout << total;

    return 0;
}