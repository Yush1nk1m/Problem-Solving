#include <iostream>
#include <vector>
using namespace std;

void InitializeTable(vector<vector<long>>& table, int maxNum);
inline long Combination(vector<vector<long>>& table, int M, int N);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<long>> table;
    InitializeTable(table, 30);

    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++) {
        int N, M;
        cin >> N >> M;
        cout << Combination(table, M, N) << '\n';
    }

    return 0;
}

void InitializeTable(vector<vector<long>>& table, int maxNum) {
    table.resize(maxNum + 1);
    for (int i = 0; i <= maxNum; i++)
        table[i].resize(i + 1);
    
    for (int n = 0; n <= maxNum; n++) {
        table[n][0] = 1;
        table[n][n] = 1;
    }

    for (int n = 2; n <= maxNum; n++)
        for (int r = 1; r < n; r++)
            table[n][r] = table[n-1][r] + table[n-1][r-1];
}

inline long Combination(vector<vector<long>>& table, int M, int N) {
    return table[M][N];
}