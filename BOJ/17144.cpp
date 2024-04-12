#include <iostream>
#include <vector>
using namespace std;

#define CLEANER -1

static int R, C, T;
static int dirR[4] = { -1, 0, 1, 0 };
static int dirC[4] = { 0, -1, 0, 1 };

static vector<vector<int>> map;
static vector<pair<int, int>> cleanerLocation;
static vector<pair<int, int>> upperCleaningFlow, lowerCleaningFlow;

static inline bool CheckValidPoint(pair<int, int>& point);
static inline void SetCleanedLocation();
static inline void Clean(int seconds);
static inline int GetDustCount();

static inline void PrintMap() {
    cout << endl;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++)
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

    cin >> R >> C >> T;

    map.resize(R, vector<int>(C));
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++)
            cin >> map[r][c];
        
        if (map[r][0] == CLEANER)
            cleanerLocation.push_back({r, 0});
    }

    SetCleanedLocation();
    Clean(T);
    cout << GetDustCount();
    
    return 0;
}

static inline bool CheckValidPoint(pair<int, int>& point) {
    int r = point.first, c = point.second;
    return (0 <= r && r < R && 0 <= c && c < C && map[r][c] != CLEANER);
}

static inline void SetCleanedLocation() {
    pair<int, int> loc1 = cleanerLocation[0], loc2 = cleanerLocation[1];

    // right direction(both of air flows to the same direction)
    for (int c = 1; c < C; c++) {
        upperCleaningFlow.push_back({loc1.first, c});
        lowerCleaningFlow.push_back({loc2.first, c});
    }

    // upper/down direction(each of air flows to the different direction)
    for (int r = loc1.first - 1; r >= 0; r--)
        upperCleaningFlow.push_back({r, C - 1});
    for (int r = loc2.first + 1; r < R; r++)
        lowerCleaningFlow.push_back({r, C - 1});

    // left direction(both of air flows to the same direction)
    for (int c = C - 2; c >= 0; c--) {
        upperCleaningFlow.push_back({0, c});
        lowerCleaningFlow.push_back({R - 1, c});
    }

    // down/upper direction(each of air flows to the different direction)
    for (int r = 1; r < loc1.first; r++)
        upperCleaningFlow.push_back({r, 0});
    for (int r = R - 2; r > loc2.first; r--)
        lowerCleaningFlow.push_back({r, 0});
}

static inline void Clean(int seconds) {
    for (int _ = 0; _ < seconds; _++) {
        vector<pair<int, int>> dusts;
        vector<vector<int>> priorMap = map;

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (map[r][c] > 0)
                    dusts.push_back({r, c});

        // Spreading
        for (pair<int, int>& curr : dusts) {
            int spreadAmount = priorMap[curr.first][curr.second] / 5;

            for (int dir = 0; dir < 4; dir++) {
                pair<int, int> next = {curr.first + dirR[dir], curr.second + dirC[dir]};

                if (!CheckValidPoint(next))
                    continue;
                
                map[next.first][next.second] += spreadAmount;
                map[curr.first][curr.second] -= spreadAmount;
            }
        }

        // Flowing
        for (int i = upperCleaningFlow.size() - 1; i > 0; i--) {
            pair<int, int> curr = upperCleaningFlow[i], prior = upperCleaningFlow[i - 1];
            map[curr.first][curr.second] = map[prior.first][prior.second];
        }
        map[upperCleaningFlow[0].first][upperCleaningFlow[0].second] = 0;
        
        for (int i = lowerCleaningFlow.size() - 1; i > 0; i--) {
            pair<int, int> curr = lowerCleaningFlow[i], prior = lowerCleaningFlow[i - 1];
            map[curr.first][curr.second] = map[prior.first][prior.second];
        }
        map[lowerCleaningFlow[0].first][lowerCleaningFlow[0].second] = 0;
    }
}

static inline int GetDustCount() {
    int total = 0;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            if (map[r][c] > 0)
                total += map[r][c];
    
    return total;
}