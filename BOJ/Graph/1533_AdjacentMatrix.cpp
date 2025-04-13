#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000003

int N, S, E, T;
vector<vector<ll>> graph, res;

vector<vector<ll>> matmul(vector<vector<ll>> mat1, vector<vector<ll>> mat2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S >> E >> T;
    S--, E--;
    graph = vector<vector<ll>>(51, vector<ll>(51, 0));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            char n;
            cin >> n;
            int number = n - '0';
            if (number)
                graph[r*5+number-1][c*5] = 1;
        }
        for (int e = 0; e < 4; e++)
            graph[r*5+e][r*5+e+1] = 1;
    }

    if (T) {
        res = graph;
        T--;
    }
    while (T) {
        if (T % 2)
            res = matmul(res, graph);
        graph = matmul(graph, graph);
        T /= 2;
    }

    cout << res[S*5][E*5];

    return 0;
}

vector<vector<ll>> matmul(vector<vector<ll>> mat1, vector<vector<ll>> mat2) {
    vector<vector<ll>> res(mat1.size(), vector<ll>(mat1[0].size(), 0));
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            for (int k = 0; k < 50; k++) {
                res[i][j] += (mat1[i][k] * mat2[k][j]) % MOD;
                res[i][j] %= MOD;
            }
    return res;
}

