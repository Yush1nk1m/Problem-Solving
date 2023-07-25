#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    int r;
    int c;
} coord;

queue<coord> coords;
vector<vector<int>> ground;
vector<coord> cabbages;
vector<vector<bool>> visited;

int T, N, M, K;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    for (int _ = 0; _ < T; _++) {
        cin >> N >> M >> K;

        ground.resize(N, vector<int>(M));
        ground.assign(N, vector<int>(M, 0));

        visited.resize(N, vector<bool>(M));
        visited.assign(N, vector<bool>(M, true));

        cabbages.resize(K);

        for (int i = 0; i < K; i++) {
            cin >> cabbages[i].r >> cabbages[i].c;

            ground[cabbages[i].r][cabbages[i].c] = 1;
            visited[cabbages[i].r][cabbages[i].c] = false;
        }

        int result = 0;

        for (coord cbg : cabbages) {
            
            if (!visited[cbg.r][cbg.c]) {
                result++;

                coords.push(cbg);
                visited[cbg.r][cbg.c] = true;

                while (!coords.empty()) {
                    int r = coords.front().r, c = coords.front().c;
                    coords.pop();

                    if (r > 0 && !visited[r-1][c]) {
                        coords.push({r - 1, c});
                        visited[r-1][c] = true;
                    }
                    if (r < N - 1 && !visited[r+1][c]) {
                        coords.push({r + 1, c});
                        visited[r+1][c] = true;
                    }
                    if (c > 0 && !visited[r][c-1]) {
                        coords.push({r, c - 1});
                        visited[r][c-1] = true;
                    }
                    if (c < M - 1 && !visited[r][c+1]) {
                        coords.push({r, c + 1});
                        visited[r][c+1] = true;
                    }
                }
            }
        }

        cout << result << '\n';
    }

    return 0;
}