#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;

inline long double Distance(pair<long double, long double> p1, pair<long double, long double> p2);
inline bool Find(vector<int>& set, int v1, int v2);
inline void Union(vector<int>& set, int v1, int v2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> disjointSet(n);
    for (int i = 0; i < n; i++)
        disjointSet[i] = i;

    vector<pair<long double, long double>> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;
    
    vector<tuple<long double, int, int>> edgeList;
    for (int s = 0; s < n; s++)
        for (int e = s + 1; e < n; e++) {
            edgeList.push_back(
                make_tuple(Distance(points[s], points[e]), s, e)
            );
        }
    sort(edgeList.begin(), edgeList.end());
    
    int count = 0;
    long double totalDistance = 0.0;
    for (tuple<long double, int, int>& edge : edgeList) {
        long double distance = get<0>(edge);
        int v1 = get<1>(edge), v2 = get<2>(edge);

        if (!Find(disjointSet, v1, v2)) {
            totalDistance += distance;
            Union(disjointSet, v1, v2);
            if (++count == n - 1) break;
        }
    }

    cout << fixed << setprecision(2) << totalDistance;

    return 0;
}

inline long double Distance(pair<long double, long double> p1, pair<long double, long double> p2) {
    long double x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
    return (sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2)));
}

inline bool Find(vector<int>& set, int v1, int v2) {
    stack<int> v1Parents, v2Parents;

    while (v1 != set[v1]) {
        v1Parents.push(v1);
        v1 = set[v1];
    }

    while (v2 != set[v2]) {
        v2Parents.push(v2);
        v2 = set[v2];
    }

    while (!v1Parents.empty()) {
        set[v1Parents.top()] = v1;
        v1Parents.pop();
    }

    while (!v2Parents.empty()) {
        set[v2Parents.top()] = v2;
        v2Parents.pop();
    }

    if (v1 == v2)
        return true;
    else
        return false;
}

inline void Union(vector<int>& set, int v1, int v2) {
    while (v1 != set[v1])
        v1 = set[v1];

    while (v2 != set[v2])
        v2 = set[v2];
    
    set[v2] = v1;
}