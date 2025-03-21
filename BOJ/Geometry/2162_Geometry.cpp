#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> line;

int N;
vector<line> lines;
vector<int> disjointSet;

inline int ccw(pii p1, pii p2, pii p3);
inline bool isIntersect(line l1, line l2);
inline void setUnion(int n1, int n2);
inline bool setFind(int n1, int n2);
inline void generateOutput();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    lines.resize(N);
    for (int i = 0; i < N; i++)
        cin >> lines[i].first.first >> lines[i].first.second >> lines[i].second.first >> lines[i].second.second;

    disjointSet.resize(N);
    for (int i = 0; i < N; i++)
        disjointSet[i] = i;

    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (isIntersect(lines[i], lines[j]) && !setFind(i, j))
                setUnion(i, j);

    generateOutput();

    return 0;
}

inline int ccw(pii p1, pii p2, pii p3) {
    int x1, x2, x3, y1, y2, y3;
    tie(x1, y1) = p1;
    tie(x2, y2) = p2;
    tie(x3, y3) = p3;

    int result = ((x1 * y2) + (x2 * y3) + (x3 * y1))
                - ((x2 * y1) + (x3 * y2) + (x1 * y3));

    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}


inline bool isIntersect(line l1, line l2) {
    pii p1, p2, p3, p4;
    tie(p1, p2) = l1;
    tie(p3, p4) = l2;

    int ccw1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int ccw2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (ccw1 == 0 && ccw2 == 0) {
        if (p1 > p2) {
            pii temp = p1;
            p1 = p2;
            p2 = temp;
        }

        if (p3 > p4) {
            pii temp = p3;
            p3 = p4;
            p4 = temp;
        }

        return p3 <= p2 && p1 <= p4;
    }

    return ccw1 <= 0 && ccw2 <= 0;
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

inline bool setFind(int n1, int n2) {
    while (n1 != disjointSet[n1])
        n1 = disjointSet[n1];

    while (n2 != disjointSet[n2])
        n2 = disjointSet[n2];

    return n1 == n2;
}

inline void generateOutput() {
    vector<int> counts(N, 0);
    for (int i = 0; i < N; i++) {
        int v = i;
        while (v != disjointSet[v])
            v = disjointSet[v];
        counts[v]++;
    }

    int groups = 0, maxCount = 0;

    for (int cnt : counts)
        if (cnt > 0) {
            groups++;
            maxCount = max(maxCount, cnt);
        }

    cout << groups << '\n' << maxCount;
}