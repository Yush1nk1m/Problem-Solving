/**
    00:55:12
 */
// #include <bits/stdc++.h>
// using namespace std;

// int n;
// vector<int> inorder, postorder;
// vector<bool> leftValues, rightValues;

// void traversal(int from, int to);

// int main(int argc, char* argv[]) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> n;
    
//     inorder.resize(n);
//     for (int i = 0; i < n; i++)
//         cin >> inorder[i];
    
//     postorder.resize(n);
//     for (int i = 0; i < n; i++)
//         cin >> postorder[i];

//     leftValues.resize(n + 1, false);
//     rightValues.resize(n + 1, false);
//     traversal(0, n);
// }

// void traversal(int from, int to) {
//     int root = postorder[to - 1];
//     int inorderRootIdx = from;
//     while (inorder[inorderRootIdx] != root)
//         inorderRootIdx++;

//     for (int i = from; i < inorderRootIdx; i++)
//         leftValues[inorder[i]] = true;
//     for (int i = inorderRootIdx + 1; i < n; i++)
//         rightValues[inorder[i]] = true;

//     int left, right;
//     for (left = from; left < n && leftValues[postorder[left]]; left++)
//         ;
//     for (right = left; right < n && rightValues[postorder[right]]; right++)
//         ;

//     for (int i = from; i < inorderRootIdx; i++)
//         leftValues[inorder[i]] = false;
//     for (int i = inorderRootIdx + 1; i < n; i++)
//         rightValues[inorder[i]] = false;

//     cout << root << ' ';
//     if (left != from)
//         traversal(from, left);
//     if (right != left)
//         traversal(left, right);
// }