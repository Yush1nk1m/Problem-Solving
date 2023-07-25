#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, r, c;
long long visit_number;
bool calculated = false;

void Zsearch(int N, int row, int col) {
    if (calculated) return;

    if (N == 0) {
        if (row == r && col == c) {
            calculated = true;
            cout << visit_number;
            return;
        }
        visit_number++;
    }
    else {
        int next_slice = pow(2, N - 1);

        if (r < row + next_slice && c < col + next_slice) {
            Zsearch(N - 1, row, col);
            return;
        }
        visit_number += pow(2, N - 1) * pow(2, N - 1);
        if (r < row + next_slice && c >= col + next_slice) {
            Zsearch(N - 1, row, col + next_slice);
            return;
        }
        visit_number += pow(2, N - 1) * pow(2, N - 1);
        if (r >= row + next_slice && c < col + next_slice) {
            Zsearch(N - 1, row + next_slice, col);
            return;
        }
        visit_number += pow(2, N - 1) * pow(2, N - 1);
        if (r >= row + next_slice && c >= col + next_slice) {
            Zsearch(N - 1, row + next_slice, col + next_slice);
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> r >> c;

    Zsearch(N, 0, 0);

    return 0;
}