#include <iostream>
#include <vector>
using namespace std;

static vector<vector<char>> pattern;

static void FillPattern(int N, int r, int c);

static void PrintPattern() {
    for (int r = 0; r < pattern.size(); r++) {
        for (int c = 0; c < pattern[0].size(); c++)
            cout << pattern[r][c];
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    pattern.resize(N, vector<char>(N * 2 - 1, ' '));
    FillPattern(N, N - 1, 0);

    PrintPattern();

    return 0;
}

static void FillPattern(int N, int r, int c) {
    if (N == 3) {
        pattern[r-2][c+2] = '*';
        pattern[r-1][c+1] = pattern[r-1][c+3] = '*';
        for (int i = 0; i < 5; i++) pattern[r][c+i] = '*';
    }
    else {
        FillPattern(N / 2, r, c);
        FillPattern(N / 2, r, c + N);
        FillPattern(N / 2, r - N/2, c + N/2);
    }
}