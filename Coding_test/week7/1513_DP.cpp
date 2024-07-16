#include <bits/stdc++.h>
using namespace std;

#define MOD 1000007

int N, M, C;
int table[51][51][51][51];      // [row][col][max][cnt]
vector<vector<int>> city;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> C;
    city.resize(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= C; i++) {
        int r, c;
        cin >> r >> c;
        city[r][c] = i;
    }

    if (city[1][1])
        table[1][1][city[1][1]][1] = 1;
    else
        table[1][1][0][0] = 1;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (r == 1 && c == 1) continue;

            if (!city[r][c]) {
                for (int cnt = 0; cnt <= C; cnt++) {
                    for (int i = 0; i <= C; i++) {
                        table[r][c][i][cnt] += table[r][c-1][i][cnt];
                        table[r][c][i][cnt] %= MOD;
                        table[r][c][i][cnt] += table[r-1][c][i][cnt];
                        table[r][c][i][cnt] %= MOD;
                    }
                }
            }
            else {
                for (int cnt = 1; cnt <= C; cnt++) {
                    for (int i = 0; i < city[r][c]; i++) {
                        table[r][c][city[r][c]][cnt] += table[r][c-1][i][cnt-1];
                        table[r][c][city[r][c]][cnt] %= MOD;
                        table[r][c][city[r][c]][cnt] += table[r-1][c][i][cnt-1];
                        table[r][c][city[r][c]][cnt] %= MOD;
                    }
                }
            }
        }
    }

    for (int cnt = 0; cnt <= C; cnt++) {
        int sum = 0;
        for (int i = 0; i <= C; i++) {
            sum += table[N][M][i][cnt];
            sum %= MOD;
        }
        cout << sum << ' ';
    }

    return 0;
}