#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int T, N, W;
vector<vector<int>> m, c, m1, m2, m3, m4, c1, c2, c3, c4;

inline int solve();
int dfs(int depth, int mask);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N >> W;

        m = vector<vector<int>>(2, vector<int>(N));
        for (int i = 0; i < N; i++)
            cin >> m[0][i];
        for (int i = 0; i < N; i++)
            cin >> m[1][i];

        cout << solve() << '\n';
    }
}

inline int solve() {
    // case 1: no shift
    m1 = vector<vector<int>>(2, vector<int>(N + 2, INF));
    c1 = vector<vector<int>>(N + 1, vector<int>(4, INF));
    // case 2: shift 1st col of upper row
    m2 = vector<vector<int>>(2, vector<int>(N + 2, INF));
    c2 = vector<vector<int>>(N + 1, vector<int>(4, INF));
    // case 3: shift 1st col of lower row
    m3 = vector<vector<int>>(2, vector<int>(N + 2, INF));
    c3 = vector<vector<int>>(N + 1, vector<int>(4, INF));
    // case 4: shift 1st col
    m4 = vector<vector<int>>(2, vector<int>(N + 2, INF));
    c4 = vector<vector<int>>(N + 1, vector<int>(4, INF));

    for (int i = 0; i < N; i++) {
        m1[0][i] = m2[0][i] = m3[0][i] = m4[0][i] = m[0][i];
        m1[1][i] = m2[1][i] = m3[1][i] = m4[1][i] = m[1][i];
    }

    // case 2
    m2[0][N] = m2[0][0];
    m2[0][0] = INF;
    // case 3
    m3[1][N] = m3[1][0];
    m3[1][0] = INF;
    // case 4
    m4[0][N] = m4[0][0];
    m4[1][N] = m4[1][0];
    m4[0][0] = m4[1][0] = INF;
    
    int cnt = INF;
    m = m1;
    c = c1;
    cnt = min(cnt, dfs(0, 3));
    m = m2;
    c = c2;
    cnt = min(cnt, dfs(0, 2));
    m = m3;
    c = c3;
    cnt = min(cnt, dfs(0, 1));
    m = m4;
    c = c4;
    cnt = min(cnt, dfs(0, 0));

    return cnt;
}

int dfs(int depth, int mask) {
    if (depth == N + 1)
        return 0;
    
    int& ret = c[depth][mask];
    if (ret != INF)
        return ret;

    if (mask == 0)
        ret = dfs(depth + 1, 1);
    else if (mask == 1) {

    }
    else if (mask == 2) {

    }
    else if (mask == 3) {

    }

    return ret;
}