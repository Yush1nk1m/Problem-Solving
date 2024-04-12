#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>
using namespace std;

#define EMPTY 0
#define SHARK 9

static int dirR[4] = { -1, 0, 1, 0 };
static int dirC[4] = { 0, -1, 0, 1 };

static int N;
static int timePassed = 0;
static int sharkSize = 2;
static int sharkFeed = 2;
static pair<int, int> sharkLocation;
static vector<vector<int>> map;

static inline bool ValidPointCheck(int r, int c);
static inline bool MapEmptyCheck();
static inline pair<int, int> NextLocation(pair<int, int>& sharkLocation);

// static inline void PrintMap() {
//     cout << '\n';
//     for (int r = 0; r < N; r++) {
//         for (int c = 0; c < N; c++) {
//             cout << map[r][c] << ' ';
//         }
//         cout << endl;
//     }
//     cout << "TIME PASSED: " << timePassed << endl;

//     cout << endl;

//     sleep(1);
// }

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    map.resize(N, vector<int>(N));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> map[r][c];
            if (map[r][c] == SHARK)
                sharkLocation = {r, c};
        }
    }

    while (!MapEmptyCheck()) {
        pair<int, int> next = NextLocation(sharkLocation);
        
        if (next.first == sharkLocation.first && next.second == sharkLocation.second)
            break;
        
        map[next.first][next.second] = SHARK;
        map[sharkLocation.first][sharkLocation.second] = EMPTY;
        sharkLocation = next;

        // PrintMap();

        if (--sharkFeed == 0)
            sharkFeed = ++sharkSize;
    }

    cout << timePassed;

    return 0;
}

static inline bool ValidPointCheck(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < N);
}

static inline bool MapEmptyCheck() {
    bool isEmpty = true;
    for (int r = 0; r < N && isEmpty; r++)
        for (int c = 0; c < N && isEmpty; c++)
            if (map[r][c] != EMPTY && map[r][c] != SHARK)
                isEmpty = false;
    return isEmpty;
}

static inline pair<int, int> NextLocation(pair<int, int>& sharkLocation) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int, int>> bfsQueue;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> candidates;

    bool edibleFound = false;
    int thisTime = 0;

    visited[sharkLocation.first][sharkLocation.second] = true;
    bfsQueue.push(sharkLocation);

    while (!bfsQueue.empty() && !edibleFound) {
        thisTime++;
        timePassed++;
        int size = bfsQueue.size();

        for (int _ = 0; _ < size; _++) {
            pair<int, int> curr = bfsQueue.front();
            bfsQueue.pop();

            for (int dir = 0; dir < 4; dir++) {
                pair<int, int> next = { curr.first + dirR[dir], curr.second + dirC[dir] };
                
                if (!ValidPointCheck(next.first, next.second))
                    continue;
                
                if (!visited[next.first][next.second] &&
                    map[next.first][next.second] != EMPTY &&
                    map[next.first][next.second] < sharkSize) {
                    
                    visited[next.first][next.second] = true;
                    edibleFound = true;
                    candidates.push(next);
                }
                
                if (!visited[next.first][next.second] &&
                    (map[next.first][next.second] == EMPTY || map[next.first][next.second] == sharkSize)) {
                        visited[next.first][next.second] = true;
                        bfsQueue.push(next);
                }
            }
        }
    }

    if (!candidates.empty())
        return candidates.top();

    // the case when there's no edible fish
    timePassed -= thisTime;
    return sharkLocation;
}