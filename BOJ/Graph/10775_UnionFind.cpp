#include <bits/stdc++.h>
using namespace std;

int G, P, start, result;
vector<int> disjointSet, g;

inline void setUnion(int n1, int n2);
inline int setRoot(int n);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> G >> P;
    disjointSet.resize(G + 1, 0);
    for (int i = 1; i <= G; i++)
        disjointSet[i] = i;

    g.resize(P);
    for (int i = 0; i < P; i++)
        cin >> g[i];

    for (int gate : g) {
        int root = setRoot(gate);
        if (root == 0)
            break;
        result++;
        setUnion(root - 1, gate);
    }

    cout << result;

    return 0;
}

inline void setUnion(int n1, int n2) {
    stack<int> stk;

    while (n1 != disjointSet[n1]) {
        stk.push(n1);
        n1 = disjointSet[n1];
    }

    while (n2 != disjointSet[n2]) {
        stk.push(n2);
        n2 = disjointSet[n2];
    }

    stk.push(n2);

    while (!stk.empty()) {
        disjointSet[stk.top()] = n1;
        stk.pop();
    }
}

inline int setRoot(int n) {
    while (n != disjointSet[n])
        n = disjointSet[n];

    return n;
}