#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> relationship;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> N >> M;

    relationship.resize(N + 1, vector<int>(N + 1, 999));

    for (int i = 1; i <= N; i++)
        relationship[i][i] = 0;

    for (int _ = 0; _ < M; _++) {
        int s, e;
        cin >> s >> e;

        relationship[s][e] = 1;
        relationship[e][s] = 1;
    }

    for (int m = 1; m <= N; m++) {
        for (int s = 1; s <= N; s++) {
            for (int e = 1; e <= N; e++) {
                if (relationship[s][e] > relationship[s][m] + relationship[m][e])
                    relationship[s][e] = relationship[s][m] + relationship[m][e];
            }
        }
    }

    int min_kevin = 2147483647;
    int result;
    for (int s = 1; s <= N; s++) {
        int partsum = 0;
        for (int e = 1; e <= N; e++)
            partsum += relationship[s][e];
        
        if (partsum < min_kevin) {
            min_kevin = partsum;
            result = s;
        }
    }

    cout << result;

    return 0;
}