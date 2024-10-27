#include <bits/stdc++.h>
using namespace std;

#define PATH    '0'
#define WALL    '1'
#define START   'S'
#define KEY     'K'
#define NONE    -1

int N, M;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
map<pair<int, int>, int> idxs;
vector<vector<char>> maze;
vector<pair<int, int>> nodes(1);
vector<tuple<int, int, int>> edgeList;
vector<int> parent;

inline bool isValidPoint(int r, int c);
inline void addEdgesByBFS(pair<int, int> start);
inline void unionSet(int v1, int v2);
inline bool findSet(int v1, int v2);
inline int getMinimumDistance();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    maze.resize(N, vector<char>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            cin >> maze[r][c];

            if (maze[r][c] == START) {
                nodes[0] = { r, c };
                idxs[{ r, c }] = 0;
            } else if (maze[r][c] == KEY) {
                nodes.push_back({ r, c });
                idxs[{ r, c }] = nodes.size() - 1;
            }
        }

    for (pair<int, int>& node : nodes)
        addEdgesByBFS(node);

    cout << getMinimumDistance();

    return 0;
}

inline bool isValidPoint(int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < N;
}

inline void addEdgesByBFS(pair<int, int> start) {
    queue<pair<int, int>> q;
    vector<vector<int>> visited(N, vector<int>(N, NONE));

    q.push(start);
    visited[start.first][start.second] = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int r = curr.first + dr[d], c = curr.second + dc[d];

            if (!isValidPoint(r, c) || maze[r][c] == WALL || visited[r][c] != NONE)
                continue;

            visited[r][c] = visited[curr.first][curr.second] + 1;
            q.push({ r, c });

            if (maze[r][c] == KEY)
                edgeList.push_back(make_tuple(visited[r][c], idxs[start], idxs[{ r, c }]));
        }
    }
}

inline void unionSet(int v1, int v2) {
    stack<int> stk;

    while (v1 != parent[v1]) {
        stk.push(v1);
        v1 = parent[v1];
    }

    while (v2 != parent[v2]) {
        stk.push(v2);
        v2 = parent[v2];
    }

    parent[v2] = v1;
    while (!stk.empty()) {
        parent[stk.top()] = v1;
        stk.pop();
    }
}

inline bool findSet(int v1, int v2) {
    while (v1 != parent[v1])
        v1 = parent[v1];
    while (v2 != parent[v2])
        v2 = parent[v2];
    return v1 == v2;
}

inline int getMinimumDistance() {
    sort(edgeList.begin(), edgeList.end());

    parent.resize(nodes.size());
    for (int i = 0; i < parent.size(); i++)
        parent[i] = i;
    
    int addedCount = 0;
    int totalDistance = 0;
    for (tuple<int, int, int>& edge : edgeList) {
        int weight = get<0>(edge);
        int v1 = get<1>(edge);
        int v2 = get<2>(edge);

        if (findSet(v1, v2)) continue;

        unionSet(v1, v2);
        totalDistance += weight;

        addedCount++;
        if (addedCount == nodes.size() - 1) break;
    }

    return (addedCount == nodes.size() - 1) ? totalDistance : -1;
}