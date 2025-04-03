#include <bits/stdc++.h>
using namespace std;

#define INDEX(i)    ((i) + (startIndex) - (1))
#define INF         1000000000

int N, M, height, startIndex;
vector<pair<int, int>> tree;

inline void initializeTree();
inline void changeNumber(int i, int v);
inline int getMinimumIndex(int i, int j);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    height = ceil(log2(N)) + 1;
    startIndex = pow(2, height - 1);
    tree = vector<pair<int, int>>(pow(2, height) + 1);

    for (int i = startIndex; i < startIndex + N; i++) {
        int v;
        cin >> v;
        tree[i] = make_pair(v, i - startIndex + 1);
    }
    initializeTree();

    cin >> M;
    while (M--) {
        int q, a, b;
        cin >> q >> a >> b;
        if (q == 1)
            changeNumber(a, b);
        else
            cout << getMinimumIndex(a, b) << '\n';
    }

    return 0;
}

inline void initializeTree() {
    for (int i = startIndex - 1; i > 0; i--)
        tree[i] = min(tree[i*2], tree[i*2+1]);
}

inline void changeNumber(int i, int v) {
    tree[INDEX(i)] = make_pair(v, i);
    for (int j = INDEX(i) / 2; j > 0; j /= 2)
        tree[j] = min(tree[j*2], tree[j*2+1]);
}

inline int getMinimumIndex(int i, int j) {
    pair<int, int> res = make_pair(INF, INF);
    i = INDEX(i);
    j = INDEX(j);
    while (i <= j) {
        if (i % 2 != 0)
            res = min(res, tree[i]);
        if (j % 2 == 0)
            res = min(res, tree[j]);
        i = (i + 1) / 2;
        j = (j - 1) / 2;
    }
    return res.second;
}