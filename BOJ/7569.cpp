#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<vector<vector<int>>> warehouse;
queue<tuple<int, int, int>> ripen;

int M, N, H, day;

inline void update(tuple<int, int, int> tomato) {
    int h = get<0>(tomato);
    int r = get<1>(tomato);
    int c = get<2>(tomato);

    if (h > 0 && warehouse[h - 1][r][c] == 0) {
        ripen.push(make_tuple(h - 1, r, c));
        warehouse[h - 1][r][c] = 1;
    }
    if (h < H - 1 && warehouse[h + 1][r][c] == 0) {
        ripen.push(make_tuple(h + 1, r, c));
        warehouse[h + 1][r][c] = 1;
    }
    if (r > 0 && warehouse[h][r - 1][c] == 0) {
        ripen.push(make_tuple(h, r - 1, c));
        warehouse[h][r - 1][c] = 1;
    }
    if (r < N - 1 && warehouse[h][r + 1][c] == 0) {
        ripen.push(make_tuple(h, r + 1, c));
        warehouse[h][r + 1][c] = 1;
    }
    if (c > 0 && warehouse[h][r][c - 1] == 0) {
        ripen.push(make_tuple(h, r, c - 1));
        warehouse[h][r][c - 1] = 1;
    }
    if (c < M - 1 && warehouse[h][r][c + 1] == 0) {
        ripen.push(make_tuple(h, r, c + 1));
        warehouse[h][r][c + 1] = 1;
    }
}

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> M >> N >> H;

    warehouse.resize(H, vector<vector<int>>(N, vector<int>(M)));

    for (int h = 0; h < H; h++) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                cin >> warehouse[h][r][c];
                // 이미 익어 있는 것들을 큐에 저장한다.
                if (warehouse[h][r][c] == 1) ripen.push(make_tuple(h, r, c));
            }
        }
    }

    while (!ripen.empty()) {
        day++;
        int todays = ripen.size();

        for (int _ = 0; _ < todays; _++) {
            update(ripen.front());
            ripen.pop();
        }
    }

    bool is_all_ripen = true;
    for (int h = 0; h < H; h++) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (warehouse[h][r][c] == 0) {
                    is_all_ripen = false;
                    break;
                }
            }
            if (!is_all_ripen) break;
        }
        if (!is_all_ripen) break;
    }

    if (is_all_ripen) cout << day - 1;
    else cout << -1;

    return 0;
}