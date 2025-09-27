/**
 * @file 17406_Implementation.cpp
 * @brief 00:41:22
 * @date 2024-07-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, M, K, minSum = INF;
vector<vector<int>> matrix;
vector<tuple<int, int, int>> rots;
vector<int> sequence;

inline void ExecuteSequence(vector<int>& sequence);
inline void RotateMatrix(tuple<int, int, int>& man);
inline int CalcSum();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    matrix.resize(N, vector<int>(M, INF));
    rots.resize(K);
    sequence.resize(K);

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> matrix[r][c];

    for (int i = 0; i < K; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        rots[i] = make_tuple(r - 1, c - 1, s);
        sequence[i] = i;
    }

    do {
        vector<vector<int>> temp = matrix;
        ExecuteSequence(sequence);
        minSum = min(minSum, CalcSum());
        matrix = temp;
    } while (next_permutation(sequence.begin(), sequence.end()));

    cout << minSum;

    return 0;
}

inline void ExecuteSequence(vector<int>& sequence) {
    for (int i : sequence)
        RotateMatrix(rots[i]);
}

inline void RotateMatrix(tuple<int, int, int>& man) {
    int cr = get<0>(man), cc = get<1>(man), s = get<2>(man);

    for (int d = 1; d <= s; d++) {
        vector<pair<int, int>> route;
        
        // upper line
        for (int c = cc - d; c < cc + d; c++)
            route.push_back({ cr - d, c });
        // right line
        for (int r = cr - d; r < cr + d; r++)
            route.push_back({ r, cc + d });
        // lower line
        for (int c = cc + d; c > cc - d; c--)
            route.push_back({ cr + d, c });
        // left line
        for (int r = cr + d; r > cr - d; r--)
            route.push_back({ r, cc - d });
        
        int temp = matrix[route[route.size()-1].first][route[route.size()-1].second];
        for (int i = route.size() - 1; i > 0; i--) {
            matrix[route[i].first][route[i].second] =
                matrix[route[i-1].first][route[i-1].second];
        }
        matrix[route[0].first][route[0].second] = temp;
    }
}

inline int CalcSum() {
    int sum = INF;
    for (int r = 0; r < N; r++) {
        sum = min(sum, accumulate(matrix[r].begin(), matrix[r].end(), 0));
    }
    return sum;
}