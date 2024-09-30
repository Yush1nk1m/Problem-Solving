/**
 * @file 2841_Stack.cpp
 * @brief 00:11:47
 * @date 2024-09-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, P, cnt;
vector<stack<int>> pressed(7);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> P;
    for (int i = 0; i < N; i++) {
        int line, fret;
        cin >> line >> fret;

        while (!pressed[line].empty() && pressed[line].top() > fret) {
            cnt++;
            pressed[line].pop();
        }

        if (pressed[line].empty() || pressed[line].top() != fret) {
            cnt++;
            pressed[line].push(fret);
        }
    }

    cout << cnt;

    return 0;
}