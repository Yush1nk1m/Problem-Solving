#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

void Union(vector<int>& set, int a, int b);
bool Find(vector<int>& set, int a, int b);
void markIsland(vector<vector<int>>& map, vector<vector<bool>>& visited, int r, int c, int number);
void findBridges(vector<vector<int>>& map, vector<tuple<int, int, int>>& bridges);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M));
    vector<tuple<int, int, int>> bridges;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> map[r][c];
            visited[r][c] = !map[r][c];
        }
    }

    int islandNumber = 1;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (!visited[r][c])
                markIsland(map, visited, r, c, islandNumber++);
        }
    }
    islandNumber--;

    vector<int> set(islandNumber + 1);
    for (int i = 1; i <= islandNumber; i++)
        set[i] = i;

    findBridges(map, bridges);

    sort(bridges.begin(), bridges.end());

    int count = 0;
    int weight = 0;
    for (tuple<int, int, int> edge : bridges) {
        int w = get<0>(edge), start = get<1>(edge), end = get<2>(edge);
        if (!Find(set, start, end)) {
            count++;
            weight += w;
            Union(set, start, end);
        }
    }

    if (count < islandNumber - 1)
        cout << -1;
    else
        cout << weight;

    return 0;
}

void Union(vector<int>& set, int a, int b) {
    while (a != set[a])
        a = set[a];
    
    while (b != set[b])
        b = set[b];

    set[b] = a;
}

bool Find(vector<int>& set, int a, int b) {
    stack<int> nonRootA, nonRootB;

    while (a != set[a]) {
        nonRootA.push(a);
        a = set[a];
    }

    while (b != set[b]) {
        nonRootB.push(b);
        b = set[b];
    }

    if (a != b) {
        while (!nonRootA.empty()) {
            set[nonRootA.top()] = a;
            nonRootA.pop();
        }

        while (!nonRootB.empty()) {
            set[nonRootB.top()] = b;
            nonRootB.pop();
        }

        return false;
    } else {
        while (!nonRootA.empty()) {
            set[nonRootA.top()] = a;
            nonRootA.pop();
        }

        while (!nonRootB.empty()) {
            set[nonRootB.top()] = a;
            nonRootB.pop();
        }

        set[b] = a;

        return true;
    }
}

void markIsland(vector<vector<int>>& map, vector<vector<bool>>& visited, int r, int c, int number) {
    int row = map.size(), col = map[0].size();
    queue<pair<int, int>> locations;
    
    visited[r][c] = true;
    locations.push({r, c});
    map[r][c] = number;
    while (!locations.empty()) {
        int curr_r = locations.front().first, curr_c = locations.front().second;
        locations.pop();

        if (curr_r - 1 >= 0 && !visited[curr_r-1][curr_c]) {
            visited[curr_r-1][curr_c] = true;
            locations.push({curr_r-1, curr_c});
            map[curr_r-1][curr_c] = number;
        }
        if (curr_r + 1 < row && !visited[curr_r+1][curr_c]) {
            visited[curr_r+1][curr_c] = true;
            locations.push({curr_r+1, curr_c});
            map[curr_r+1][curr_c] = number;
        }
        if (curr_c - 1 >= 0 && !visited[curr_r][curr_c-1]) {
            visited[curr_r][curr_c-1] = true;
            locations.push({curr_r, curr_c-1});
            map[curr_r][curr_c-1] = number;
        }
        if (curr_c + 1 < col && !visited[curr_r][curr_c+1]) {
            visited[curr_r][curr_c+1] = true;
            locations.push({curr_r, curr_c+1});
            map[curr_r][curr_c+1] = number;
        }
    }
}

void findBridges(vector<vector<int>>& map, vector<tuple<int, int, int>>& bridges) {
    int row = map.size(), col = map[0].size();

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (map[r][c] != 0) {
                int start = map[r][c];

                // 위 방향 다리 건설
                if (r - 1 >= 0 && map[r-1][c] == 0) {
                    int length = 0;
                    int p = r - 1;

                    while (p >= 0 && map[p][c] == 0) {
                        p--;
                        length++;
                    }

                    if (p >= 0 && map[p][c] != 0 && map[p][c] != start && length >= 2) {
                        int end = map[p][c];
                        bridges.push_back(make_tuple(length, start, end));
                    }
                }
                // 아래 방향 다리 건설
                if (r + 1 < row && map[r+1][c] == 0) {
                    int length = 0;
                    int p = r + 1;
                    
                    while (p < row && map[p][c] == 0) {
                        p++;
                        length++;
                    }

                    if (p < row && map[p][c] != 0 && map[p][c] != start && length >= 2) {
                        int end = map[p][c];
                        bridges.push_back(make_tuple(length, start, end));
                    }
                }
                // 왼 방향 다리 건설
                if (c - 1 >= 0 && map[r][c-1] == 0) {
                    int length = 0;
                    int p = c - 1;

                    while (p >= 0 && map[r][p] == 0) {
                        p--;
                        length++;
                    }

                    if (p >= 0 && map[r][p] != 0 && map[r][p] != start && length >= 2) {
                        int end = map[r][p];
                        bridges.push_back(make_tuple(length, start, end));
                    }
                }
                // 오른 방향 다리 건설
                if (c + 1 < col && map[r][c+1] == 0) {
                    int length = 0;
                    int p = c + 1;

                    while (p < col && map[r][p] == 0) {
                        p++;
                        length++;
                    }

                    if (p < col && map[r][p] != 0 && map[r][p] != start && length >= 2) {
                        int end = map[r][p];
                        bridges.push_back(make_tuple(length, start, end));
                    }
                }
            }
        }
    }
}