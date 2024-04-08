#include <iostream>
#include <vector>
using namespace std;

#define INCREASING 0
#define DECREASING 1

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> sequence(N);
    vector<vector<int>> length(2, vector<int>(N, 1));

    for (int i = 0; i < N; i++)
        cin >> sequence[i];

    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (sequence[j] < sequence[i])
                length[INCREASING][i] = max(length[INCREASING][i], length[INCREASING][j] + 1);
            else if (sequence[j] > sequence[i])
                length[DECREASING][i] = max(length[DECREASING][i], max(length[DECREASING][j] + 1, length[INCREASING][j] + 1));
        }
    }

    int maxLength = 1;
    for (int i = 0; i < N; i++)
        maxLength = max(maxLength, max(length[INCREASING][i], length[DECREASING][i]));

    cout << maxLength;

    return 0;
}