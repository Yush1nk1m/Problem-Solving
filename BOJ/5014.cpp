#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited;
queue<int> floors;
int max_floor, curr_floor, comp_floor, up, down, button;

inline bool clear_floors() {
    int number = floors.size();
    bool result = false;

    for (int _ = 0; _ < number; _++) {
        int curr = floors.front();

        if (curr == comp_floor) {
            result = true;
            break;
        }

        floors.pop();

        if (curr + up <= max_floor && !visited[curr + up]) {
            visited[curr + up] = true;
            floors.push(curr + up);
        }

        if (curr - down >= 1 && !visited[curr - down]) {
            visited[curr - down] = true;
            floors.push(curr - down);
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    cin >> max_floor >> curr_floor >> comp_floor >> up >> down;

    visited.resize(max_floor + 1, false);

    floors.push(curr_floor);
    visited[curr_floor] = true;

    while (!floors.empty()) {
        bool is_reach = clear_floors();
        if (is_reach) break;
        button++;
    }

    if (floors.empty()) cout << "use the stairs";
    else cout << button;

    return 0;
}