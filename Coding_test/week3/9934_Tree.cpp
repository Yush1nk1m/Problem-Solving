/**
 * @file 9934_Tree.cpp
 * @brief 00:12:01
 * @date 2024-06-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define NONE -1

int K, N;
vector<int> tree;
queue<int> buildings;

void Traversal(int root);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    N = pow(2, K) - 1;
    tree.resize(N + 1, NONE);
    for (int _ = 0; _ < N; _++) {
        int number;
        cin >> number;
        buildings.push(number);
    }

    Traversal(1);

    for (int level = 0; level < K; level++) {
        int p = pow(2, level), end = pow(2, level + 1);
        while (p < end)
            cout << tree[p++] << ' ';
        cout << '\n';
    }

    return 0;
}

void Traversal(int root) {
    if (root * 2 <= N)
        Traversal(root * 2);

    tree[root] = buildings.front();
    buildings.pop();

    if (root * 2 + 1 <= N)
        Traversal(root * 2 + 1);
}

