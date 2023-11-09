#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ground;

int N, M, B, max_height = -1, cost = 2147483647, height;

inline int depthSum() {
    int sum = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            sum += max_height - ground[r][c];
        }
    }
    return sum;
}

inline int costSum() {
    int sum = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (ground[r][c] > max_height) {
                sum += (ground[r][c] - max_height) * 2;
            }
            else if (ground[r][c] < max_height) {
                sum += (max_height - ground[r][c]);
            }
        }
    }
    return sum;
}

int main(int argc, char* argv[]) {
    cin >> N >> M >> B;

    ground.resize(N, vector<int>(M, 0));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> ground[r][c];
            if (ground[r][c] > max_height) max_height = ground[r][c];
        }
    }

    int depth_sum;
    max_height++;
    do {
        max_height--;
        depth_sum = depthSum();
    } while (depth_sum > B);

    while (1) {
        int temp = costSum();
        if (cost <= temp) break;
        else cost = temp;
        max_height--;
    }

    max_height++;

    cout << cost << ' ' << max_height;

    return 0;
}