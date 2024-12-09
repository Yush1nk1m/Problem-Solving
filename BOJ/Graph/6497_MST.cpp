#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, int, int> tup;

int m, n;
ll totalCost;
vector<int> disjointSet;
priority_queue<tup, vector<tup>, greater<tup>> pq;

inline void solve();
inline ll mst();
inline bool setFind(int n1, int n2);
inline void setUnion(int n1, int n2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> m >> n) {
        if (m == 0 && n == 0)
            break;
        solve();
    }

    return 0;
}

inline void solve() {
    totalCost = 0;
    disjointSet = vector<int>(m);
    for (int i = 0; i < m; i++)
        disjointSet[i] = i;

    while (n--) {
        int n1, n2;
        ll cost;
        cin >> n1 >> n2 >> cost;

        totalCost += cost;
        pq.push(make_tuple(cost, n1, n2));
    }

    cout << totalCost - mst() << '\n';
}

inline ll mst() {
    ll minCost = 0;
    int connectedCount = 0;

    while (connectedCount < m - 1) {
        tup curr = pq.top();
        pq.pop();

        if (!setFind(get<1>(curr), get<2>(curr))) {
            setUnion(get<1>(curr), get<2>(curr));
            minCost += get<0>(curr);
            connectedCount++;
        }
    }
    pq = priority_queue<tup, vector<tup>, greater<tup>>();

    return minCost;
}

inline bool setFind(int n1, int n2) {
    while (n1 != disjointSet[n1])
        n1 = disjointSet[n1];

    while (n2 != disjointSet[n2])
        n2 = disjointSet[n2];

    return n1 == n2;
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