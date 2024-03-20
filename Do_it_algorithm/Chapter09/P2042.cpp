#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define UPDATE 1
#define PREFIX 2
#define LEFTCHILD(x) ((x) * (2))
#define RIGHTCHILD(x) ((x) * (2) + (1))

long long int InitializeTree(vector<long long int>& tree, int node, int depth);
void updateTree(vector<long long int>& tree, int index, long long int value);
long long int prefixSumTree(vector<long long int>& tree, int startIndex, int endIndex);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int treeDepth = ceil(log2(N));
    vector<long long int> tree(pow(2, treeDepth + 1), 0);

    int treeStartIndex = pow(2, treeDepth);
    for (int i = 0; i < N; i++)
        cin >> tree[i + treeStartIndex];

    InitializeTree(tree, 1, treeDepth);

    for (int _ = 0; _ < M + K; _++) {
        int command;
        cin >> command;

        if (command == UPDATE) {
            int index; long long int value;
            cin >> index >> value;
            index += (treeStartIndex - 1);

            updateTree(tree, index, value);
        }
        else if (command == PREFIX) {
            int startIndex, endIndex;
            cin >> startIndex >> endIndex;

            startIndex += (treeStartIndex - 1);
            endIndex += (treeStartIndex - 1);

            cout << prefixSumTree(tree, startIndex, endIndex) << '\n';
        }
    }

    // TREE PRINT
    //for (int depth = 0; depth <= treeDepth; depth++) {
    //    for (int idx = pow(2, depth); idx < pow(2, depth + 1); idx++)
    //        cout << tree[idx] << " ";
    //    cout << endl;
    //}
}

long long int InitializeTree(vector<long long int>& tree, int node, int depth) {
    if (depth == 0)
        return tree[node];

    tree[node] = InitializeTree(tree, LEFTCHILD(node), depth - 1) + InitializeTree(tree, RIGHTCHILD(node), depth - 1);

    return tree[node];
}

void updateTree(vector<long long int>& tree, int index, long long int value) {
    long long int difference = value - tree[index];
    
    while (index >= 1) {
        tree[index] += difference;
        index /= 2;
    }
}

long long int prefixSumTree(vector<long long int>& tree, int startIndex, int endIndex) {
    long long int prefixSum = 0;
    
    while (startIndex <= endIndex) {
        if (startIndex % 2 == 1)
            prefixSum += tree[startIndex];
        startIndex = (startIndex + 1) / 2;

        if (endIndex % 2 == 0)
            prefixSum += tree[endIndex];
        endIndex = (endIndex - 1) / 2;
    }

    return prefixSum;
}