// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> pii;
// typedef tuple<int, int, int> ti;

// #define NONE    -1
// #define PINF    100000000
// #define MINF    -100000000

// int N, K;
// vector<int> depth;
// vector<vector<pii>> graph;
// vector<vector<ti>> parent;

// inline void initializeTree();
// inline void findMinMax(int u, int v);

// int main(int argc, char* argv[]) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> N;

//     graph = vector<vector<pii>>(N + 1);
//     for (int _ = 0; _ < N - 1; _++) {
//         int A, B, C;
//         cin >> A >> B >> C;
//         graph[A].push_back({ B, C });
//         graph[B].push_back({ A, C });
//     }

//     initializeTree();

//     cin >> K;
//     while (K--) {
//         int D, E;
//         cin >> D >> E;
//         findMinMax(D, E);
//     }

//     return 0;
// }

// inline void initializeTree() {
//     depth = vector<int>(N + 1, NONE);
//     parent = vector<vector<ti>>(18, vector<ti>(N + 1, make_tuple(0, PINF, MINF)));

//     queue<int> q;
//     q.push(1);
//     depth[1] = 0;
//     while (!q.empty()) {
//         int curr = q.front();
//         q.pop();

//         for (pii& p : graph[curr])
//             if (depth[p.first] == NONE) {
//                 q.push(p.first);
//                 depth[p.first] = depth[curr] + 1;
//                 parent[0][p.first] = make_tuple(curr, p.second, p.second);
//             }
//     }

//     for (int k = 1; k <= 17; k++)
//         for (int node = 1; node <= N; node++) {
//             if (floor(log2(depth[node])) < k)
//                 continue;
//             ti c = parent[k-1][node], p = parent[k-1][get<0>(parent[k-1][node])];
//             parent[k][node] = make_tuple(get<0>(p), min(get<1>(c), get<1>(p)), max(get<2>(c), get<2>(p)));
//         }

//     for (int node = 1; node <= N; node++) {
//         for (int k = 0; k <= 3; k++) {
//             cout << "(" << get<1>(parent[k][node]) << ", " << get<2>(parent[k][node]) << ") ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// inline void findMinMax(int u, int v) {
//     int minL = PINF, maxL = MINF, depthDiff = abs(depth[u] - depth[v]);

//     if (depth[u] < depth[v]) {
//         while (depthDiff) {
//             int k = floor(log2(depth[v]));
//             ti& c = parent[k][v];
//             minL = min(minL, get<1>(c));
//             maxL = max(maxL, get<2>(c));
//             depthDiff -= pow(2, k);
//             v = get<0>(c);
//         }
//     } else if (depth[u] > depth[v]) {
//         while (depthDiff) {
//             int k = floor(log2(depth[u]));
//             ti& c = parent[k][u];
//             minL = min(minL, get<1>(c));
//             maxL = max(maxL, get<2>(c));
//             depthDiff -= pow(2, k);
//             u = get<0>(c);
//         }
//     }

//     cout << "PASSED "<< endl;

//     while (u != v) {
//         int k = floor(log2(depth[u]));
//         while (k) {
//             if (parent[k][u] != parent[k][v])
//                 break;
//             k--;
//         }

//         ti& pu = parent[k][u];
//         ti& pv = parent[k][v];
//         minL = min(minL, min(get<1>(pu), get<1>(pv)));
//         maxL = max(maxL, max(get<2>(pu), get<2>(pv)));
//         u = get<0>(pu);
//         v = get<0>(pv);
//     }

//     cout << minL << ' ' << maxL << '\n';
// }