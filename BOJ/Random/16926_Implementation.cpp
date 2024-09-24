/**
 * @file 16926_Implementation.cpp
 * @brief 00:18:55
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, R;
vector<vector<int>> matrix;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;
    matrix.resize(N, vector<int>(M));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> matrix[r][c];
    
    for (int level = 0; level < min(N, M) / 2; level++) {
        vector<int> sequence;

        int r = level, c = level;
        
        // down
        while (r < N - level - 1) {
            sequence.push_back(matrix[r][c]);
            r++;
        }
        
        // right
        while (c < M - level - 1) {
            sequence.push_back(matrix[r][c]);
            c++;
        }

        // up
        while (r > level) {
            sequence.push_back(matrix[r][c]);
            r--;
        }

        // down
        while (c > level) {
            sequence.push_back(matrix[r][c]);
            c--;
        }

        rotate(sequence.rbegin(), sequence.rbegin() + (R % sequence.size()), sequence.rend());
        int i = 0;

        // down
        while (r < N - level - 1) {
            matrix[r][c] = sequence[i++];
            r++;
        }
        
        // right
        while (c < M - level - 1) {
            matrix[r][c] = sequence[i++];
            c++;
        }

        // up
        while (r > level) {
            matrix[r][c] = sequence[i++];
            r--;
        }

        // down
        while (c > level) {
            matrix[r][c] = sequence[i++];
            c--;
        }        
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++)
            cout << matrix[r][c] << ' ';
        cout << '\n';
    }

    return 0;
}
