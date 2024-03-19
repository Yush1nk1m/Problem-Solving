#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

void preorderTraversal(vector<char>& tree, int root);
void inorderTraversal(vector<char>& tree, int root);
void postorderTraversal(vector<char>& tree, int root);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<char> tree(pow(2, N), 0);
    map<char, int> charIndex;

    tree[1] = 'A';
    charIndex['A'] = 1;

    for (int _ = 0; _ < N; _++) {
        char parent, left, right;
        cin >> parent >> left >> right;

        if (left != '.') {
            tree[charIndex[parent] * 2] = left;
            charIndex[left] = charIndex[parent] * 2;
        }
        
        if (right != '.') {
            tree[charIndex[parent] * 2 + 1] = right;
            charIndex[right] = charIndex[parent] * 2 + 1;
        }
    }

    preorderTraversal(tree, 1);
    cout << '\n';
    inorderTraversal(tree, 1);
    cout << '\n';
    postorderTraversal(tree, 1);

    return 0;
}

void preorderTraversal(vector<char>& tree, int root) {
    // root
    cout << tree[root];

    // left child
    if (root * 2 < tree.size() && tree[root * 2] != 0)
        preorderTraversal(tree, root * 2);

    // right child
    if (root * 2 + 1 < tree.size() && tree[root * 2 + 1] != 0)
        preorderTraversal(tree, root * 2 + 1);
}

void inorderTraversal(vector<char>& tree, int root) {
    // left child
    if (root * 2 < tree.size() && tree[root * 2] != 0)
        inorderTraversal(tree, root * 2);
    
    // root
    cout << tree[root];

    // right child
    if (root * 2 + 1 < tree.size() && tree[root * 2 + 1] != 0)
        inorderTraversal(tree, root * 2 + 1);
}

void postorderTraversal(vector<char>& tree, int root) {
    // left child
    if (root * 2 < tree.size() && tree[root * 2] != 0)
        postorderTraversal(tree, root * 2);

    // right child
    if (root * 2 + 1 < tree.size() && tree[root * 2 + 1] != 0)
        postorderTraversal(tree, root * 2 + 1);

    // root
    cout << tree[root];
}