#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

#define NONE    -1000000001
#define INF     1000000001

int N, M, minCost = INF;
vector<int> m, c;
vector<vector<int>> cache(101, vector<int>(10001, NONE));

int dfs(int idx, int limitedCost);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    m.resize(N);
    c.resize(N);

    for (int i = 0; i < N; i++)
        cin >> m[i];
    for (int i = 0; i < N; i++)
        cin >> c[i];

    int low = 0, high = 10001;
    while (low <= high) {
        int mid = (low + high) / 2;
        int memory = dfs(0, mid);
        if (memory >= M) {
            minCost = min(minCost, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << minCost;

    return 0;
}

int dfs(int idx, int limitedCost) {
    if (limitedCost < 0)
        return NONE;
    else if (idx >= N)
        return 0;

    int& ret = cache[idx][limitedCost];
    if (ret != NONE)
        return ret;

    ret = max(
        dfs(idx + 1, limitedCost - c[idx]) + m[idx],
        dfs(idx + 1, limitedCost)
    );

    return ret;
}