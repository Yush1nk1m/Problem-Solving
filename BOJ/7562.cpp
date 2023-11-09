#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, l;
pair<int, int> current, target;
queue<pair<int, int>> cases;
vector<vector<bool>> visited;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    for (int _ = 0; _ < T; _++) {
        cin >> l;
        visited.resize(l, vector<bool>(l));
        visited.assign(l, vector<bool>(l, false));

        cin >> current.first >> current.second;
        cin >> target.first >> target.second;

        cases.push(current);
        visited[current.first][current.second] = true;

        int depth = -1;
        bool reached = false;
        while (!reached) {
            depth++;
            int size = cases.size();

            for (int __ = 0; __ < size; __++) {
                int r = cases.front().first, c = cases.front().second;
                cases.pop();

                if (r == target.first && c == target.second) {
                    reached = true;
                    break;
                }

                if (r - 1 >= 0 && c - 2 >= 0 && !visited[r-1][c-2]) {
                    cases.push({r-1, c-2});
                    visited[r-1][c-2] = true;
                }
                if (r - 2 >= 0 && c - 1 >= 0 && !visited[r-2][c-1]) {
                    cases.push({r-2, c-1});
                    visited[r-2][c-1] = true;

                }
                if (r + 1 <= l - 1 && c - 2 >= 0 && !visited[r+1][c-2]) {
                    cases.push({r+1, c-2});
                    visited[r+1][c-2] = true;
                }
                if (r + 2 <= l - 1 && c - 1 >= 0 && !visited[r+2][c-1]) {
                    cases.push({r+2, c-1});
                    visited[r+2][c-1] = true;
                }
                if (r - 2 >= 0 && c + 1 <= l - 1 && !visited[r-2][c+1]) {
                    cases.push({r-2, c+1});
                    visited[r-2][c+1] = true;
                }
                if (r - 1 >= 0 && c + 2 <= l - 1 && !visited[r-1][c+2]) {
                    cases.push({r-1, c+2});
                    visited[r-1][c+2] = true;
                }
                if (r + 2 <= l - 1 && c + 1 <= l - 1 && !visited[r+2][c+1]) {
                    cases.push({r+2, c+1});
                    visited[r+2][c+1] = true;
                }
                if (r + 1 <= l - 1 && c + 2 <= l - 1 && !visited[r+1][c+2]) {
                    cases.push({r+1, c+2});
                    visited[r+1][c+2] = true;
                }
            }
        }

        while (!cases.empty()) cases.pop();

        cout << depth << '\n';
    }

    return 0;
}