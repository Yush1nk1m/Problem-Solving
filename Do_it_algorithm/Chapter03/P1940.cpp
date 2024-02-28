#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> table(N);
    for (int i = 0; i < N; i++)
        cin >> table[i];
    sort(table.begin(), table.end());

    int from = 0, to = N - 1, result = 0;
    while (from < to) {
        int sum = table[from] + table[to];

        if (sum < M) {
            from++;
        } else if (sum > M) {
            to--;
        } else {
            result++;
            from++;
            to--;
        }
    }

    cout << result;

    return 0;
}