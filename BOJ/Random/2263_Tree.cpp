/**
 * @file 2263_Tree.cpp
 * @brief 01:18:10
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> inorder, postorder;
map<int, int> indexMap;

void traversal(int inFrom, int inTo, int postFrom, int postTo);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    inorder.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        indexMap[inorder[i]] = i;
    }
    
    postorder.resize(n);
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    traversal(0, n - 1, 0, n - 1);

    return 0;
}

void traversal(int inFrom, int inTo, int postFrom, int postTo) {
    int root = postorder[postTo];
    int mid = indexMap[root];
    int leftChilds = mid - inFrom;

    cout << root << ' ';
    if (inFrom <= mid - 1)
        traversal(inFrom, mid - 1, postFrom, postFrom + leftChilds - 1);
    if (mid + 1 <= inTo)
        traversal(mid + 1, inTo, postFrom + leftChilds, postTo - 1);
}