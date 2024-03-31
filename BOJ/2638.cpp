#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define CHEESE 1
#define EMPTY 0

#define OUTER 0
#define INNER 1

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

static int dR[4] = { -1, 1, 0, 0 };
static int dC[4] = { 0, 0, -1, 1 };

static vector<vector<int>> paper;
static vector<vector<int>> labels;
static vector<vector<int>> touchCount;

static inline bool isValidPoint(int r, int c, int N, int M) {
    return (0 <= r && r < N && 0 <= c && c < M);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    paper.resize(N, vector<int>(M, 0));
    labels.resize(N, vector<int>(M, INNER));
    touchCount.resize(N, vector<int>(M, 0));

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            cin >> paper[r][c];
        }
    
    queue<pair<int, int>> bfsQueue;
    queue<pair<int, int>> airQueue;

    labels[0][0] = OUTER;
    airQueue.push({0, 0});
    while (!airQueue.empty()) {
        int r = airQueue.front().first, c = airQueue.front().second;
        airQueue.pop();

        for (int i = 0; i < 4; i++) {
            int nextR = r + dR[i], nextC = c + dC[i];

            if (!isValidPoint(nextR, nextC, N, M)) continue;

            if (labels[nextR][nextC] == INNER) {
                if (paper[nextR][nextC] == EMPTY) {
                    labels[nextR][nextC] = OUTER;
                    airQueue.push({nextR, nextC});
                }
                else if (paper[nextR][nextC] == CHEESE) {
                    if (++touchCount[nextR][nextC] == 2) {
                        bfsQueue.push({nextR, nextC});
                    }
                }
            }
        }
    }

    int hours = 0;
    int currentHourQueueCount = bfsQueue.size();
    while (!bfsQueue.empty()) {
        currentHourQueueCount--;
        int r = bfsQueue.front().first, c = bfsQueue.front().second;
        bfsQueue.pop();

        paper[r][c] = EMPTY;
        labels[r][c] = OUTER;
        airQueue.push({r, c});

        if (currentHourQueueCount == 0) {
            while (!airQueue.empty()) {
                int airR = airQueue.front().first, airC = airQueue.front().second;
                airQueue.pop();

                for (int i = 0; i < 4; i++) {
                    int nextAirR = airR + dR[i], nextAirC = airC + dC[i];

                    if (!isValidPoint(nextAirR, nextAirC, N, M)) continue;

                    if (labels[nextAirR][nextAirC] == INNER) {
                        if (paper[nextAirR][nextAirC] == EMPTY) {
                            labels[nextAirR][nextAirC] = OUTER;
                            airQueue.push({nextAirR, nextAirC});
                        }
                        else if (paper[nextAirR][nextAirC] == CHEESE) {
                            if (++touchCount[nextAirR][nextAirC] == 2) {
                                bfsQueue.push({nextAirR, nextAirC});
                            }
                        }
                    }
                }
            }

            currentHourQueueCount = bfsQueue.size();
            hours++;
        }
    }

    cout << hours;

    return 0;
}