/**
 * @file 15662_Implementation.cpp
 * @brief 00:44:33
 * @date 2024-07-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define LEFT    6
#define RIGHT   2
#define N       0
#define S       1
#define RCLOCK  -1
#define CLOCK   1

int T, K, rotated;
vector<vector<bool>> gear;

void Rotate(int g, int dir);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    gear.resize(T, vector<bool>(8));
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            gear[i][j] = (c - '0');
        }
    }

    cin >> K;
    for (int _ = 0; _ < K; _++) {
        int g, dir;
        cin >> g >> dir;
        rotated = (1 << (g - 1));
        Rotate(g - 1, dir);
    }

    int cnt = 0;
    for (int i = 0; i < T; i++)
        cnt += (gear[i][0]);
    cout << cnt;

    return 0;
}

void Rotate(int g, int dir) {
    if (g - 1 >= 0 && !(rotated & (1 << (g - 1)))&& gear[g][LEFT] != gear[g-1][RIGHT]) {
        rotated |= (1 << (g - 1));
        Rotate(g - 1, -dir);
    }

    if (g + 1 < T && !(rotated & (1 << (g + 1))) && gear[g][RIGHT] != gear[g+1][LEFT]) {
        rotated |= (1 << (g + 1));
        Rotate(g + 1, -dir);
    }

    if (dir == CLOCK)
        rotate(gear[g].rbegin(), gear[g].rbegin() + 1, gear[g].rend());
    else
        rotate(gear[g].begin(), gear[g].begin() + 1, gear[g].end());
}