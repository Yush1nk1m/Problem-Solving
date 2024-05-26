#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    vector<vector<bool>> table(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
        table[i][i] = true;
    
    for (int i = 0; i < N - 1; i++)
        if (numbers[i] == numbers[i + 1])
            table[i][i + 1] = true;
    
    for (int interval = 2; interval < N; interval++) {
        for (int start = 0; start + interval < N; start++) {
            int end = start + interval;
            if (table[start + 1][end - 1] && numbers[start] == numbers[end])
                table[start][end] = true;
        } 
    }
    
    cin >> M;
    for (int _ = 0; _ < M; _++) {
        int s, e;
        cin >> s >> e;
        cout << table[s-1][e-1] << '\n';
    }

    return 0;
}