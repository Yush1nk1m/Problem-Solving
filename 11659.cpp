#include <iostream>
#include <vector>
using namespace std;

vector<int> sequence;
int N, M, i, j;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    sequence.resize(N + 1, 0);
    cin >> sequence[1];
    for (int i = 2; i <= N; i++) {
        cin >> sequence[i];
        sequence[i] += sequence[i - 1];
    }

    for (int _ = 0; _ < M; _++) {
        cin >> i >> j;
        cout << sequence[j] - sequence[i - 1] << '\n';
    }
    
    return 0;
}