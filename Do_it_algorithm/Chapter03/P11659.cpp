#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> sum(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    for (int _ = 0; _ < M; _++) {
        int from, to;
        cin >> from >> to;
        cout << (sum[to] - sum[from-1]) << '\n';
    }

    return 0;
}