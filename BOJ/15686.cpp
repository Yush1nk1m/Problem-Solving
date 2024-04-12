#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000
#define EMPTY 0
#define HOUSE 1
#define STORE 2

static int N, M;
static int minimumDistance = INF;
static int dirR[4] = {-1, 0, 1, 0};
static int dirC[4] = {0, -1, 0, 1};

static vector<vector<int>> map;
static vector<pair<int, int>> houses;
static vector<pair<int, int>> stores;
static vector<int> selectedIndices;

static inline void SearchAllCombination();
static void RecursiveCombination(int depth, int priorIndex);
static inline int GetChickenDistance();
static inline bool CheckValidPoint(pair<int, int>& point);

static inline void PrintMap(vector<vector<int>> map) {
    cout << endl;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++)
            cout << map[r][c] << ' ';
        cout << endl;
    }
    cout << endl;
    char c;
    cin >> c;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    map.resize(N, vector<int>(N));
    selectedIndices.resize(M + 1);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> map[r][c];

            if (map[r][c] == HOUSE)
                houses.push_back({r, c});
            else if (map[r][c] == STORE)
                stores.push_back({r, c});
        }
    }

    SearchAllCombination();

    cout << minimumDistance;

    return 0;
}

static inline void SearchAllCombination() {
    for (int startIndex = 0; startIndex <= stores.size() - M; startIndex++) {
        selectedIndices[1] = startIndex;
        RecursiveCombination(1, startIndex);
    }
}

static void RecursiveCombination(int depth, int priorIndex) {
    if (depth == M) {
        minimumDistance = min(minimumDistance, GetChickenDistance());
        return;
    }

    for (int nextIndex = priorIndex + 1; nextIndex < stores.size(); nextIndex++) {
        selectedIndices[depth + 1] = nextIndex;
        RecursiveCombination(depth + 1, nextIndex);
    }
}

static inline int GetChickenDistance() {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<int>> copyMap = map;
    queue<pair<int, int>> bfsQueue;
    int totalDist = 0;

    for (int i = 1; i <= M; i++) {
        pair<int, int> selectedStore = stores[selectedIndices[i]];
        visited[selectedStore.first][selectedStore.second] = true;
        bfsQueue.push(selectedStore);
    }

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (copyMap[r][c] == STORE && !visited[r][c])
                copyMap[r][c] = EMPTY;
    
    int dist = 0;
    while (!bfsQueue.empty()) {
        dist++;
        int size = bfsQueue.size();

        for (int _ = 0; _ < size; _++) {
            pair<int, int> curr = bfsQueue.front();
            bfsQueue.pop();

            for (int dir = 0; dir < 4; dir++) {
                pair<int, int> next = { curr.first + dirR[dir], curr.second + dirC[dir] };

                if (!CheckValidPoint(next))
                    continue;

                if (!visited[next.first][next.second]) {
                    visited[next.first][next.second] = true;
                    bfsQueue.push(next);

                    if (copyMap[next.first][next.second] == HOUSE) {
                        totalDist += dist;
                    }
                }
            }
        }
    }
    
    return totalDist;
}

static inline bool CheckValidPoint(pair<int, int>& point) {
    int r = point.first, c = point.second;
    return (0 <= r && r < N && 0 <= c && c < N);
}