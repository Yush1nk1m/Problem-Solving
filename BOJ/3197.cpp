#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int dR[4] = {0, 0, 1, -1};
static int dC[4] = {1, -1, 0, 0};
static inline bool isValid(int r, int c, int maxR, int maxC) {
    return (0 <= r && r < maxR && 0 <= c && c < maxC);
}

static inline int Find(vector<int>& set, int a) {
    while (a != set[a])
        a = set[a];
    return a;
}

static inline void Union(vector<int>& set, int a, int b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    queue<int> nonRootA, nonRootB;

    while (a != set[a]) {
        nonRootA.push(a);
        a = set[a];
    }

    while (b != set[b]) {
        nonRootB.push(b);
        b = set[b];
    }

    while (!nonRootA.empty()) {
        set[nonRootA.front()] = a;
        nonRootA.pop();
    }
    
    while (!nonRootB.empty()) {
        set[nonRootB.front()] = a;
        nonRootB.pop();
    }

    set[b] = a;
}

void PrintSetMap(vector<vector<int>>& setNumbers) {
    cout << endl;
    for (int r = 0; r < setNumbers.size(); r++) {
        for (int c = 0; c < setNumbers[0].size(); c++) {
            cout << setNumbers[r][c] << ' ';
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C;
    cin >> R >> C;
    
    vector<pair<int, int>> swans;
    vector<vector<char>> map(R, vector<char>(C));
    vector<vector<bool>> visited(R, vector<bool>(C, true));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++) {
            cin >> map[r][c];
            if (map[r][c] == 'L')
                swans.push_back({r, c});
            else if (map[r][c] == 'X')
                visited[r][c] = false;
        }
    
    vector<vector<int>> setNumbers(R, vector<int>(C, 0));
    queue<pair<int, int>> bfsQueue;
    queue<pair<int, int>> iceQueue;

    int setNum = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (map[r][c] != 'X' && setNumbers[r][c] == 0) {
                queue<pair<int, int>> setQueue;
                setNumbers[r][c] = ++setNum;
                setQueue.push({r, c});

                while (!setQueue.empty()) {
                    int currR = setQueue.front().first, currC = setQueue.front().second;
                    setQueue.pop();

                    bool isIceTouched = false;
                    for (int i = 0; i < 4; i++) {
                        int nextR = currR + dR[i], nextC = currC + dC[i];

                        if (!isValid(nextR, nextC, R, C)) continue;

                        if (map[nextR][nextC] == 'X') {
                            isIceTouched = true;
                        }
                        else if (setNumbers[nextR][nextC] == 0) {
                            setNumbers[nextR][nextC] = setNumbers[currR][currC];
                            setQueue.push({nextR, nextC});
                        }
                    }
                    if (isIceTouched) bfsQueue.push({currR, currC});
                }
            }
        }
    }

    vector<int> set(setNum + 1);
    for (int i = 0; i <= setNum; i++)
        set[i] = i;
    
    int days = 0;
    int queueSize = bfsQueue.size();
    if (Find(set, setNumbers[swans[0].first][swans[0].second]) != Find(set, setNumbers[swans[1].first][swans[1].second])) {
        while (!bfsQueue.empty()) {
            queueSize--;
            int r = bfsQueue.front().first, c = bfsQueue.front().second;
            bfsQueue.pop();

            for (int i = 0; i < 4; i++) {
                int nextR = r + dR[i], nextC = c + dC[i];
                
                if (!isValid(nextR, nextC, R, C)) continue;

                if (visited[nextR][nextC] && Find(set, setNumbers[nextR][nextC]) != Find(set, setNumbers[r][c]))
                    Union(set, setNumbers[nextR][nextC], setNumbers[r][c]);
                else if (setNumbers[nextR][nextC] == 0) {
                    setNumbers[nextR][nextC] = setNumbers[r][c];
                    iceQueue.push({nextR, nextC});
                }
            }

            if (queueSize == 0) {
                if (Find(set, setNumbers[swans[0].first][swans[0].second]) == Find(set, setNumbers[swans[1].first][swans[1].second]))
                    break;
                
                while (!iceQueue.empty()) {
                    int iceR = iceQueue.front().first, iceC = iceQueue.front().second;
                    visited[iceR][iceC] = true;
                    bfsQueue.push(iceQueue.front());
                    iceQueue.pop();
                }

                queueSize = bfsQueue.size();
                days++;
            }
        }
    }
    
    cout << days;

    return 0;
}