#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, level;
vector<int> op_numbers;
vector<int> parents;
vector<bool> visited;
queue<int> nodes;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    op_numbers.resize(N + 1, 0);
    parents.resize(N + 1, 0);
    visited.resize(N + 1, false);

    visited[1] = true;
    nodes.push(1);

    while (!nodes.empty()) {
        level++;
        int number = nodes.size();

        for (int _ = 0; _ < number; _++) {
            int node = nodes.front();
            nodes.pop();

            if (node + 1 <= N && !visited[node + 1]) {
                parents[node + 1] = node;
                visited[node + 1] = true;
                op_numbers[node + 1] = level;
                nodes.push(node + 1);
            }

            if (node * 2 <= N && !visited[node * 2]) {
                parents[node * 2] = node;
                visited[node * 2] = true;
                op_numbers[node * 2] = level;
                nodes.push(node * 2);
            }

            if (node * 3 <= N && !visited[node * 3]) {
                parents[node * 3] = node;
                visited[node * 3] = true;
                op_numbers[node * 3] = level;
                nodes.push(node * 3);
            }
        }
    }

    cout << op_numbers[N] << '\n';
    
    int temp = N;
    while (temp != 0) {
        cout << temp << ' ';
        temp = parents[temp];
    }
}