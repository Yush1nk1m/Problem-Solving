#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

static vector<int> priorPattern;
static vector<int> pattern;
static set<int> uniqueNumbers;
static vector<bool> visited;
static vector<int> sequence;

static void DFS(int depth, int maxDepth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    priorPattern.resize(M, 0);
    pattern.resize(M, 0);
    sequence.resize(N);

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        uniqueNumbers.insert(n);
    }

    for (int number : uniqueNumbers) {
        for (int _ = 0; _ < M; _++)
            sequence.push_back(number);
    }
    visited.resize(sequence.size(), false);
    
    sort(sequence.begin(), sequence.end());

    DFS(0, M);

    return 0;
}

static void DFS(int depth, int maxDepth) {
    if (depth == maxDepth) {
        if (pattern != priorPattern) {
            for (int number : pattern)
                cout << number << ' ';
            cout << '\n';
            priorPattern = pattern;
        }

        return;
    }

    int prior = 0;
    for (int i = 0; i < sequence.size(); i++) {
        if (!visited[i] && sequence[i] != prior && (depth == 0 || pattern[depth-1] <= sequence[i])) {
            prior = sequence[i];
            visited[i] = true;
            pattern[depth] = sequence[i];
            DFS(depth + 1, maxDepth);
            visited[i] = false;
        }
    }
}