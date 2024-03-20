#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long int DIVIDER = 1000000007LL;
#define UPDATE 1
#define PREFIX 2
#define PARENT(x) ((x) / (2))

void InitializeTree(vector<long long int>& tree, int maxIndex);
void UpdateTree(vector<long long int>& tree, int index, long long int value);
long long int prefixMultiplicationTree(vector<long long int>& tree, int startIndex, int endIndex);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int treeDepth = ceil(log2(N));
    int treeStartIndex = pow(2, treeDepth);
    vector<long long int> tree(pow(2, treeDepth + 1), 1);

    for (int i = 0; i < N; i++) {
        cin >> tree[i + treeStartIndex];
        tree[i + treeStartIndex] %= DIVIDER;
    }

    InitializeTree(tree, treeStartIndex + N - 1);

    for (int _ = 0; _ < M + K; _++) {
        int command;
        cin >> command;

        if (command == UPDATE) {
            int index; long long int value;
            cin >> index >> value;
            index += (treeStartIndex - 1);

            UpdateTree(tree, index, value);
        }
        else if (command == PREFIX) {
            int startIndex, endIndex;
            cin >> startIndex >> endIndex;

            startIndex += (treeStartIndex - 1);
            endIndex += (treeStartIndex - 1);

            long long int prefixMul = prefixMultiplicationTree(tree, startIndex, endIndex);

           cout << prefixMul << '\n';
        }
    }

}

void InitializeTree(vector<long long int>& tree, int maxIndex) {
    if (maxIndex % 2 == 0)
        maxIndex++;
    
    int index = maxIndex;
    while (index >= 1) {
        tree[index / 2] = (tree[index] * tree[index - 1]) % DIVIDER;
        index -= 2;
    }
}

void UpdateTree(vector<long long int>& tree, int index, long long int value) {
    tree[index] = value % DIVIDER;

    while (index >= 1) {
        int sibling;
        // 왼쪽 자식일 경우
        if (index % 2 == 0)
            sibling = index + 1;
        else
            sibling = index - 1;
        
        tree[PARENT(index)] = (tree[index] * tree[sibling]) % DIVIDER;

        index = PARENT(index);
    }
}

long long int prefixMultiplicationTree(vector<long long int>& tree, int startIndex, int endIndex) {
    long long int prefixMul = 1;

    while (startIndex <= endIndex) {
        if (startIndex % 2 == 1) {
            prefixMul *= tree[startIndex];
            prefixMul %= DIVIDER;
        }
        startIndex = PARENT(startIndex + 1);

        if (endIndex % 2 == 0) {
            prefixMul *= tree[endIndex];
            prefixMul %= DIVIDER;
        }
        endIndex = PARENT(endIndex - 1);
    }

    return prefixMul;
}