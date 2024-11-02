/**
 * @file 19941_Greedy.cpp
 * @brief 00:09:29
 * @date 2024-11-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, K, result;
string line;
vector<bool> edible;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> line;
    edible.resize(N, true);
    for (int i = 0; i < N; i++)
        if (line[i] == 'P')
            edible[i] = false;
    
    for (int i = 0; i < N; i++)
        if (line[i] == 'P')
            for (int j = max(0, i - K); j <= min(N - 1, i + K); j++)
                if (edible[j]) {
                    edible[j] = false;
                    result++;
                    break;
                }

    cout << result;

    return 0;
}