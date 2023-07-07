#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> people;
vector<vector<bool>> parents;
vector<vector<bool>> visited;

int n, m, src, dest, depth;

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    parents.resize(n + 1, vector<bool>(n + 1, false));
    visited.resize(n + 1, vector<bool>(n + 1, true));

    cin >> src >> dest;

    cin >> m;
    for (int _ = 0; _ < m; _++) {
        int parent, child;
        cin >> parent >> child;
        parents[parent][child] = true;
        visited[parent][child] = false;
    }

    people.push(src);
    while (!people.empty()) {
        int curr = people.top();
        if (curr == dest) break;

        int next;

        for (next = 1; next <= n; next++) {
            if (!visited[curr][next]) {
                visited[curr][next] = true;
                people.push(next);
                break;
            }
            else if (!visited[next][curr]) {
                visited[next][curr] = true;
                people.push(next);
                break;
            }
        }

        if (next > n) {    // if there was no connection
            depth--;
            people.pop();
        }
        else depth++;
    }

    if (people.empty()) cout << -1;
    else cout << depth;

    return 0;
}