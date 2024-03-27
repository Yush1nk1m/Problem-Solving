#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

static vector<int> pattern;

static void DFS(vector<int>& sequence, vector<bool>& visited, int depth, int maxDepth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    pattern.resize(M, 0);

    vector<bool> visited(N, false);
    vector<int> sequence(N);
    for (int i = 0; i < N; i++)
        cin >> sequence[i];
    
    sort(sequence.begin(), sequence.end());

    DFS(sequence, visited, 0, M);

    return 0;
}

static void DFS(vector<int>& sequence, vector<bool>& visited, int depth, int maxDepth) {
    if (depth == maxDepth) {
        for (int number : pattern)
            cout << number << ' ';
        cout << '\n';

        return;
    }

    int prior = 0;
    for (int i = 0; i < sequence.size(); i++) {
        if (!visited[i] && prior != sequence[i]) {
            pattern[depth] = sequence[i];
            visited[i] = true;
            DFS(sequence, visited, depth + 1, maxDepth);
            visited[i] = false;
            prior = sequence[i];
        }
    }
}