#include <bits/stdc++.h>
using namespace std;

#define MIN 0
#define MAX 1
#define INF 1000000001
#define INDEX(x) (x + idx - 1)

int N, M, height, idx;
vector<int> minTree, maxTree;

inline void Initialize();
inline int Range(int from, int to, int command);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    height = ceil(log2(N)) + 1;
    idx = pow(2, height - 1);
    minTree.resize(pow(2, height), INF);
    maxTree.resize(pow(2, height), -INF);

    for (int i = INDEX(1); i < INDEX(1 + N); i++) {
        cin >> minTree[i];
        maxTree[i] = minTree[i];
    }
    Initialize();

    for (int _ = 0; _ < M; _++) {
        int a, b;
        cin >> a >> b;
        cout << Range(a, b, MIN) << ' ' << Range(a, b, MAX) << '\n';
    }

    return 0;
}

inline void Initialize() {
    for (int i = INDEX(1) - 1; i > 0; i--) {
        minTree[i] = min(minTree[i*2], minTree[i*2+1]);
        maxTree[i] = max(maxTree[i*2], maxTree[i*2+1]);
    }
}

inline int Range(int from, int to, int command) {
    int res;
    from = INDEX(from);
    to = INDEX(to);

    if (command == MIN) {
        res = INF;
        while (from <= to) {
            if (from % 2 == 1)
                res = min(res, minTree[from]);
            if (to % 2 == 0)
                res = min(res, minTree[to]);
            from = (from + 1) / 2;
            to = (to - 1) / 2;
        }
    }
    else if (command == MAX) {
        res = -INF;
        while (from <= to) {
            if (from % 2 == 1)
                res = max(res, maxTree[from]);
            if (to % 2 == 0)
                res = max(res, maxTree[to]);
            from = (from + 1) / 2;
            to = (to - 1) / 2;
        }
    }

    return res;
}