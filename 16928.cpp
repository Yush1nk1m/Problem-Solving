#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<int, int> portal;
bitset<100> visited;
queue<int> cells;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    for (int i = 1; i <= 100; i++) {
        portal[i] = i;
    }

    cin >> N >> M;

    for (int _ = 0; _ < N; _++) {
        int x, y;
        cin >> x >> y;

        portal[x] = y;
    }

    for (int _ = 0; _ < M; _++) {
        int x, y;
        cin >> x >> y;

        portal[x] = y;
    }

    cells.push(1);
    visited.set(1);

    int result = 0;
    bool finished = false;
    while (!finished) {
        result++;
        int size = cells.size();
        
        for (int _ = 0; _ < size; _++) {
            int cell = cells.front();
            cells.pop();

            for (int dice = 1; dice <= 6 && cell + dice <= 100; dice++) {
                int arrive_point = portal[cell + dice];

                if (arrive_point == 100) {
                    finished = true;
                    break;
                }

                if (!visited.test(arrive_point)) {
                    visited.set(arrive_point);
                    cells.push(arrive_point);
                }
            }
        }
    }

    cout << result;

    return 0;
}