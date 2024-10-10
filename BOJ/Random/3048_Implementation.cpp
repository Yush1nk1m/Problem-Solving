/**
 * @file 3048_Implementation.cpp
 * @brief 00:22:59
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define RIGHT   false
#define LEFT    true

int N1, N2, T;
vector<pair<char, bool>> v;
string result;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N1 >> N2;
    v.resize(N1 + N2);
    for (int i = N1 - 1; i >= 0; i--)
        cin >> v[i].first;
    for (int i = N1; i < N1 + N2; i++) {
        cin >> v[i].first;
        v[i].second = LEFT;
    }

    cin >> T;
    while (T--) {
        vector<int> candidates;
        for (int i = 0; i < N1 + N2 - 1; i++)
            if (v[i].second == RIGHT && v[i+1].second == LEFT)
                candidates.push_back(i);
        
        for (int idx : candidates) {
            pair<char, bool> temp = v[idx];
            v[idx] = v[idx+1];
            v[idx+1] = temp;
        }
    }

    for (pair<char, bool>& p : v)
        cout << p.first;

    return 0;
}