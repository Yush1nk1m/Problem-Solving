#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define INF 1000000001
#define LEFTCHILD(x) ((x) * (2))
#define RIGHTCHILD(x) ((x) * (2) + (1))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

long long int InitializeTree(vector<long long int>& tree, int node, int depth);
long long int prefixMinimumTree(vector<long long int>& tree, int startIndex, int endIndex);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int treeDepth = ceil(log2(N));
    int treeStartIndex = pow(2, treeDepth);
    vector<long long int> tree(pow(2, treeDepth + 1), INF);

    for (int i = 0; i < N; i++)
        cin >> tree[i + treeStartIndex];

    InitializeTree(tree, 1, treeDepth);

    for (int _ = 0; _ < M; _++) {
        int startIndex, endIndex;
        cin >> startIndex >> endIndex;
        
        startIndex += (treeStartIndex - 1);
        endIndex += (treeStartIndex - 1);

        cout << prefixMinimumTree(tree, startIndex, endIndex) << '\n';
    }
    
    return 0;
}

long long int InitializeTree(vector<long long int>& tree, int node, int depth) {
    if (depth == 0)
        return tree[node];
    
    tree[node] = MIN(InitializeTree(tree, LEFTCHILD(node), depth - 1), InitializeTree(tree, RIGHTCHILD(node), depth - 1));

    return tree[node];
}

long long int prefixMinimumTree(vector<long long int>& tree, int startIndex, int endIndex) {
    long long int minimum = INF;

    while (startIndex <= endIndex) {
        if (startIndex % 2 == 1)
            minimum = MIN(minimum, tree[startIndex]);
        startIndex = (startIndex + 1) / 2;
        
        if (endIndex % 2 == 0)
            minimum = MIN(minimum, tree[endIndex]);
        endIndex = (endIndex - 1) / 2;
    }

    return minimum;
}