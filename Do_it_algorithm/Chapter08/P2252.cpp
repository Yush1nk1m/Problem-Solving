#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> degrees(N + 1, 0);
    vector<vector<int>> graph(N + 1);
    for (int _ = 0; _ < M; _++) {
        int shorter, taller;
        cin >> shorter >> taller;

        graph[shorter].push_back(taller);
        degrees[taller]++;
    }

    queue<int> students;
    for (int student = 1; student <= N; student++)
        if (degrees[student] == 0) {
            students.push(student);
            cout << student << " ";
        }
    
    while (!students.empty()) {
        int curr = students.front();
        students.pop();

        for (int taller : graph[curr]) {
            degrees[taller]--;
            if (degrees[taller] == 0) {
                students.push(taller);
                cout << taller << " ";
            }
        }
    }

    return 0;
}