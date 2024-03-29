#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> seconds(100001, -1);
    queue<int> locations;

    seconds[N] = 0;
    locations.push(N);
    
    while (!locations.empty()) {
        int curr = locations.front();
        locations.pop();

        for (int teleport = curr * 2; teleport <= 100000 && teleport != curr; teleport *= 2) {
            if (seconds[teleport] == -1) {
                seconds[teleport] = seconds[curr];
                locations.push(teleport);
            }
        }

        if (curr - 1 >= 0 && seconds[curr-1] == -1) {
            seconds[curr-1] = seconds[curr] + 1;
            locations.push(curr-1);
        }
        if (curr + 1 <= 100000 && seconds[curr+1] == -1) {
            seconds[curr+1] = seconds[curr] + 1;
            locations.push(curr+1);
        }

        if (seconds[K] != -1)
            break;
    }

    cout << seconds[K];
    
    return 0;
}