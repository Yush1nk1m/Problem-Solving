#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007;

ll D;
vector<vector<ll>> graph(8, vector<ll>(8, 0)), result;

vector<vector<ll>> matmul(ll pow);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    graph[0][1] = graph[0][2] = 1;
    graph[1][0] = graph[1][2] = graph[1][3] = 1;
    graph[2][0] = graph[2][1] = graph[2][3] = graph[2][4] = 1;
    graph[3][1] = graph[3][2] = graph[3][4] = graph[3][5] = 1;
    graph[4][2] = graph[4][3] = graph[4][5] = graph[4][6] = 1;
    graph[5][3] = graph[5][4] = graph[5][7] = 1;
    graph[6][4] = graph[6][7] = 1;
    graph[7][5] = graph[7][6] = 1;

    cin >> D;
    result = matmul(D);

    cout << result[0][0];

    return 0;
}

vector<vector<ll>> matmul(ll pow) {
    if (pow == 1)
        return graph;

    vector<vector<ll>> mat1, mat2, mat3(8, vector<ll>(8, 0));
    mat1 = matmul(pow / 2);
    mat2 = mat1;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 8; k++) {
                mat3[i][j] += (mat1[i][k] * mat2[k][j]);
                mat3[i][j] %= MOD;
            }
    
    if (pow % 2 != 0) {
        mat1 = mat3;
        mat2 = graph;
        mat3 = vector<vector<ll>>(8, vector<ll>(8, 0));

        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                for (int k = 0; k < 8; k++) {
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                    mat3[i][j] %= MOD;
                }
    }
    
    return mat3;
}