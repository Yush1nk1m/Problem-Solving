/**
 * @file 2240_DP.cpp
 * @brief 00:27:01
 * @date 2024-07-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int T, W, maxCaught;
vector<int> tree;
vector<vector<int>> caught;     // caught[T][W]

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T >> W;
    tree.resize(T + 1, 0);
    for (int i = 1; i <= T; i++)
        cin >> tree[i];
    
    // if the index W is even number -> position = 1, odd number -> position = 2
    caught.resize(W + 1, vector<int>(T + 1, 0));
    for (int t = 1; t <= T; t++)
        caught[0][t] = caught[0][t-1] + (tree[t] == 1);
    
    for (int w = 1; w <= W; w++)
        for (int t = 1; t <= T; t++)
            caught[w][t] = max(caught[w-1][t-1], caught[w][t-1]) + (tree[t] % 2 == (w + 1) % 2);
    
    
    for (int w = 0; w <= W; w++)
        maxCaught = max(maxCaught, caught[w][T]);

    cout << maxCaught;

    return 0;
}