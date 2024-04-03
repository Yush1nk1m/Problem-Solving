#include <iostream>
#include <queue>
using namespace std;

#define NOTVISITED -1

static int N, K;
static int count;
static int times[200001];
queue<int> points;

inline static bool isValidPoint(int point);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if (N == K) {
        cout << "0\n1";
        return 0;
    }

    fill(times, times + 200001, NOTVISITED);

    times[N] = 0;
    points.push(N);

    while (!points.empty() && times[K] == NOTVISITED) {
        int queueSize = points.size();

        for (int _ = 0; _ < queueSize; _++) {
            int curr = points.front();
            points.pop();

            if (isValidPoint(curr * 2)) {
                if (curr * 2 == K) {
                    times[curr * 2] = times[curr] + 1;
                    count++;
                } else if (times[curr * 2] == NOTVISITED || times[curr * 2] == times[curr] + 1) {
                    times[curr * 2] = times[curr] + 1;
                    points.push(curr * 2);
                }
            }
            if (isValidPoint(curr + 1)) {
                if (curr + 1 == K) {
                    times[curr + 1] = times[curr] + 1;
                    count++;
                } else if (times[curr + 1] == NOTVISITED || times[curr + 1] == times[curr] + 1) {
                    times[curr + 1] = times[curr] + 1;
                    points.push(curr + 1);
                }
            }
            if (isValidPoint(curr - 1)) {
                if (curr - 1 == K) {
                    times[curr - 1] = times[curr] + 1;
                    count++;
                } else if (times[curr - 1] == NOTVISITED || times[curr - 1] == times[curr] + 1) {
                    times[curr - 1] = times[curr] + 1;
                    points.push(curr - 1);
                }
            }
        }
    }

    cout << times[K] << '\n' << count;

    return 0;
}

inline static bool isValidPoint(int point) {
    return (0 <= point && point <= 200000);
}