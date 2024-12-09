#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;
typedef pair<int, int> pii;

int N, cost, connected;
vector<int> disjointSet;
vector<pii> xs, ys, zs;
priority_queue<tup, vector<tup>, greater<tup>> pq;

inline bool setFind(int n1, int n2);
inline void setUnion(int n1, int n2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    disjointSet.resize(N);
    for (int i = 0; i < N; i++)
        disjointSet[i] = i;

    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        xs.push_back({ x, i });
        ys.push_back({ y, i });
        zs.push_back({ z, i });
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    sort(zs.begin(), zs.end());

    for (int i = 1; i < N; i++) {
        pq.push(make_tuple(abs(xs[i].first - xs[i-1].first), xs[i].second, xs[i-1].second));
        pq.push(make_tuple(abs(ys[i].first - ys[i-1].first), ys[i].second, ys[i-1].second));
        pq.push(make_tuple(abs(zs[i].first - zs[i-1].first), zs[i].second, zs[i-1].second));
    }

    while (connected < N - 1) {
        tup curr = pq.top();
        pq.pop();

        if (!setFind(get<1>(curr), get<2>(curr))) {
            setUnion(get<1>(curr), get<2>(curr));
            cost += get<0>(curr);
            connected++;
        }
    }

    cout << cost;
    
    return 0;
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