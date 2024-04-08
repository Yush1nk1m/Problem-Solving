#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000ULL

static unsigned long long int N, B;
vector<vector<unsigned long long int>> matrix;

static vector<vector<unsigned long long int>> MatrixMultiplication(vector<vector<unsigned long long int>>& mat1, vector<vector<unsigned long long int>>& mat2);
static vector<vector<unsigned long long int>> MatrixSquare(unsigned long long int power);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;
    
    matrix.resize(N, vector<unsigned long long int>(N));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            cin >> matrix[r][c];
            matrix[r][c] %= MOD;
        }

    vector<vector<unsigned long long int>> result = MatrixSquare(B);
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << result[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

static vector<vector<unsigned long long int>> MatrixMultiplication(vector<vector<unsigned long long int>>& mat1, vector<vector<unsigned long long int>>& mat2) {
    vector<vector<unsigned long long int>> resultMatrix;
    resultMatrix.resize(mat1.size(), vector<unsigned long long int>(mat2[0].size(), 0));

    for (int i = 0; i < resultMatrix.size(); i++) {
        for (int j = 0; j < resultMatrix[0].size(); j++) {
            for (int k = 0; k < mat1[0].size(); k++) {
                resultMatrix[i][j] += ((mat1[i][k] % MOD) * (mat2[k][j] % MOD));
                resultMatrix[i][j] %= MOD;
            }
        }
    }

    return resultMatrix;
}

static vector<vector<unsigned long long int>> MatrixSquare(unsigned long long int power) {
    if (power == 1) {
        return matrix;
    }

    vector<vector<unsigned long long int>> squaredMatrix;
    if (power % 2 == 0) {
        squaredMatrix = MatrixSquare(power / 2);
        squaredMatrix = MatrixMultiplication(squaredMatrix, squaredMatrix);
    } else {
        squaredMatrix = MatrixSquare(power / 2);
        squaredMatrix = MatrixMultiplication(squaredMatrix, squaredMatrix);
        squaredMatrix = MatrixMultiplication(squaredMatrix, matrix);
    }

    return squaredMatrix;
}