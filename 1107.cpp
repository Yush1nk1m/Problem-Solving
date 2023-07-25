#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    vector<bool> visited(1000000, false);
    vector<int> distance(1000000, -1);
    vector<bool> buttons(10, true);     // true: not broken, false: broken
    
    int N, M;
    cin >> N >> M;

    for (int _ = 0; _ < M; _++) {
        int temp;
        cin >> temp;
        buttons[temp] = false;
    }

    queue<int> channels;

    bool is_found = false;
    int level = 1;

    for (int i = 0; i <= 9; i++) {
        if (buttons[i]) {
            visited[i] = true;
            distance[i] = level;
            channels.push(i);
        }
    }

    while (!channels.empty()) {
        level++;

        int queue_size = channels.size();

        for (int _ = 0; _ < queue_size; _++) {
            int chnl = channels.front();
            channels.pop();

            for (int i = 0; i <= 9; i++) {
                if (buttons[i] && chnl * 10 + i < 1000000 && !visited[chnl * 10 + i]) {
                    visited[chnl * 10 + i] = true;
                    distance[chnl * 10 + i] = level;
                    channels.push(chnl * 10 + i);
                }
            }
        }
    }

    if (distance[N] != -1) {
        cout << min(distance[N], abs(N - 100));
    }
    else {
        int l = N, r = N, dist_left = 0, dist_right = 0;
        while (l >= 0 && distance[l] == -1) {
            l--;
            dist_left++;
        }

        if (l == -1) dist_left = 1000000;
        else dist_left += distance[l];

        while (r < 1000000 && distance[r] == -1) {
            r++;
            dist_right++;
        }

        if (r == 1000000) dist_right = 1000000;
        else dist_right += distance[r];

        cout << min(min(dist_left, dist_right), abs(N - 100));
    }

    return 0;
}