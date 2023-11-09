#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input;
vector<bool> visited;
vector<int> sequence;

int N, M;

void dfs(int number) {
    sequence.push_back(number);

    if (sequence.size() == M) {
        for (auto iter = sequence.begin(); iter != sequence.end(); iter++) {
            cout << *iter << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(input[i]);
                visited[i] = false;
                sequence.pop_back();
            }
        }
    }
}

int main(int argc, char* argv[]) {
    cin >> N >> M;

    input.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < N; i++)
        cin >> input[i];
    
    sort(input.begin(), input.end());

    for (int i = 0; i < N; i++) {
        visited[i] = true;
        dfs(input[i]);
        visited[i] = false;
        sequence.pop_back();
    }

    return 0;
}